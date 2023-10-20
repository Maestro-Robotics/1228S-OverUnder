#pragma once

#include "pros/adi.hpp"

class Pistons{
    private:
        pros::ADIDigitalOut actuateBlocker;

    public:
        Pistons(uint8_t const actuateBlocker);

        void launchBlocker(bool tf);
        void launchWings(bool tf);
        void launchElevation();


};