#pragma once

#include "pros/adi.hpp"

class Pistons{
    private:
        pros::ADIDigitalOut actuateBLeftWings;
        pros::ADIDigitalOut actuateBRightWings;
        pros::ADIDigitalOut actuateFLeftWings;
        pros::ADIDigitalOut actuateFRightWings;
        pros::ADIDigitalOut actuateRatchet;

    public:
        Pistons(uint8_t const bWingR, uint8_t const bWingL, uint8_t const fWingR, uint8_t const fWingL, uint8_t const hangRatchet);

        void launchBackWings(bool left, bool right);
        void launchFrontwings(bool left, bool right);
        void closeBackWings();
        void closeBackWings(bool left, bool right);
        void closeFrontWings();
        void closeFrontWings(bool left, bool right);
        void engageRatchet(bool trueFalse);


};