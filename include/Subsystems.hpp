#pragma once

#include "pros/misc.hpp"

#include "Catapult.hpp"
#include "Intake.hpp"
#include "Pistons.hpp"
#include "Drivetrain.hpp"

class Subsystems {
    private:
        pros::Controller Bot_Controller{ pros::E_CONTROLLER_MASTER};
        Catapult Bot_Catapult;
        Intake Bot_Intake;
        Pistons Bot_Pistons;
        Drivetrain Bot_Drivetrain;

        bool CataActive = false;
        bool intakeToggle = false;

        void update_Catapult();
        void update_Intake();
        void update_Pistons();
        void update_Drivetrain();

    public:
        Subsystems(Catapult catapult, Intake intake, Pistons pistons, Drivetrain drivetrain);
        void update();
};