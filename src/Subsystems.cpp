#include "Catapult.hpp"
#include "pros/misc.h"
#include <iostream>
#include "Subsystems.hpp"

Subsystems::Subsystems(Drivetrain drivetrain, Catapult catapult) 
    : Bot_Drivetrain(drivetrain)
	, Bot_Catapult(catapult) {}

void Subsystems::update_Drivetrain() {
	Bot_Drivetrain.update(Bot_Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), Bot_Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X));
	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
		Bot_Drivetrain.next_reference_frame();
	} else if (Bot_Controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
		Bot_Drivetrain.update(80, 0);
	}
}

void Subsystems::update_Catapult(){

    if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){
        Bot_Catapult.CataSpinToPosition(0);
    }
}

void Subsystems::update() {
    update_Drivetrain();
	update_Catapult();
}