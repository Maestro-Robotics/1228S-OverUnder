#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include "Subsystems.hpp"
#include "pros/rtos.hpp"

// Constructor for Catapult class
Catapult::Catapult(int8_t const CataPort, uint8_t const RotationPort) : CataMotor{ CataPort }, CataRotationSensor{ RotationPort } {}

// Constants for PID control
const double kP = 5;    // Proportional gain
const double kI = 0.8;  // Integral gain
const double kD = 2.00; // Derivative gain

bool running = false;

// Function to control the catapult and spin it to the target angle
void Catapult::spinToTarget(int targetAngle, int angleRange, int velocity) {
    pros::Task cataSpin{[=] {
    
    const int timeout = 3000; // set timeout to 3 seconds
    uint32_t start_time = pros::millis();
    double error, lastError = 0, integral = 0, derivative;

    // Loop until the rotation sensor reaches the desired range of the target angle
    while (std::abs(CataRotationSensor.get_angle() - targetAngle) > angleRange) {

        error = targetAngle - CataRotationSensor.get_angle();

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
            break;
        }

        // Save the current error for the next iteration
        lastError = error;

        pros::delay(1);
    }

    // Stop the catapult motor
    CataMotor.move_velocity(0);
    }};
}

// Function to spin the catapult to a pre-defined position based on positiontype
void Catapult::cataSpinToPosition(int positiontype, int velocity) {
    if (positiontype == 0) {
    spinToTarget(35900, 300, -velocity);

    } else if (positiontype == 1) {
        spinToTarget(34000, 300, -velocity);

    } else if (positiontype == 2) {
        CataMotor.move_velocity(-velocity);
        pros::Task::delay(400);
        CataMotor.move_velocity(0);
    }
}

// Function to spin the catapult until stopped (Skills/Match loading)
void Catapult::cataMatchLoad(int velocity){
    if (running == true){
        CataMotor.move_velocity(0);
    }
    else{
        CataMotor.move_velocity(-velocity);
    }
}


