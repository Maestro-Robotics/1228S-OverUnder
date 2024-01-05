#pragma once

#include "pros/adi.hpp"

class Pistons{
    private:
        pros::ADIDigitalOut actuateElevation;
        pros::ADIDigitalOut actuateWings;

    public:
        Pistons(uint8_t const elevationPort, uint8_t const wingsPort);

        void launchWings(bool tf);
        void launchElevation();


};