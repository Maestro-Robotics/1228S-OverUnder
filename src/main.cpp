#include "main.h"
#include "Intake.hpp"
#include "pros/rtos.hpp"
#include "pros/apix.h" // Include the LVGL library

const int DRIVE_SPEED = 127; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;

lv_obj_t *label; // Declare a global pointer for the label widget

// Chassis constructor
Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {8, -9, -10}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{18, 19, -20}

  // IMU Port
  ,7

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
  //    (or tracking wheel diameter)
  ,4

  // Cartridge RPM
  //   (or tick per rotation if using tracking wheels)
  ,600

  // External Gear Ratio (MUST BE DECIMAL)
  //    (or gear ratio of tracking wheel)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
  ,0.571

  // Uncomment if using tracking wheels
  
  // Left Tracking Wheel Ports (negative port will reverse it!)
  ,{-1, -2} // 3 wire encoder
  // ,8 // Rotation sensor

  // Right Tracking Wheel Ports (negative port will reverse it!)
  ,{-3, -4} // 3 wire encoder
   // Rotation sensor


  // Uncomment if tracking wheels are plugged into a 3 wire expander
  // 3 Wire Port Expander Smart Port
  ,17
);

void GoalSideAuton1(Catapult catapult, Intake intake, Pistons pistons) {
    
  chassis.set_drive_pid(42, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);

  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-3, DRIVE_SPEED, false);
  chassis.wait_drive();

  pistons.InitialLaunch(false);
  intake.toggle(false, true);

  chassis.set_drive_pid(10, 127, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-25, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-60, TURN_SPEED);
  pistons.InitialLaunch(true);
  chassis.wait_drive();

  chassis.set_drive_pid(60, DRIVE_SPEED, true);
  intake.toggle(false, false);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  intake.toggle(true, true);
  chassis.wait_drive();

  chassis.set_drive_pid(5, DRIVE_SPEED, false);
  intake.toggle(true, false);
  pistons.InitialLaunch(false);
  chassis.wait_drive();

  chassis.set_drive_pid(18, DRIVE_SPEED, true);
  intake.toggle(false, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-15, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-125, TURN_SPEED);
  pistons.InitialLaunch(true);
  intake.toggle(false, false);
  chassis.wait_drive();

  chassis.set_drive_pid(30, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-25, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  pistons.InitialLaunch(false);
  intake.toggle(false, true);
  chassis.wait_drive();

  chassis.set_drive_pid(3, DRIVE_SPEED, false);
  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  pistons.InitialLaunch(false);
  chassis.set_drive_pid(20, DRIVE_SPEED, false);
  chassis.wait_drive();
}
void GoalSideAuton2(Catapult catapult, Intake intake, Pistons pistons){
  chassis.set_drive_pid(42, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);

  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-3, DRIVE_SPEED, false);
  chassis.wait_drive();

  pistons.InitialLaunch(false);
  intake.toggle(false, true);

  chassis.set_drive_pid(8, 127, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-25, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(255, TURN_SPEED);
  pistons.InitialLaunch(true);
  chassis.wait_drive();

  chassis.set_drive_pid(55, DRIVE_SPEED, true);
  intake.toggle(false, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-5, DRIVE_SPEED, false);
  pistons.InitialLaunch(false);
  chassis.wait_drive();

  chassis.set_turn_pid(20, TURN_SPEED);
  intake.toggle(true, true);
  chassis.wait_drive();

  chassis.set_drive_pid(26, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  chassis.set_drive_pid(20, DRIVE_SPEED, false);
  intake.toggle(false, true);
  pistons.InitialLaunch(false);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, TURN_SPEED);
  pistons.InitialLaunch(true);
  intake.toggle(false, false);
  chassis.wait_drive();

  chassis.set_drive_pid(15, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();



}
void FarSideAuton(Catapult catapult, Intake intake, Pistons pistons) {

  chassis.set_drive_pid(40, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-40, DRIVE_SPEED, true);
  chassis.wait_drive();

  intake.toggle(true, true);

  chassis.set_turn_pid(225, TURN_SPEED);
  chassis.wait_drive(); 

  chassis.set_drive_pid(42, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(270, TURN_SPEED);

  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-3, DRIVE_SPEED, false);
  chassis.wait_drive();

  pistons.InitialLaunch(false);
  intake.toggle(false, true);

  chassis.set_drive_pid(10, 127, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(359, TURN_SPEED);
  chassis.wait_drive();
 
  chassis.set_drive_pid(28, DRIVE_SPEED, true);
  chassis.wait_drive();  

  chassis.set_turn_pid(290, TURN_SPEED);
  pistons.InitialLaunch(true);
  intake.toggle(false, false);
  chassis.wait_drive();

  chassis.set_drive_pid(50, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.wait_drive();

  catapult.CataSpinToPosition(0, 150);
  chassis.wait_drive();
  
  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
  
  chassis.set_drive_pid(20, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(135, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(70, 127, true);
}
void Skills(Catapult catapult, Intake intake, Pistons pistons){
    pistons.LiftWheel();

  chassis.set_drive_pid(-10, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_drive_pid(45, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive(); 

  chassis.set_drive_pid(42, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, TURN_SPEED);

  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-3, DRIVE_SPEED, false);
  chassis.wait_drive();

  pistons.InitialLaunch(false);
  intake.toggle(false, true);

  chassis.set_drive_pid(10, 127, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-270, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(8, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-340, TURN_SPEED);
  chassis.wait_drive();

  pistons.InitialLaunch(true);
  catapult.MatchLoadSkills(22, 40);
  catapult.CataSpinToPosition(0, 140);

  chassis.set_turn_pid(-343, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-50, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(5, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-15, DRIVE_SPEED, false);
  chassis.wait_drive();

  intake.toggle(false, false);
  chassis.set_turn_pid(-70, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(38, DRIVE_SPEED, true);
  chassis.wait_drive();

  pros::delay(400);

  chassis.set_turn_pid(-360, TURN_SPEED);
  chassis.wait_drive();

  catapult.CataSpinToPosition(0, 140);
  chassis.wait_drive();

  chassis.set_drive_pid(-20, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(10, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(20, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-15, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_drive_pid(15, DRIVE_SPEED, true, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(60, DRIVE_SPEED, true);
  chassis.wait_until(60);

  chassis.set_turn_pid(-30, TURN_SPEED);
  chassis.wait_drive();

  catapult.MatchLoadSkills(22, 40);
  chassis.wait_drive();

  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-5, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-315, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-20, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-20, DRIVE_SPEED, true);
  chassis.wait_drive();


}
void SkillsMatchOnly(Catapult catapult, Intake intake, Pistons pistons) {
  pistons.LiftWheel();

  chassis.set_drive_pid(-10, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_drive_pid(45, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive(); 

  chassis.set_drive_pid(42, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, TURN_SPEED);

  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-3, DRIVE_SPEED, false);
  chassis.wait_drive();

  pistons.InitialLaunch(false);
  intake.toggle(false, true);

  chassis.set_drive_pid(10, 127, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-270, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(8, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-340, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(3, DRIVE_SPEED, false);
  chassis.wait_drive();

  pistons.InitialLaunch(true);
  catapult.MatchLoadSkills(22, 40);
  catapult.CataSpinToPosition(0, 140);

  chassis.set_turn_pid(-343, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-50, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(80, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
    chassis.wait_drive();

    chassis.set_drive_pid(60, DRIVE_SPEED, true);
    chassis.wait_drive();

    chassis.set_turn_pid(-30, TURN_SPEED);
    chassis.wait_drive();

    catapult.MatchLoadSkills(22, 40);
   
}

void displayAutonomousSelection(int selection) {
    // Update the controller LCD
    pros::lcd::set_text(1, "Selected Autonomous:");
    switch (selection) {
        case 1:
            pros::lcd::set_text(2, "Routine 1");
            break;
        case 2:
            pros::lcd::set_text(2, "Routine 2");
            break;
        case 3:
            pros::lcd::set_text(2, "Routine 3");
            break;
        case 4:
            pros::lcd::set_text(2, "Routine 4");
            break;
        default:
            pros::lcd::set_text(2, "Invalid Selection");
            break;
    }

    // Create a new LVGL screen
    lv_obj_t *screen = lv_obj_create(NULL, NULL);
    lv_scr_load(screen);

    // Create a label widget to display the selected autonomous
    label = lv_label_create(screen, NULL);
    lv_label_set_text(label, "Selected Autonomous:");
    lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);

    // Update the label text based on the selected autonomous
    switch (selection) {
        case 1:
            lv_label_set_text(label, "Selected Autonomous: Routine 1");
            break;
        case 2:
            lv_label_set_text(label, "Selected Autonomous: Routine 2");
            break;
        case 3:
            lv_label_set_text(label, "Selected Autonomous: Routine 3");
            break;
        case 4:
            lv_label_set_text(label, "Selected Autonomous: SKILLS");
            break;
        default:
            lv_label_set_text(label, "Selected Autonomous: Invalid Selection");
            break;
    }
}

void runSelectedAutonomous(int selection) {
    // Display the selected autonomous
    displayAutonomousSelection(selection);

    
    Catapult catapult(2, 5, 16);
    Intake intake(1);
    Pistons pistons('A', 'B', 'C', 'D');

    // Run the chosen autonomous routine
    switch (selection) {
        case 1:
            GoalSideAuton1(catapult, intake, pistons);
            break;
        case 2:
            GoalSideAuton2(catapult, intake, pistons);
            break;
        case 3:
            FarSideAuton(catapult, intake, pistons);
            break;
        case 4:
            Skills(catapult, intake, pistons);
            break;
        default:
            // If an invalid selection is made, do nothing or display an error message.
            break;
    }
}


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {  
  
  // Print our branding over your terminal :D
  ez::print_ez_template();
  
  pros::delay(500); // Stop the user from doing anything while legacy ports configure.

  // Configure your chassis controls
  chassis.toggle_modify_curve_with_controller(true); // Enables modifying the controller curve with buttons on the joysticks
  chassis.set_active_brake(0.1); // Sets the active brake kP. We recommend 0.1.
  chassis.set_curve_default(0, 0); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.set_left_curve_buttons (pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT); // If using tank, only the left side is used. 
  // chassis.set_right_curve_buttons(pros::E_CONTROLLER_DIGITAL_Y,    pros::E_CONTROLLER_DIGITAL_A);

  lv_init();

  chassis.set_exit_condition(chassis.turn_exit,  50, 3,  500, 7,   250, 250);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3,  500, 7,   500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 50,  50, 300, 150, 250, 250);

  // Initialize chassis and auton selector
  chassis.initialize();
}
/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {

    pros::ADIAnalogIn selector ('E');

    chassis.reset_pid_targets(); // Resets PID targets to 0
    chassis.reset_gyro(); // Reset gyro position to 0
    chassis.reset_drive_sensor(); // Reset drive sensors to 0
    chassis.set_drive_brake(MOTOR_BRAKE_HOLD); // Set motors to hold.  This helps autonomous consistency.


    Catapult catapult(2, 5, 16);
    Intake intake(1);
    Pistons pistons('A', 'B', 'C', 'D');

    int potValue = selector.get_value();
    
    // Determine the autonomous routine based on potValue
    int selectedAutonomous = 1;

    if (0 < potValue < 1024) {
        selectedAutonomous = 1;
    } else if (1024 < potValue < 2048) {
        selectedAutonomous = 2;
    } else if (2048 < potValue < 3072) {
        selectedAutonomous = 3;
    } else {
        selectedAutonomous = 4;
    }

//    runSelectedAutonomous(4);
SkillsMatchOnly(catapult, intake, pistons);

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */


void opcontrol() {
    
    Catapult const catapult(2, 5, 16);
    Intake const intake(1);
    Pistons const pistons('A', 'B', 'C', 'D');
	  Subsystems subsystems(catapult, intake, pistons);

    while (true) {
      chassis.arcade_standard(ez::SPLIT);
      subsystems.update();
      pros::delay(1);
    }
	}


