#include "pros/misc.h"
#include <iostream>
#include "Subsystems.hpp"
#include "autons.hpp"
#include "main.h"


// Define a boolean variable to keep track of the state of initial launch for the Pistons

int i = 0;

bool firing = false;

bool wingsState = false;

bool blockerState = true;

bool GoalSide = true;

bool intakeState = false;

// Constructor for the Subsystems class, initializing the subsystem objects
Subsystems::Subsystems(Catapult Bot_Catapult, Intake Bot_Intake, Pistons Bot_Pistons) 
    : Bot_Catapult(Bot_Catapult)
	, Bot_Intake(Bot_Intake)
	, Bot_Pistons(Bot_Pistons) {}

void Subsystems::update_Drivetrain() {
	lemchassis.curvature(Bot_Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), Bot_Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), 2.5);
}


// Update function for the Catapult subsystem
void Subsystems::update_Catapult() {

    // Check if the R1 button is pressed and activate the Bot_Catapult
    if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
		CataActive = true;
		
		// Toggle the Bot_Intake off to avoid any interference with the Bot_Catapult operation
        Bot_Intake.toggle(false, true);
		intakeToggle = false;
        
        // Move the Bot_Catapult to the firing position
        Bot_Catapult.cataSpinToPosition(0, -200);
		
		CataActive = false;
		
    }

	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)){
		if(firing == true){
			Bot_Catapult.cataMatchLoad(0);
		}
		else{
		Bot_Intake.toggle(false, true);
		intakeToggle = false;
		Bot_Catapult.cataMatchLoad(-200);
		}

		firing = !firing;
	}


	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)){
		Bot_Intake.toggle(false, true);
		Bot_Catapult.cataSpinToPosition(1, -200);
	}
}

// Update function for the Intake subsystem
void Subsystems::update_Intake() {

	 // Check if the L1 button is pressed and toggle the Bot_Intake on (in the forward direction)
    if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1) && CataActive == false) {
		Bot_Intake.toggle(intakeState, false);
		intakeState = !intakeState;
		

    } 
    // Check if the L2 button is pressed and toggle the Bot_Intake on (in the reverse direction)
    else if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2) && CataActive == false) {
        Bot_Intake.toggle(false, true); // Toggle the Bot_Intake with the current reverse setting
		intakeState = false;
		}
    

}

// Update function for the Pistons subsystem
void Subsystems::update_Pistons() {


	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
		wingsState = !wingsState;

		Bot_Pistons.launchWings(wingsState);
	}

	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
		blockerState = !blockerState;

		Bot_Pistons.launchBlocker(blockerState);
	}

	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
		Bot_Pistons.launchElevation();
	}

}

// Update function that calls the individual update functions for each subsystem
void Subsystems::update() {
	update_Drivetrain();
	update_Catapult();
	update_Intake();
	update_Pistons();
}
