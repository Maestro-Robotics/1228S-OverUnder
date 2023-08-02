// Include necessary header files
#include "main.h"
#include "Catapult.hpp"
#include "Intake.hpp"
#include "pros/rtos.hpp"
#include "pros/apix.h" // Include the LVGL library

// Define constants for drive and turn speeds
const int DRIVE_SPEED = 127; // This is 110/127 (around 87% of max speed). We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower. When this is 87%, it's correcting by making one side
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

// Function to execute the Goal Side Autonomous 1 routine
void GoalSideAuton1(Catapult catapult, Intake intake, Pistons pistons) {
  // Move forward to a specific target position
  chassis.set_drive_pid(42, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-45, TURN_SPEED);

  // Launch the catapult and toggle the intake
  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-3, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Retract the catapult and toggle the intake
  pistons.InitialLaunch(false);
  intake.toggle(false, true);

  // Move forward to a specific target position
  chassis.set_drive_pid(10, 127, false);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-25, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle and launch the catapult
  chassis.set_turn_pid(-60, TURN_SPEED);
  pistons.InitialLaunch(true);
  chassis.wait_drive();

  // Move forward to a specific target position and toggle the intake
  chassis.set_drive_pid(60, DRIVE_SPEED, true);
  intake.toggle(false, false);
  chassis.wait_drive();

  // Turn to a specific angle and toggle the intake
  chassis.set_turn_pid(45, TURN_SPEED);
  intake.toggle(true, true);
  chassis.wait_drive();

  // Move forward to a specific target position and toggle the intake
  chassis.set_drive_pid(5, DRIVE_SPEED, false);
  intake.toggle(true, false);
  pistons.InitialLaunch(false);
  chassis.wait_drive();

  // Move forward to a specific target position and toggle the intake
  chassis.set_drive_pid(18, DRIVE_SPEED, true);
  intake.toggle(false, true);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-15, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle and launch the catapult
  chassis.set_turn_pid(-125, TURN_SPEED);
  pistons.InitialLaunch(true);
  intake.toggle(false, false);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(30, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-25, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle and retract the catapult
  chassis.set_turn_pid(45, TURN_SPEED);
  pistons.InitialLaunch(false);
  intake.toggle(false, true);
  chassis.wait_drive();

  // Move forward to a specific target position and launch the catapult
  chassis.set_drive_pid(3, DRIVE_SPEED, false);
  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  // Retract the catapult and move forward to a specific target position
  pistons.InitialLaunch(false);
  chassis.set_drive_pid(20, DRIVE_SPEED, false);
  chassis.wait_drive();
}

// Function to execute the Goal Side Autonomous 2 routine
void GoalSideAuton2(Catapult catapult, Intake intake, Pistons pistons) {
  // Move forward to a specific target position
  chassis.set_drive_pid(42, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-45, TURN_SPEED);

  // Launch the catapult and toggle the intake
  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-3, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Retract the catapult and toggle the intake
  pistons.InitialLaunch(false);
  intake.toggle(false, true);

  // Move forward to a specific target position
  chassis.set_drive_pid(8, 127, false);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-25, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle and launch the catapult
  chassis.set_turn_pid(255, TURN_SPEED);
  pistons.InitialLaunch(true);
  chassis.wait_drive();

  // Move forward to a specific target position and toggle the intake
  chassis.set_drive_pid(55, DRIVE_SPEED, true);
  intake.toggle(false, false);
  chassis.wait_drive();

  // Turn to a specific angle and toggle the intake
  chassis.set_turn_pid(180, TURN_SPEED);
  intake.toggle(true, true);
  chassis.wait_drive();

  // Move forward to a specific target position and toggle the intake
  chassis.set_drive_pid(26, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle and launch the catapult
  chassis.set_turn_pid(45, TURN_SPEED);
  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  // Move forward to a specific target position and toggle the intake
  chassis.set_drive_pid(20, DRIVE_SPEED, false);
  intake.toggle(false, true);
  pistons.InitialLaunch(false);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-12, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle and launch the catapult
  chassis.set_turn_pid(-90, TURN_SPEED);
  pistons.InitialLaunch(true);
  intake.toggle(false, false);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(15, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();
}

// Function to execute the Far Side Autonomous routine
void FarSideAuton(Catapult catapult, Intake intake, Pistons pistons) {
  // Move forward to a specific target position
  chassis.set_drive_pid(40, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-40, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Toggle the intake
  intake.toggle(true, true);

  // Turn to a specific angle
  chassis.set_turn_pid(225, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(42, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(270, TURN_SPEED);

  // Launch the catapult and toggle the intake
  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-3, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Retract the catapult and toggle the intake
  pistons.InitialLaunch(false);
  intake.toggle(false, true);

  // Move forward to a specific target position
  chassis.set_drive_pid(10, 127, false);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(359, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(28, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle and launch the catapult
  chassis.set_turn_pid(290, TURN_SPEED);
  pistons.InitialLaunch(true);
  intake.toggle(false, false);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(50, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.wait_drive();

  // Spin the catapult to a specific position
  catapult.CataSpinToPosition(0, 150);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(20, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(135, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(70, 127, true);
}

// Function to execute the Skills routine
void Skills(Catapult catapult, Intake intake, Pistons pistons) {
  // Lift the wheel using the pistons
  pistons.LiftWheel();

  // Move backward to a specific target position
  chassis.set_drive_pid(-10, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(45, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(42, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-90, TURN_SPEED);

  // Launch the catapult and toggle the intake
  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-3, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Retract the catapult and toggle the intake
  pistons.InitialLaunch(false);
  intake.toggle(false, true);

  // Move forward to a specific target position
  chassis.set_drive_pid(10, 127, false);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-270, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(8, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-340, TURN_SPEED);
  chassis.wait_drive();

  // Launch the catapult and load the ball
  pistons.InitialLaunch(true);
  catapult.MatchLoadSkills(22, 40);
  catapult.CataSpinToPosition(0, 140);

  // Turn to a specific angle
  chassis.set_turn_pid(-343, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-50, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(5, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-15, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Toggle the intake
  intake.toggle(false, false);

  // Turn to a specific angle
  chassis.set_turn_pid(-70, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(38, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Delay to wait for the piston to settle
  pros::delay(400);

  // Turn to a specific angle
  chassis.set_turn_pid(-360, TURN_SPEED);
  chassis.wait_drive();

  // Spin the catapult to a specific position
  catapult.CataSpinToPosition(0, 140);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-20, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(10, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(20, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-15, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Move forward to a specific target position and toggle the intake
  chassis.set_drive_pid(15, DRIVE_SPEED, true, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(60, DRIVE_SPEED, true);
  chassis.wait_until(60);

  // Turn to a specific angle
  chassis.set_turn_pid(-30, TURN_SPEED);
  chassis.wait_drive();

  // Launch the catapult and load the ball
  catapult.MatchLoadSkills(22, 40);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-5, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-315, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-20, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-20, DRIVE_SPEED, true);
  chassis.wait_drive();
}

// Function to execute the SkillsMatchOnly routine
void SkillsMatchOnly(Catapult catapult, Intake intake, Pistons pistons) {
  // Lift the wheel using the pistons
  pistons.LiftWheel();

  // Move backward to a specific target position
  chassis.set_drive_pid(-10, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(45, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(42, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-90, TURN_SPEED);

  // Launch the catapult and toggle the intake
  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-3, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Retract the catapult and toggle the intake
  pistons.InitialLaunch(false);
  intake.toggle(false, true);

  // Move forward to a specific target position
  chassis.set_drive_pid(10, 127, false);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-270, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(8, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-340, TURN_SPEED);
  chassis.wait_drive();

  // Launch the catapult and load the ball
  pistons.InitialLaunch(true);
  catapult.MatchLoadSkills(22, 40);
  catapult.CataSpinToPosition(0, 140);

  // Turn to a specific angle
  chassis.set_turn_pid(-343, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-50, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(80, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(70, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Toggle the intake
  intake.toggle(false, false);

  // Delay to wait for the piston to settle
  pros::delay(400);

  // Turn to a specific angle
  chassis.set_turn_pid(-360, TURN_SPEED);
  chassis.wait_drive();

  // Spin the catapult to a specific position
  catapult.CataSpinToPosition(0, 140);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-20, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(10, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(20, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-15, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Move forward to a specific target position and toggle the intake
  chassis.set_drive_pid(15, DRIVE_SPEED, true, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(60, DRIVE_SPEED, true);
  chassis.wait_until(60);

  // Turn to a specific angle
  chassis.set_turn_pid(-30, TURN_SPEED);
  chassis.wait_drive();

  // Launch the catapult and load the ball
  catapult.MatchLoadSkills(22, 40);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-5, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-315, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-20, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-20, DRIVE_SPEED, true);
  chassis.wait_drive();
}


void displayAutonomousSelection(int selectedAutonomous) {
    // Update the controller LCD
    pros::lcd::set_text(1, "Selected Autonomous:");
    switch (selectedAutonomous) {
        case 1:
            pros::lcd::set_text(2, "Close Side Rush");
            break;
        case 2:
            pros::lcd::set_text(2, "Close Side Safer");
            break;
        case 3:
            pros::lcd::set_text(2, "Far Side");
            break;
        case 4:
            pros::lcd::set_text(2, "SKILLS");
            break;
        case 5:
            pros::lcd::set_text(2, "SKILLS MATCH ONLY");
            break;
        default:
            pros::lcd::set_text(2, "Invalid Selection");
            break;
    }

    // Create a new LVGL screen
    lv_obj_t *screen = lv_obj_create(NULL, NULL);
    lv_scr_load(screen);

    // Create a label widget to display the selected autonomous
    lv_obj_t *label = lv_label_create(screen, NULL);
    lv_label_set_text(label, "Selected Autonomous:");
    lv_obj_align(label, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);

    // Update the label text based on the selected autonomous
    switch (selectedAutonomous) {
        case 1:
            lv_label_set_text(label, "Selected Autonomous: Close Side Rush");
            break;
        case 2:
            lv_label_set_text(label, "Selected Autonomous: Close Side Safer");
            break;
        case 3:
            lv_label_set_text(label, "Selected Autonomous: Far Side");
            break;
        case 4:
            lv_label_set_text(label, "Selected Autonomous: SKILLS");
            break;
        case 5:
            lv_label_set_text(label, "Selected Autonomous: SKILLS MATCH ONLY");
            break;
        default:
            lv_label_set_text(label, "Selected Autonomous: Invalid Selection");
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

  pros::delay(500); // Stop the user from doing anything while legacy ports configure.
  lv_init();

  pros::ADIAnalogIn selector('E');     
  // Determine the selected autonomous based on potentiometer value
  int potValue = selector.get_value();
  int selectedAutonomous = 1; // Default to Routine 1  
  if (potValue > 3072) {
      selectedAutonomous = 5; // Routine 5 (SKILLS MATCH ONLY)
  } else if (potValue > 2304) {
      selectedAutonomous = 4; // Routine 4 (SKILLS)
  } else if (potValue > 1536) {
      selectedAutonomous = 3; // Routine 3
  } else if (potValue > 768) {
      selectedAutonomous = 2; // Routine 2
  }    
  // Display the selected autonomous on the controller's LCD
  displayAutonomousSelection(selectedAutonomous);  

  // Configure your chassis controls
  chassis.toggle_modify_curve_with_controller(true); // Enables modifying the controller curve with buttons on the joysticks
  chassis.set_active_brake(0.1); // Sets the active brake kP. We recommend 0.1.
  chassis.set_curve_default(0, 0); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.set_left_curve_buttons (pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT); // If using tank, only the left side is used. 
  // chassis.set_right_curve_buttons(pros::E_CONTROLLER_DIGITAL_Y,    pros::E_CONTROLLER_DIGITAL_A);

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
    
    // Get the potentiometer value to determine the selected autonomous
    int potValue = selector.get_value();
    int selectedAutonomous = 1; // Default to Routine 1

    if (potValue > 3072) {
        selectedAutonomous = 5; // Routine 5 (SKILLS MATCH ONLY)
    } else if (potValue > 2304) {
        selectedAutonomous = 4; // Routine 4 (SKILLS)
    } else if (potValue > 1536) {
        selectedAutonomous = 3; // Routine 3
    } else if (potValue > 768) {
        selectedAutonomous = 2; // Routine 2
    }

    // Display the selected autonomous on the controller's LCD and the screen
    displayAutonomousSelection(selectedAutonomous);

    // Run the selected autonomous
    switch (selectedAutonomous) {
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
        case 5:
            SkillsMatchOnly(catapult, intake, pistons);
            break;
        default:
            // If an invalid selection is made, do nothing or display an error message.
            break;
    }
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


