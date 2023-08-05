#pragma once

#include "EZ-Template/drive/drive.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include "pros/distance.hpp"

extern Drive chassis;

class Catapult {

private:
    pros::Motor CataMotor;
    pros::Rotation CataRotationSensor;
    pros::Distance CataDistanceSensor;

public:

    Catapult(int8_t const CataPort, uint8_t const RotationPort, uint8_t const DistancePort);

    // Updated function signature with targetAngle and angleRange arguments
    void SpinToTarget(int targetAngle, int angleRange, int velocity);
    void CataSpinToPosition(int positiontype, int velocity);
    void MatchLoadSkills(int range, double buffer);
    void SpinToTargetSkills(int targetAngle, int angleRange, int velocity);
};
