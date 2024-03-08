#include "Subsystems.hpp"
#include "pros/misc.h"
#include "main.h"
#include "pros/motors.h"

// Define variables
bool l1pressed = false;

bool l2pressed = false;

bool firing = false;

bool PTOOn =false;

bool frontWingsState = false;

bool prevFrontWingsState = frontWingsState;

bool BackwingsState = false;

bool prevBackWingsState = BackwingsState;

bool GoalSide = true;

bool intakeState = true;

// Constructor for the Subsystems class, initializing the subsystem objects
Subsystems::Subsystems(Catapult Bot_Catapult, Intake Bot_Intake, Pistons Bot_Pistons, PTO Bot_PTO) 
    : Bot_Catapult(Bot_Catapult)
	, Bot_Intake(Bot_Intake)
	, Bot_Pistons(Bot_Pistons)
	, Bot_PTO(Bot_PTO) {}

// Update function for the Drivetrain subsystem
void Subsystems::update_Drivetrain() {
	lemchassis.curvature(Bot_Controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y), Bot_Controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X), 3.9);
}


// Update function for the Catapult subsystem
void Subsystems::update_Catapult() {

	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)){
		if(firing == true){
			Bot_Catapult.cataMatchLoad(0);
		}
		else if (PTOOn == true) {
			Bot_Pistons.engageRatchet(true);
			Bot_PTO.changeBrakeMode(pros::E_MOTOR_BRAKE_COAST);
			Bot_Catapult.cataMatchLoad(200);
		}
		else{
		Bot_Intake.toggle(false, true);
		intakeToggle = false;
		Bot_Catapult.cataMatchLoad(150);
		}

		firing = !firing;
	}
	// if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
	// 	if(firing == true){
	// 		Bot_Catapult.cataMatchLoad(0);
	// 	}
	// 	else{
	// 	Bot_Intake.toggle(false, true);
	// 	intakeToggle = false;
	// 	Bot_Catapult.cataMatchLoad(200);
	// 	}

	// 	firing = !firing;
	// }

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

	frontWingsState = Bot_Controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);

	if (frontWingsState != prevFrontWingsState) {
    	Bot_Pistons.launchFrontwings(frontWingsState, frontWingsState);
    	prevFrontWingsState = frontWingsState;
	}

	
	BackwingsState = Bot_Controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);

	if (BackwingsState != prevBackWingsState) {
    	Bot_Pistons.launchBackWings(BackwingsState, BackwingsState);
    	prevBackWingsState = BackwingsState;
	}


}

void Subsystems::update_PTO() {
	if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_UP)){
		Bot_PTO.engagePTO(true);
		PTOOn = true;
		// PTOOn = true;
		// if(firing == true){
		// 	Bot_Catapult.cataMatchLoad(0);
		// }
		// else{
		// Bot_Intake.toggle(false, true);
		// intakeToggle = false;
		// Bot_Catapult.cataMatchLoad(200);
		// }

		// firing = !firing;
		// Bot_PTO.liftToAngle(-200, 80);
	}

	// if (Bot_Controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_DOWN)){
	// 	Bot_PTO.liftToAngle(-200, 0, 5);
	// }


}

// Update function that calls the individual update functions for each subsystem (called in OP Control)
void Subsystems::update() {
	update_Drivetrain();
	update_Catapult();
	update_Intake();
	update_Pistons();
	update_PTO();
}
