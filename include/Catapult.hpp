#pragma once

#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "pros/distance.hpp"

class Catapult {

private:
    pros::Motor CataMotor;
    pros::Rotation CataRotationSensor;
    pros::Distance CataDistanceSensor;

public:

    Catapult(int8_t const CataPort, uint8_t const RotationPort, uint8_t const DistancePort);

    // Updated function signature with targetAngle and angleRange arguments
    void SpinToTarget(int targetAngle, int angleRange);
    void CataSpinToPosition(int positiontype);
    void MatchLoadSkills(int range, double buffer);
};
