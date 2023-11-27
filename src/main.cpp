// Include necessary header files
#include "main.h"
#include "EZ-Template/auton.hpp"
#include "autons.hpp"

// drive motors
pros::Motor lF(-7, pros::E_MOTOR_GEARSET_06); // left front motor. port 7, reversed
pros::Motor lM(-8, pros::E_MOTOR_GEARSET_06); // left middle motor. port 8, reversed
pros::Motor lB(10, pros::E_MOTOR_GEARSET_06); // left back motor. port 10
pros::Motor rF(-2, pros::E_MOTOR_GEARSET_06); // right front motor. port 1, reversed
pros::Motor rM(3, pros::E_MOTOR_GEARSET_06); // right middle motor. port 3
pros::Motor rB(4, pros::E_MOTOR_GEARSET_06); // right back motor. port 4

// motor groups
pros::MotorGroup leftMotors({lF, lM, lB}); // left motor group
pros::MotorGroup rightMotors({rF, rM, rB}); // right motor group

// Inertial Sensor on port 19
pros::Imu imu(19);

// drivetrain
lemlib::Drivetrain_t drivetrain {&leftMotors, &rightMotors, 11, lemlib::Omniwheel::NEW_325, 400};

// Drive PID
lemlib::ChassisController_t lateralController {
    13, // kP
    6, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};

// Turning PID
lemlib::ChassisController_t angularController {
    9, // kP
    73, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
};

//Swing PID
lemlib::ChassisController_t swingController {
    2, // kP
    10, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
};

// sensors for odometry
lemlib::OdomSensors_t sensors {nullptr, nullptr, nullptr, nullptr, &imu};

lemlib::Chassis lemchassis(drivetrain, lateralController, angularController, swingController, sensors);


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  // Shows position of the bot (Used for creating auton)
  
  // pros::lcd::initialize();

  // pros::Task screenTask([=]() {
  //       while (true) {
  //           pros::lcd::print(0, "X: %f", lemchassis.getPose().x);
  //           pros::lcd::print(1, "Y: %f", lemchassis.getPose().y);
  //           pros::lcd::print(2, "Theta: %f", lemchassis.getPose().theta);
  //           pros::delay(50);
  //       }
  //   });

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.add_autons({
    Auton("lib & PID Blended\n 5 Triball GoalSide Auton (25 points)", twentyFiveGoal),
    Auton("Disrupt Close, Elim", disruptClose),
    Auton("test goal", testGoal),
    Auton("Pure lib\n Preload(5 Point)", goalSide10Point),
    Auton("lib & PID Blended\n Far Side Safe (9 points)", farSideAutonWin),
    Auton("Far Side auton, touch match load zone", farSideMatchLoad),
    Auton("Skills", Skills),
    Auton("Driver Skills", driverSkills)
  });

// initialize Library and autonomous selector
  lemchassis.calibrate();
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

  //Calls Autonomous using autonomous selector
  ez::as::auton_selector.call_selected_auton();
  //twentyFiveGoal();
  //farSideAutonWin();
  //Skills();
  //testGoal();
 //disruptClose();
  

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

  // applies all of these functions based on how different autonomouses ended
  pistons.launchBlocker(false);

  if (GoalSide == true){
    catapult.cataSpinToPosition(0, -200);
  }

  if (matchLoadAuto == true){
    catapult.cataMatchLoad(-200);
  }
      
  while (true) {
    subsystems.update();
    pros::delay(ez::util::DELAY_TIME);
  }
    
}

