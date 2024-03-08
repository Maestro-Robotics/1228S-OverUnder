// Include necessary header files
#include "main.h"
#include "EZ-Template/auton.hpp"
#include "autons.hpp"
#include "lemlib/chassis/trackingWheel.hpp"
#include "pros/motors.h"

// drive motors
pros::Motor lF(-10, pros::E_MOTOR_GEARSET_06); // left front motor. port 7, reversed
pros::Motor lM(-17, pros::E_MOTOR_GEARSET_06); // left middle motor. port 8, reversed
pros::Motor lB(-19, pros::E_MOTOR_GEARSET_06); // left back motor. port 10
pros::Motor rF(2, pros::E_MOTOR_GEARSET_06); // right front motor. port 1, reversed
pros::Motor rM(4, pros::E_MOTOR_GEARSET_06); // right middle motor. port 3
pros::Motor rB(9, pros::E_MOTOR_GEARSET_06); // right back motor. port 4

// motor groups
pros::MotorGroup leftMotors({lF, lM, lB}); // left motor group
pros::MotorGroup rightMotors({rF, rM, rB}); // right motor group

// Inertial Sensor on port 19
pros::Imu imu(11);

// drivetrain settings
lemlib::Drivetrain drivetrain(&leftMotors, // left motor group
                              &rightMotors, // right motor group
                              12, // 11 inch track width
                              lemlib::Omniwheel::NEW_275, // using new 2.75" omnis
                              450, // drivetrain rpm is 400
                              8 // chase power is 2. If we had traction wheels, it would have been 8
);

// lateral motion controller
lemlib::ControllerSettings linearController(14, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            5.5, // derivative gain (kD)
                                            0, // anti windup
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            2, // large error range, in inches
                                            200, // large error range timeout, in milliseconds
                                            0 // maximum acceleration (slew)
);


// angular motion controller
lemlib::ControllerSettings angularController(5, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             27.95, // derivative gain (kD)
                                             0, // anti windup
                                             1, // small error range, in degrees
                                             50, // small error range timeout, in milliseconds
                                             2, // large error range, in degrees
                                             100, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);
// sensors for odometry
// note that in this example we use internal motor encoders (IMEs), so we don't pass vertical tracking wheels
lemlib::OdomSensors sensors(nullptr, // vertical tracking wheel 1
                            nullptr, // vertical tracking wheel 2
                            nullptr, // horizontal tracking wheel 1
                            nullptr, // horizontal tracking wheel 2
                            &imu // inertial sensor
);

// create the chassis
lemlib::Chassis lemchassis(drivetrain, linearController, angularController, sensors);


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  // Shows position of the bot (Used for creating auton)
  
  pros::lcd::initialize();

  pros::Task screenTask([=]() {
        while (true) {
            pros::lcd::print(0, "X: %f", lemchassis.getPose().x);
            pros::lcd::print(1, "Y: %f", lemchassis.getPose().y);
            pros::lcd::print(2, "Theta: %f", lemchassis.getPose().theta);
            pros::delay(50);
        }
    });

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.autons_add({
    Auton("Goal Side 6 Ball", testGoal),
    Auton("Pure lib\n Preload(5 Point)", preloadGoal),
    Auton("lib & PID Blended\n Far Side Safe (9 points), \n 2 tile, bar inwards", closeSideAWP),
    Auton("Disrupt Close, Elim", disruptClose),
    Auton("Skills", driverSkills),
  });

// initialize Library and autonomous selector
  lemchassis.calibrate();
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

void autonomous() {

  //Calls Autonomous using autonomous selector
  //driverSkills();
  Skills();
  //closeSideAWP();
  //twentyFiveGoal();
  //testGoal();
  //preloadGoal();
  //ez::as::auton_selector.selected_auton_call();
  // lemchassis.moveToPoint(0, 20, 5000);
  //lemchassis.turnToHeading(90, 3000);
  // lemchassis.moveToPoint(10, 20, 5000);
  // lemchassis.moveToPose(0, 0, 0, 4000, {.forwards = false, .chasePower = 15});
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
  Catapult catapult(12, 15);
  Intake intake(8);
  Pistons pistons('H', 'A', 'C', 'B', 'E');
  PTO pto(12, 15, 3, 'G');
  Subsystems subsystems(catapult, intake, pistons, pto);

  //Sets drivetrain brake mode to coast for smoother driving
  lemchassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);

  // applies all of these functions based on how different autonomouses ended  
  pistons.closeFrontWings();
  pistons.closeBackWings();

  // lemchassis.setPose(0, 0, 315);

  // //Push preloads into Close Goal
  // lemchassis.moveToPose(37, -24, 270, 2000, {.forwards = false, .minSpeed = 127, .earlyExitRange = 3});

  // //Setup for Matchload position
  // lemchassis.moveToPoint(18, -18, 800);
  // lemchassis.turnToHeading(384, 800);
  // lemchassis.moveToPose(13, -26, 384, 1000, {.forwards = false, .chasePower = 18, .lead = 0});
  // lemchassis.waitUntilDone();
  // pistons.launchBackWings(true, false);

  // catapult.cataMatchLoad(160);
      
  while (true) {
    subsystems.update();
    pros::delay(ez::util::DELAY_TIME);
  }
    
}

