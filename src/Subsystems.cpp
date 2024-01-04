#include "pros/misc.h"
#include "main.h"

// Define variables
bool l1pressed = false;

bool l2pressed = false;

bool firing = false;

bool wingsState = false;

bool prevWingsState = wingsState;

bool blockerState = false;

bool GoalSide = true;

bool matchLoadAuto = false;

bool intakeState = true;

// Constructor for the Subsystems class, initializing the subsystem objects
Subsystems::Subsystems(Catapult Bot_Catapult, Intake Bot_Intake, Pistons Bot_Pistons) 
    : Bot_Catapult(Bot_Catapult)
	, Bot_Intake(Bot_Intake)
	, Bot_Pistons(Bot_Pistons) {}

// Update function for the Drivetrain subsystem
void Subsystems::update_Drivetrain() {
	lemchassis.curvature(Bot_Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), Bot_Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), 1.6);
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
		Bot_Catapult.cataSpinToPosition(2, -200);
	}
}

// Update function for the Intake Subsystem
void Subsystems::update_Intake() {
    // Check if the L1 button is pressed and toggle the Bot_Intake
    if (Bot_Controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) {
        if (!l1pressed) {
            Bot_Intake.toggle(true, false); // Turn on intake in the forward direction
            l1pressed = true;
            intakeState = true;
        }
    } else {
        l1pressed = false;
        if (intakeState) {
            Bot_Intake.toggle(false, false); // Keep intake running forward
        }
    }

    // Check if the L2 button is pressed
    if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_LEFT)) {
        if (intakeState) {
            Bot_Intake.toggle(false, true); // Turn on intake in the reverse direction
            intakeState = false;
        } else {
            Bot_Intake.toggle(false, false); // Stop the intake
            intakeState = true;
        }
    }
}


// Update function for the Pistons subsystem
void Subsystems::update_Pistons() {

	wingsState = Bot_Controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);

	if (wingsState != prevWingsState) {
    	Bot_Pistons.launchWings(wingsState);
    	prevWingsState = wingsState;
}

	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
		Bot_Pistons.launchElevation();
	}

}

// Update function that calls the individual update functions for each subsystem (called in OP Control)
void Subsystems::update() {
	update_Drivetrain();
	update_Catapult();
	update_Intake();
	update_Pistons();
}
