#include "pros/misc.h"
#include <iostream>
#include "Subsystems.hpp"

// Define a boolean variable to keep track of the button state for the R2 button
bool r2Pressed = false;

// Define a boolean variable to keep track of the state of initial launch for the Pistons
bool initialLaunchState = false;

// Constructor for the Subsystems class, initializing the subsystem objects
Subsystems::Subsystems(Catapult catapult, Intake intake, Pistons pistons) 
    : Bot_Catapult(catapult)
	, Bot_Intake(intake)
	, Bot_Pistons(pistons) {}

// Update function for the Catapult subsystem
void Subsystems::update_Catapult() {

    // Check if the R1 button is pressed and activate the catapult
    if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
		CataActive = true;
		
		// Toggle the intake off to avoid any interference with the catapult operation
        Bot_Intake.toggle(false, true);
        
        // Move the catapult to the firing position
        Bot_Catapult.CataSpinToPosition(0, 140);
		
		CataActive = false;
		
		// Toggle the intake back on after the catapult operation is completed
		Bot_Intake.toggle(false, false);
    }

	// Check if the DOWN button is pressed and perform the MatchLoadSkills routine
	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
		Bot_Catapult.MatchLoadSkills(22, 50);
	}
}

// Update function for the Intake subsystem
void Subsystems::update_Intake() {

    // Check if the L1 button is pressed and toggle the intake on (in the forward direction)
	if ((Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1)) && CataActive == false) {
		Bot_Intake.toggle(false, false);
	} 
    // Check if the L2 button is pressed and toggle the intake on (in the reverse direction)
    else if ((Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2)) && CataActive == false) {
		Bot_Intake.toggle(true, false);
	}
}

// Update function for the Pistons subsystem
void Subsystems::update_Pistons() {

    // Check if the UP button is pressed and lift the tracking wheel using the Pistons
	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)) {
		Bot_Pistons.LiftWheel();
		Bot_Pistons.InitialLaunch(true);
	}

    // Toggle Initial Launch when Button X is pressed
    if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
        // Toggle the state of the initial launch
        initialLaunchState = !initialLaunchState;
        
        // Trigger the InitialLaunch function with the updated state
        Bot_Pistons.InitialLaunch(initialLaunchState);
    }

	// Check the state of the R2 button inside your main loop or update function
	if (Bot_Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
	    // If the R2 button is pressed, set the angle change to true and update the button state
	    if (!r2Pressed) {
	        Bot_Pistons.ChangeAngle(true);
	        r2Pressed = true;
	    }
	}
    // If the R2 button is released, set the angle change to false and update the button state
	else {
	    if (r2Pressed) {
	        Bot_Pistons.ChangeAngle(false);
	        r2Pressed = false;
	    }
	}
}

// Update function that calls the individual update functions for each subsystem
void Subsystems::update() {
	update_Catapult();
	update_Intake();
	update_Pistons();
}
