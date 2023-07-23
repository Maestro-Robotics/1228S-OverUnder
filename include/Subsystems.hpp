#pragma once

#include "pros/misc.hpp"

#include "Drivetrain.hpp"
#include "Catapult.hpp"

class Subsystems {
    private:
        pros::Controller Bot_Controller{ pros::E_CONTROLLER_MASTER};
        Drivetrain Bot_Drivetrain;
        Catapult Bot_Catapult;

        void update_Drivetrain();
        void update_Catapult();

    public:
        Subsystems(Drivetrain drivetrain, Catapult catapult);
        void update();
};