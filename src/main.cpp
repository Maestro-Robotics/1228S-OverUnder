// Include necessary header files
#include "main.h"
#include "autons.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"
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

// Inertial Sensor on port 19
pros::Imu imu(19);

// drivetrain
lemlib::Drivetrain_t drivetrain {&leftMotors, &rightMotors, 10, lemlib::Omniwheel::NEW_325, 400};

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
    2,
    10,
    1,
    100,
    3,
    500,
    0
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
  ez::as::auton_selector.add_autons({
    Auton("lib & PID Blended\n 5 Triball GoalSide Auton (25 points)", twentyFiveGoal),
    Auton("Pure lib\n Preload and one ball (10 Point)", goalSide10Point),
    Auton("lib & PID Blended\n Far Side Safe (9 points)", farSideAutonWin),
    Auton("lib & PID Blended \n Far Side MatchLoad (7 points)", farSideMatchLoad),
    Auton("lib & PID Blended \n Far Side Elims (5 points)", farSideElims),
    Auton("Pure lib\n Test Goal Side (20/25 points)", lemGoalSideTest),
    Auton("Skills", Skills),
    Auton("Driver Skills", driverSkills)
  });

// initialize libraries and autonomous selector
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

  //ez::as::auton_selector.call_selected_auton();
  farSideElims();

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

  if (GoalSide == true){
    catapult.cataSpinToPosition(1, -200);
  }

  if (matchLoadAuto == true){
    catapult.cataMatchLoad(-200);
  }
      
  while (true) {
    subsystems.update();
    pros::delay(ez::util::DELAY_TIME);
  }
    
}

