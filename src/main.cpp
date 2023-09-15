// Include necessary header files
#include "main.h"
#include "autoSelect/selection.h"
#include "lemlib/chassis/trackingWheel.hpp"
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


/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  selector::init();
  lemchassis.calibrate();
  lemchassis.setPose(0, 0, 0);
  lemchassis.setPose(46, -61, 45);
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

void goToGoal(){
    Pistons pistons('H');
    lemchassis.moveTo(33, 0, 90, 3000, false, true, 3, 0.6, 200);
    pistons.InitialLaunch(false);
    lemchassis.moveTo(41, 0, 90, 3000, false, true, 3, 0.6, 200);
    lemchassis(32, 0, 90, 3000, false, true, 3, 0.6, 200);
}

ASSET(removeball_txt);
ASSET(removeballtest_txt);
ASSET(testpath_txt);

void autonomous() {
    Catapult catapult(15, 20);
    Intake intake(11);
    Pistons pistons('H');

    pistons.launchWings(true);
    lemchassis.moveTo(55, -47, 0, 2000, false, true, 3, 0.6);
    // lemchassis.moveTo(60, -36, 0, 3000, false, true, 3);
    pistons.launchWings(false);
    lemchassis.moveTo(64, -17, 0, 2000, false, true, 6, 0.6, 180);
    lemchassis.moveTo(46, -43, 135, 2000, false, false, 3, 0.6, 180);
    pistons.InitialLaunch(true);
    intake.toggle(false, false);
    lemchassis.moveTo(4, -20, 90, 3000, false, true, 3, 0.6, 190);
    intake.toggle(true, true);

    goToGoal();

    pistons.InitialLaunch(true);
    intake.toggle(false, false);
    lemchassis.moveTo(24, 0, 180, 3000, false, true, 3);
    intake.toggle(true, true);

    goToGoal();

    
    pistons.InitialLaunch(true);
    intake.toggle(false, false);
    lemchassis.moveTo(4, 1, 180, 3000, false, true, 3);
    intake.toggle(true, true);

    goToGoal();



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
    Catapult catapult(15, 20);
    Intake intake(11);
    Pistons pistons('H');
    Subsystems subsystems(catapult, intake, pistons);

    pistons.InitialLaunch(true);
        
    while (true) {
      subsystems.update();
    }
      
}

