#pragma once

#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "pros/distance.hpp"

class Catapult {

private:
    pros::Motor fullMotor;
    pros::Motor halfMotor;

public:

    Catapult(int8_t const fullMotorPort, int8_t const halfMotorPort);

    // Updated function signature with targetAngle and angleRange arguments
    void cataMatchLoad(int velocity);
};
