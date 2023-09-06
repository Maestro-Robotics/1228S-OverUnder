#pragma once

#include "EZ-Template/drive/drive.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "pros/distance.hpp"


class Catapult {

private:
    pros::Motor CataMotor;
    pros::Rotation CataRotationSensor;

public:

    Catapult(int8_t const CataPort, uint8_t const RotationPort);

    // Updated function signature with targetAngle and angleRange arguments
    void SpinToTarget(int targetAngle, int angleRange, int velocity);
    void CataSpinToPosition(int positiontype, int velocity);
};
