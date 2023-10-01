#pragma once

#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "pros/distance.hpp"

#include "EZ-Template/api.hpp"

// extern Drive chassis;

class Catapult {

private:
    pros::Motor CataMotor;
    pros::Rotation CataRotationSensor;

public:

    Catapult(int8_t const CataPort, uint8_t const RotationPort);

    // Updated function signature with targetAngle and angleRange arguments
    void spinToTarget(int targetAngle, int angleRange, int velocity);
    void cataSpinToPosition(int positiontype, int velocity);
    void cataMatchLoad(int velocity);
};
