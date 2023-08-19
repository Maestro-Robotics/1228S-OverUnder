// Include necessary header files
#include "main.h"
#include "Catapult.hpp"
#include "Intake.hpp"
#include "pros/rtos.hpp"
#include "pros/apix.h" // Include the LVGL library

lv_obj_t *label; // Declare a global pointer for the label widget

bool COLOR_DETECTED = false;



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
  ,{3, 4} // 3 wire encoder
  // Rotation sensor


  // Uncomment if tracking wheels are plugged into a 3 wire expander
  // 3 Wire Port Expander Smart Port
  ,17
);


void intake_control_task(void* param) {
    Intake* intake = static_cast<Intake*>(param); // Cast the parameter back to Intake*

    pros::Optical optical_sensor(15);

    // Debug print to indicate task has started
    printf("Intake Control Task started\n");

    while (true) {
        int hue = optical_sensor.get_hue();
        printf("Hue: %d\n", hue);

        optical_sensor.set_led_pwm(100);

        if (hue > 80 && hue < 120) {
            printf("Green detected\n");
            intake->toggle(true, true);
            COLOR_DETECTED = true;
            // When Green is detected, out of loop
        }

        pros::delay(1); // Adjust the delay as needed
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

  // Configure your chassis controls
  chassis.toggle_modify_curve_with_controller(true); // Enables modifying the controller curve with buttons on the joysticks
  chassis.set_active_brake(0.05); // Sets the active brake kP. We recommend 0.1.
  chassis.set_curve_default(0, 0); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
  // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
  // chassis.set_left_curve_buttons (pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT); // If using tank, only the left side is used. 
  // chassis.set_right_curve_buttons(pros::E_CONTROLLER_DIGITAL_Y,    pros::E_CONTROLLER_DIGITAL_A);

  chassis.set_exit_condition(chassis.turn_exit,  50, 3,  500, 7,   250, 250);
  chassis.set_exit_condition(chassis.swing_exit, 100, 3,  500, 7,   500, 500);
  chassis.set_exit_condition(chassis.drive_exit, 50,  50, 300, 150, 250, 250);

  
	// chassis.set_slew_min_power(80, 80);
	// chassis.set_slew_distance(7, 7);
	// chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
	// chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 5, 0);
	// chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
	// chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
	// chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);



  ez::as::auton_selector.add_autons({
    Auton("Autonomous 3\n Far Side (Shoots)", FarSide),
    Auton("Autonomous 1\n Goal Side Rush", GoalSideRush),
    Auton("Autonomous 5\n Skills Match Load Only", SkillsMatchLoadOnly),
    Auton("Autonomous 2\n Goal Side Safe", GoalSideSafe),
    Auton("Autonomous 4\n Skills Development", SkillsDevelopment)
    
  });

  ez::as::auton_selector.print_selected_auton(); 

  // Initialize chassis
  chassis.initialize();
  ez::as::initialize();
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
    chassis.reset_pid_targets();
    chassis.reset_gyro();
    chassis.reset_drive_sensor();
    chassis.set_drive_brake(MOTOR_BRAKE_HOLD);
    ez::as::auton_selector.call_selected_auton(); // Calls selected auton from autonomous selector.
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
    Catapult catapult(2, 5, 16);
    Intake intake(1);
    Pistons pistons('A', 'B', 'C', 'D');
    Subsystems subsystems(catapult, intake, pistons);

    pros::Optical optical(15);
    pros::Controller controller(pros::E_CONTROLLER_MASTER);

    // initial thread started
    pros::Task intake_task(intake_control_task, &intake, TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "Intake Control Task");

    pistons.ChangeAngle(GoalSide);
    pistons.InitialLaunch(true);
        
    while (true) {

        if (optical.get_hue() < 80 || optical.get_hue() > 120) {
          if (GoalSide == true) {
            COLOR_DETECTED = false;
            // When Green is detected, out of loop
          }

          else {
            COLOR_DETECTED = true;
          }
        }

        if (COLOR_DETECTED  == true) {
          // write, thread re-start 
          intake_task.suspend();
        }

        else {
          intake_task.resume();
        }

        // Update other subsystems and drive control
        chassis.arcade_standard(ez::SPLIT);
        subsystems.update();
        pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
    }
      
}

