#pragma once

#include "pros/motors.hpp"
#include "pros/rotation.hpp"

class Catapult {

private:
    pros::Motor CataMotor;
    pros::Rotation CataRotationSensor;

public:
    Catapult(int8_t const CataPort, uint8_t const RotationPort);

    // Updated function signature with targetAngle and angleRange arguments
    void SpinToTarget(int targetAngle, int angleRange);
    void CataSpinToPosition(int positiontype);
};