#include "pros/misc.h"
#include <iostream>
#include "Subsystems.hpp"
#include "autons.hpp"
#include "main.h"


// Define a boolean variable to keep track of the state of initial launch for the Pistons
bool initialLaunchState = false;

bool firing = false;

bool wingsState = false;

int ToggleGoalSide = 0;

bool GoalSide = true;

bool SkillsMode = false;

int InitialIntake = 0;

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

		Bot_Pistons.InitialLaunch(true);
        
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
		Bot_Pistons.InitialLaunch(true);
		Bot_Catapult.cataMatchLoad(-200);
		}

		firing = !firing;
	}


	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_RIGHT)){
		Bot_Intake.toggle(false, true);
		Bot_Pistons.InitialLaunch(true);
		Bot_Catapult.cataSpinToPosition(1, -200);
	}

	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)){
		if (ez::as::auton_selector.current_auton_page == 4){
       ez::as::auton_selector.call_selected_auton(); 
      }
	}
}

// Update function for the Intake subsystem
void Subsystems::update_Intake() {

	 // Check if the L1 button is pressed and toggle the Bot_Intake on (in the forward direction)
    if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L1) && CataActive == false) {
			Bot_Pistons.InitialLaunch(true);
			Bot_Intake.toggle(false, false);
		

    } 
    // Check if the L2 button is pressed and toggle the Bot_Intake on (in the reverse direction)
    else if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_L2) && CataActive == false) {
		Bot_Pistons.InitialLaunch(false);
        Bot_Intake.toggle(true, false); // Toggle the Bot_Intake with the current reverse setting
		}
    

	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
		ToggleGoalSide++;

		if (ToggleGoalSide == 2){
			GoalSide = !GoalSide;
			Bot_Intake.toggle(false, true);
			ToggleGoalSide = 0;
			InitialIntake = 0;
		}
	}
}

// Update function for the Pistons subsystem
void Subsystems::update_Pistons() {

    // Toggle Initial Launch when Button X is pressed
    if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
        // Toggle the state of the initial launch
        initialLaunchState = !initialLaunchState;
        
        // Trigger the InitialLaunch function with the updated state
        Bot_Pistons.InitialLaunch(initialLaunchState);
    }

	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_Y)) {
		wingsState = !wingsState;

		initialLaunchState = false;
		Bot_Pistons.InitialLaunch(initialLaunchState);

		Bot_Pistons.launchWings(wingsState);
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
