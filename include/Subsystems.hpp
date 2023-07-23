#pragma once

#include "pros/misc.hpp"

#include "Drivetrain.hpp"
#include "Catapult.hpp"
#include "Intake.hpp"

class Subsystems {
    private:
        pros::Controller Bot_Controller{ pros::E_CONTROLLER_MASTER};
        Drivetrain Bot_Drivetrain;
        Catapult Bot_Catapult;
        Intake Bot_Intake;

        bool CataActive = false;

        void update_Drivetrain();
        void update_Catapult();
        void update_Intake();

    public:
        Subsystems(Drivetrain drivetrain, Catapult catapult, Intake intake);
        void update();
};