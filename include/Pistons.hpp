#pragma once

#include "pros/adi.hpp"

class Pistons{
    private:
        pros::ADIDigitalOut CatapultAngleChange;
        pros::ADIDigitalOut LiftTrackingWheel;
        pros::ADIDigitalOut ExpandIntake;

    public:
        Pistons(uint8_t const CatapultAngleChange, uint8_t const LiftTrackingWheel, uint8_t const ExpandIntake);

        void InitialLaunch();
        void LiftWheel();
        void ChangeAngle();

};