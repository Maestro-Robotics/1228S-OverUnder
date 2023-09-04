#include "pros/misc.h"
#include <iostream>
#include "Subsystems.hpp"
#include "autons.hpp"
#include "main.h"

// Define a boolean variable to keep track of the button state for the R2 button
bool r2Pressed = false;

// Define a boolean variable to keep track of the state of initial launch for the Pistons
bool initialLaunchState = false;

int ToggleGoalSide = 0;

bool GoalSide = true;

bool SkillsMode = false;

int InitialIntake = 0;

// Define constants for drive and turn speeds
const int DRIVE_SPEED = 127; // This is 110/127 (around 87% of max speed). We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower. When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;
// Constructor for the Subsystems class, initializing the subsystem objects
Subsystems::Subsystems(Catapult Bot_Catapult, Intake Bot_Intake, Pistons Bot_Pistons) 
    : Bot_Catapult(Bot_Catapult)
	, Bot_Intake(Bot_Intake)
	, Bot_Pistons(Bot_Pistons) {}

// Update function for the Catapult subsystem
void Subsystems::update_Catapult() {

    // Check if the R1 button is pressed and activate the Bot_Catapult
    if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
		CataActive = true;
		
		// Toggle the Bot_Intake off to avoid any interference with the Bot_Catapult operation
        Bot_Intake.toggle(false, true);
        
        // Move the Bot_Catapult to the firing position
        Bot_Catapult.CataSpinToPosition(0, -200);
		
		CataActive = false;
		
		// Toggle the Bot_Intake back on after the Bot_Catapult operation is completed
		Bot_Intake.toggle(false, false);
    }

	// // Check if the DOWN button is pressed and perform the MatchLoadSkills routine
	// if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)) {
	//  	Bot_Catapult.MatchLoadSkills(44, 40);
	

	//  }


	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)){
		Bot_Intake.toggle(false, true);
		Bot_Catapult.CataSpinToPosition(2, 200);
	}

	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)){
		autonomous();
	}
}

// Update function for the Intake subsystem
void Subsystems::update_Intake() {

	 // Check if the L1 button is pressed and toggle the Bot_Intake on (in the forward direction)
    if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1) && CataActive == false) {
		if (GoalSide == true && InitialIntake == 1){
			Bot_Pistons.InitialLaunch(true);
			Bot_Intake.toggle(false, false);
			Bot_Intake.toggle(false, false);
		}

		else if (GoalSide == true){
			Bot_Pistons.InitialLaunch(true);
			Bot_Intake.toggle(false, false);
			InitialIntake = 1;
		}

		else{
         // Toggle the Bot_Intake state
        Bot_Intake.toggle(false, false); // Toggle the Bot_Intake with the current reverse setting
		}
    } 
    // Check if the L2 button is pressed and toggle the Bot_Intake on (in the reverse direction)
    else if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2) && CataActive == false) {
		if (GoalSide == true && InitialIntake == 1){
			Bot_Intake.toggle(true, false);
			Bot_Intake.toggle(true, false);
			Bot_Pistons.InitialLaunch(false);
		}

		else if (GoalSide == true){
			Bot_Pistons.InitialLaunch(true);
			Bot_Intake.toggle(true, false);
			InitialIntake = 1;
		}

		else{	
        Bot_Intake.toggle(true, false); // Toggle the Bot_Intake with the current reverse setting
		}
    }

	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
		ToggleGoalSide++;

		if (ToggleGoalSide == 2){
			GoalSide = !GoalSide;
			Bot_Pistons.ChangeAngle(GoalSide);
			Bot_Intake.toggle(false, true);
			ToggleGoalSide = 0;
			InitialIntake = 0;
		}
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
