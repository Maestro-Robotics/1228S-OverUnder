#pragma once

#include "pros/adi.hpp"

class Pistons{
    private:
        pros::ADIDigitalOut actuateElevation;
        pros::ADIDigitalOut actuateWings;

    public:
        Pistons(uint8_t const actuateBlocker, uint8_t const actuateWings);

        void launchBlocker(bool tf);
        void launchWings(bool tf);
        void launchElevation();


};