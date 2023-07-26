#pragma once

#include "pros/adi.hpp"

class Pistons{
    private:
        pros::ADIDigitalOut CatapultAngleChange;
        pros::ADIDigitalOut LiftTrackingWheel;
        pros::ADIDigitalOut ExpandIntake1;
        pros::ADIDigitalOut ExpandIntake2;

    public:
        Pistons(uint8_t const CatapultAngleChange, uint8_t const LiftTrackingWheel, uint8_t const ExpandIntake1, uint8_t const ExpandIntake2);

        void InitialLaunch();
        void LiftWheel();
        void ChangeAngle();

};