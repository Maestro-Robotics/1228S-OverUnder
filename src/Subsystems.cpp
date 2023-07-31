#include "pros/misc.h"
#include <iostream>
#include "Subsystems.hpp"

Subsystems::Subsystems(Catapult catapult, Intake intake, Pistons pistons) 
    : Bot_Catapult(catapult)
	, Bot_Intake(intake)
	, Bot_Pistons(pistons) {}

// void Subsystems::update_Drivetrain() {
// 	Bot_Drivetrain.update(Bot_Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), Bot_Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));
// 	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
// 		Bot_Drivetrain.next_reference_frame();

// }
// }

void Subsystems::update_Catapult() {

    if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
		CataActive = true;
		Bot_Intake.toggle(false, true);
        Bot_Catapult.CataSpinToPosition(0, 180);
		CataActive = false;
		Bot_Intake.toggle(false, false);
    }

	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
		Bot_Catapult.MatchLoadSkills(22, 30);
	}
}

void Subsystems::update_Intake(){

	if((Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) && CataActive == false) {
		Bot_Intake.toggle(false, false);
	} else if((Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) && CataActive == false) {
		Bot_Intake.toggle(true, false);
	}
}

void Subsystems::update_Pistons() {
	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
		Bot_Pistons.LiftWheel();
		Bot_Pistons.InitialLaunch(true);
	}

	if (Bot_Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
		Bot_Pistons.ChangeAngle(true);
	}
}

void Subsystems::update() {
    // update_Drivetrain();
	update_Catapult();
	update_Intake();
	update_Pistons();
}