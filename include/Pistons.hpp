#pragma once

#include "pros/adi.hpp"

class Pistons{
    private:
        pros::ADIDigitalOut elevationLaunch;

    public:
        Pistons(uint8_t const elevationLaunch);

        void InitialLaunch(bool boolean);
        void launchWings(bool tf);
        void launchElevation();


};