#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include "Catapult.hpp"
#include "pros/rtos.hpp"

Catapult::Catapult(int8_t const CataPort, uint8_t const RotationPort, uint8_t const DistancePort) : CataMotor{ CataPort }, CataRotationSensor{ RotationPort }, CataDistanceSensor{ DistancePort } {}

// Constants for PID control
const double kP = 5; // Proportional gain
const double kI = 0.8; // Integral gain
const double kD = 2.00; // Derivative gain

void Catapult::SpinToTarget(int targetAngle, int angleRange, int velocity) {
    const int timeout = 3000; // set timeout to 3 seconds
    uint32_t start_time = pros::millis();

    // Variables for PID control
    double error, lastError = 0, integral = 0, derivative;

    CataMotor.move_velocity(velocity);
    pros::Task::delay(300);

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

        if (pros::millis() - start_time > timeout) {
            std::printf("Spin motor timeout reached");
            break;
        }

        // Save the current error for the next iteration
        lastError = error;

        pros::delay(1);
    }

    CataMotor.move_velocity(0);
}

void Catapult::CataSpinToPosition(int positiontype, int velocity) {
    if (positiontype == 0) {
        SpinToTarget(35250, 300, velocity);
    } else if (positiontype == 1) {
        SpinToTarget(34000, 160, velocity);
    } else {
        SpinToTarget(260, 5, velocity);
    }
}

void Catapult::MatchLoadSkills(int range, double buffer) {
    int now = 0;

    while (range < now) {
        if (CataDistanceSensor.get() < buffer) {
            pros::delay(100);
            CataSpinToPosition(0, 200);
            now += 1;
        }
        pros::delay(1);
    }
}
