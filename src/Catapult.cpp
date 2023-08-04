#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include "Catapult.hpp"
#include "pros/rtos.hpp"

// Constructor for Catapult class
Catapult::Catapult(int8_t const CataPort, uint8_t const RotationPort, uint8_t const DistancePort) : CataMotor{ CataPort }, CataRotationSensor{ RotationPort }, CataDistanceSensor{ DistancePort } {}

// Constants for PID control
const double kP = 5;    // Proportional gain
const double kI = 0.8;  // Integral gain
const double kD = 2.00; // Derivative gain

// Function to control the catapult and spin it to the target angle
void Catapult::SpinToTarget(int targetAngle, int angleRange, int velocity) {
    
    chassis.arcade_standard(ez::SPLIT);
    const int timeout = 3000; // set timeout to 3 seconds
    uint32_t start_time = pros::millis();

    // Variables for PID control
    double error, lastError = 0, integral = 0, derivative;

    // Start spinning the catapult motor at the desired velocity
    CataMotor.move_velocity(velocity);
    pros::Task::delay(300);

    // Loop until the rotation sensor reaches the desired range of the target angle
    while (std::abs(CataRotationSensor.get_angle() - targetAngle) > angleRange) {
        error = targetAngle - CataRotationSensor.get_angle();
        chassis.arcade_standard(ez::SPLIT);

        // Calculate PID terms
        integral += error;
        derivative = error - lastError;

        // Calculate the motor output velocity using PID formula
        double output = kP * error + kI * integral + kD * derivative;

        // Limit the motor output to prevent excessive changes
        output = std::min(std::max(output, static_cast<double>(-velocity)), static_cast<double>(velocity));

        // Update motor velocity
        CataMotor.move_velocity(static_cast<int>(output));

        // Check for timeout
        if (pros::millis() - start_time > timeout) {
            std::printf("Spin motor timeout reached");
            break;
        }

        // Save the current error for the next iteration
        lastError = error;

        pros::delay(1);
    }

    // Stop the catapult motor
    CataMotor.move_velocity(0);
}

// Function to spin the catapult to a pre-defined position based on positiontype
void Catapult::CataSpinToPosition(int positiontype, int velocity) {
    if (positiontype == 0) {
        // Spin to the target angle with a larger angle range
        SpinToTarget(35200, 350, velocity);
    } else if (positiontype == 1) {
        // Spin to the target angle with a smaller angle range
        SpinToTarget(34000, 160, velocity);
    } else {
        // Spin to a specific target angle with a very small angle range
        SpinToTarget(260, 5, velocity);
    }
}

// Function to spin the catapult and load skills in a match
void Catapult::MatchLoadSkills(int range, double buffer) {
    int now = 0;
    unsigned long startTime = pros::millis(); // Get the start time in milliseconds

    // Loop until the desired range is reached
    while (range > now) {

        if (CataDistanceSensor.get() < buffer) {
            pros::delay(25);
            CataSpinToPosition(0, 160);
            now += 1;
        }

        // Check if the match time has exceeded 24 seconds and exit the loop if true
        if (pros::millis() - startTime >= 24000) {
            break;
        }

        pros::delay(1);
    }
}
