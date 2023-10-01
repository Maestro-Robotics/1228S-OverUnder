// Include necessary header files
#include "main.h"
#include "pros/rtos.hpp"
#include "pros/apix.h" // Include the LVGL library

// drive motors
pros::Motor lF(-1, pros::E_MOTOR_GEARSET_06); // left front motor. port 1, reversed
pros::Motor lM(2, pros::E_MOTOR_GEARSET_06); // left front motor. port 2
pros::Motor lB(-3, pros::E_MOTOR_GEARSET_06); // left back motor. port 3, reversed
pros::Motor rF(6, pros::E_MOTOR_GEARSET_06); // right front motor. port 6
pros::Motor rM(-7, pros::E_MOTOR_GEARSET_06); // right front motor. port 7, reversed
pros::Motor rB(9, pros::E_MOTOR_GEARSET_06); // right back motor. port 9

// motor groups
pros::MotorGroup leftMotors({lF, lM, lB}); // left motor group
pros::MotorGroup rightMotors({rF, rM, rB}); // right motor group

// Inertial Sensor on port 11
pros::Imu imu(19);


// drivetrain
lemlib::Drivetrain_t drivetrain {&leftMotors, &rightMotors, 10, lemlib::Omniwheel::NEW_325, 360};

lemlib::ChassisController_t lateralController {
    13, // kP
    5, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};

// turning PID
lemlib::ChassisController_t angularController {
    6, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
};

// sensors for odometry
lemlib::OdomSensors_t sensors {nullptr, nullptr, nullptr, nullptr, &imu};

lemlib::Chassis lemchassis(drivetrain, lateralController, angularController, sensors);


// Chassis constructor
Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  {-1, 2, -3}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is the sensored port (when trackers are not used!)
  ,{6, -7, 8}

  // IMU Port
  ,19

  // Wheel Diameter (Remember, 4" wheels are actually 4.125!)
  //    (or tracking wheel diameter)
  ,3.25

  // Cartridge RPM
  //   (or tick per rotation if using tracking wheels)
  ,600

  // External Gear Ratio (MUST BE DECIMAL)
  //    (or gear ratio of tracking wheel)
  // eg. if your drive is 84:36 where the 36t is powered, your RATIO would be 2.333.
  // eg. if your drive is 36:60 where the 60t is powered, your RATIO would be 0.6.
  ,0.6


  // Uncomment if using tracking wheels
  /*
  // Left Tracking Wheel Ports (negative port will reverse it!)
  // ,{1, 2} // 3 wire encoder
  // ,8 // Rotation sensor

  // Right Tracking Wheel Ports (negative port will reverse it!)
  // ,{-3, -4} // 3 wire encoder
  // ,-9 // Rotation sensor
  */

  // Uncomment if tracking wheels are plugged into a 3 wire expander
  // 3 Wire Port Expander Smart Port
  // ,1
);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
// // Print our branding over your terminal :D
//   ez::print_ez_template();
  
//   pros::delay(500); // Stop the user from doing anything while legacy ports configure.

//   // Configure your chassis controls
//   chassis.toggle_modify_curve_with_controller(true); // Enables modifying the controller curve with buttons on the joysticks
//   chassis.set_active_brake(0); // Sets the active brake kP. We recommend 0.1.
//   chassis.set_curve_default(0, 0); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
//   default_constants(); // Set the drive to your own constants from autons.cpp!
//   chassis.set_exit_condition(chassis.turn_exit,  50, 3,  500, 7,   250, 250);
//   chassis.set_exit_condition(chassis.swing_exit, 50, 3,  500, 7,   250, 250);
//   chassis.set_exit_condition(chassis.drive_exit, 50,  50, 300, 150, 250, 250);
//   // These are already defaulted to these buttons, but you can change the left/right curve buttons here!
//   // chassis.set_left_curve_buttons (pros::E_CONTROLLER_DIGITAL_LEFT, pros::E_CONTROLLER_DIGITAL_RIGHT); // If using tank, only the left side is used. 
//   // chassis.set_right_curve_buttons(pros::E_CONTROLLER_DIGITAL_Y,    pros::E_CONTROLLER_DIGITAL_A);

//   // Autonomous Selector using LLEMU
//   ez::as::auton_selector.add_autons({
//     Auton("5 Triball GoalSide Auton (25 points)", goalSide),
//     Auton("push preload in", goalSafe),
//     Auton("Far Side Safe (9 points)", farSideSafe),
//     Auton("Far Side Rush (9/11 points)", farSide),
//     Auton("Skills", SkillsDevelopment)
//   });

  // Initialize chassis and auton selector
  pros::lcd::initialize();
    lemlib::Logger::initialize();
    lemchassis.calibrate(); // calibrate sensors

    // print odom values to the brain
    pros::Task screenTask([=]() {
        while (true) {
            pros::lcd::print(0, "X: %f", lemchassis.getPose().x);
            pros::lcd::print(1, "Y: %f", lemchassis.getPose().y);
            pros::lcd::print(2, "Theta: %f", lemchassis.getPose().theta);
            lemlib::Logger::logOdom(lemchassis.getPose());
            pros::delay(50);
        }
    });
  // chassis.initialize();
  //ez::as::initialize();
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

void lemGoalSideTest(){
   
 Catapult catapult(15, 14);
 Intake intake(11);
 Pistons pistons('H');

      pistons.launchWings(true);
  lemchassis.moveTo(-30, 14, 270, 2000, false, true, 10);
  pistons.launchWings(false);
  lemchassis.moveTo(-30, 10, 270, 2000, false, true, 10);
  pistons.InitialLaunch(true);
  intake.toggle(false, false);
  lemchassis.moveTo(-33, -30, 220, 2000, false, true, 10);
  intake.toggle(false, false);
  lemchassis.moveTo(-65, -20, 0, 2000, false, true, 10);
  pistons.InitialLaunch(false);
  pistons.launchWings(true);
  intake.toggle(true, false);
  lemchassis.moveTo(-65, 10, 0, 1500, false, true, 10);
  intake.toggle(false, true);
  pistons.InitialLaunch(true);
  pistons.launchWings(false);
  intake.toggle(false, false);
  lemchassis.moveTo(-65, -30, 200, 2000, false, true, 10);
  lemchassis.moveTo(-65, -20, 0, 2000, false, true, 10);
  intake.toggle(false, true);
  pistons.InitialLaunch(false);
  pistons.launchWings(true);
  intake.toggle(true, false);
  lemchassis.moveTo(-65, 10, 0, 1500, false, true, 10);
  lemchassis.moveTo(-65, 15, 0, 500, false, true, 10);
  lemchassis.moveTo(0, -30, 180, 2000, false, true, 10);
}

ASSET(FrontGoal_txt);
ASSET(PassBarrier_txt);
ASSET(test2_txt);

void Skills(){
  
 Catapult catapult(15, 14);
 Intake intake(11);
 Pistons pistons('H');
  
lemchassis.setPose(-38,56,0);

pistons.launchWings(true);
lemchassis.moveTo(-37, 66, 22, 2000, false, true, 7);
pistons.launchWings(false);

const int timeout = 30000;
uint32_t start_time = pros::millis();

pistons.InitialLaunch(true);

catapult.cataMatchLoad(-200);
while (true){
if (pros::millis() - start_time > timeout) {
      std::printf("Spin motor timeout reached");
      catapult.cataSpinToPosition(0, -200);
      break;
  }
}

lemchassis.moveTo(-61, 79, 90, 2000, false, false, 12);

pistons.InitialLaunch(true);

lemchassis.setPose(60, -35, 180);

lemchassis.follow(PassBarrier_txt, 10000, 12, false, true);

pistons.InitialLaunch(false);
pistons.launchWings(true);

lemchassis.follow(FrontGoal_txt, 3000, 10, false, true);

lemchassis.turnTo(-39, 0, 1000);

lemchassis.setPose(0, 0, 0);
lemchassis.moveTo(0, 50, 0, 2000, false, true, 9);
pistons.launchWings(false);

lemchassis.moveTo(20, 10, 0, 3000, false, true, 9);
pistons.launchWings(true);

lemchassis.moveTo(5, 50, 0, 2000, false, true, 12);
pistons.launchWings(false);

lemchassis.moveTo(-20, 10, 0, 3000, false, true, 9);
pistons.launchWings(true);

lemchassis.moveTo(-10, 50, 0, 2000, false, true, 12);
pistons.launchWings(false);

lemchassis.moveTo(-40, 5, 315, 3000, false, true, 9);

lemchassis.moveTo(-61, 30, 220, 2000, false, true, 9);

lemchassis.moveTo(-41, 49, 251, 2000, false, false, 12);

lemchassis.setPose(0, 0, 0);

lemchassis.moveTo(0, 30, 0, 2000, false, true, 15);

lemchassis.moveTo(0, -10, 0, 2000, false, false, 30);
}

void autonomous() {
//     chassis.reset_pid_targets(); // Resets PID targets to 0
//     chassis.reset_gyro(); // Reset gyro position to 0
//     chassis.reset_drive_sensor(); // Reset drive sensors to 0
//     chassis.set_drive_brake(MOTOR_BRAKE_HOLD); // Set motors to hold.  This helps autonomous consistency.

    // ez::as::auton_selector.call_selected_auton();
    
//  Catapult catapult(15, 14);
//  Intake intake(11);
//  Pistons pistons('H');

// lemchassis.setPose(0, 0, 0);

// pistons.launchWings(true);

// lemchassis.moveTo(7, 14, 90, 2000, false, true, 9);
// pistons.launchWings(false);

// lemchassis.moveTo(22, 15, 90, 2000, false, true, 12);

// lemchassis.moveTo(7, -2, 108, 2000, false, false, 9);

// lemchassis.moveTo(43, -13, 100, 2000, true, true, 9);
// lemchassis.waitUntilDist(10);
// pistons.InitialLaunch(true);
// intake.toggle(false, false);
// lemchassis.waitUntilDist(1000);

// //lemchassis.moveTo(35, -19, 0, 2500, false, true, 7);
// lemchassis.turnTo(43, 0, 2000);
// catapult.cataSpinToPosition(0, -200);

// lemchassis.moveTo(46, -29, 135, 2000, false, true, 9);

// lemchassis.moveTo(35, -19, 0, 2500, false, true, 7);
// catapult.cataSpinToPosition(0, -200);

// lemchassis.turnTo(23, -18, 2000);

// pistons.InitialLaunch(false);
// intake.toggle(false, true);

// lemchassis.moveTo(-3, -4, 180, 2000, false, true, 15);

// lemchassis.moveTo(-3, -60, 180, 2000, false, true, 30);

Skills();


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
    Catapult catapult(15, 14);
    Intake intake(11);
    Pistons pistons('H');
    Subsystems subsystems(catapult, intake, pistons);
    lemchassis.setPose(0,0,0);


    pistons.InitialLaunch(true);

    if (GoalSide == true){
      pistons.InitialLaunch(true);
      catapult.cataSpinToPosition(1, -200);
    }
    
    
        
    while (true) {
      subsystems.update();
      pros::delay(ez::util::DELAY_TIME);
    }
      
}

