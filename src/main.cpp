#include "main.h"
#include "pros/rtos.hpp"


// drivetrain motors
pros::Motor LeftMotor1{ 8, pros::E_MOTOR_GEARSET_06, true};
pros::Motor LeftMotor2{ 9, pros::E_MOTOR_GEARSET_06 };
pros::Motor LeftMotor3{ 10, pros::E_MOTOR_GEARSET_06 };
pros::Motor RightMotor1{ 18, pros::E_MOTOR_GEARSET_06, true};
pros::Motor RightMotor2{ 19, pros::E_MOTOR_GEARSET_06, true};
pros::Motor RightMotor3{ 20, pros::E_MOTOR_GEARSET_06 };
 
// drivetrain motor groups
pros::MotorGroup left_side_motors({LeftMotor1, LeftMotor1, LeftMotor3});
pros::MotorGroup right_side_motors({RightMotor1, RightMotor2, RightMotor3});
 
lemlib::Drivetrain_t drivetrain {
    &left_side_motors, // left drivetrain motors
    &right_side_motors, // right drivetrain motors
    12.58, // track width
    4, // wheel diameter
    343 // wheel rpm
};


// left tracking wheel encoder
pros::ADIEncoder vert_enc({ 17, 'A', 'B' }, true); // ports A and B, reversed

// back tracking wheel encoder
pros::ADIEncoder hori_enc({17 , 'C', 'D'}, true); // ports C and D, reversed
 
// left tracking wheel
lemlib::TrackingWheel VerticalTracker(&vert_enc, 2.75, -0.1); // 2.75" wheel diameter, -0.1" offset from tracking center
// back tracking wheel
lemlib::TrackingWheel HorizontalTracker(&hori_enc, 2.75, 5); // 2.75" wheel diameter, 5" offset from tracking center
 
// inertial sensor
pros::Imu inertial_sensor(7); 
 
// odometry struct
lemlib::OdomSensors_t sensors {
    &VerticalTracker, // vertical tracking wheel 1
    nullptr, 
    &HorizontalTracker, // horizontal tracking wheel 1
    nullptr, 
    &inertial_sensor // inertial sensor
};
 
// forward/backward PID
lemlib::ChassisController_t lateralController {
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    40 // slew rate
};
 
 
// create the chassis
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);


void AllianceZoneAuton1(){
    chassis.moveTo(10, 0, 1000, 50);
}


/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	chassis.calibrate(); // calibrate the chassis
    chassis.setPose(0, 0, 0); // X: 0, Y: 0, Heading: 0
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
	AllianceZoneAuton1();
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
	Drivetrain const drivetrain(8, 9 ,10 ,18 , 19,20);
    Catapult const catapult(2, 5);
	Subsystems subsystems(drivetrain, catapult);

	while (true){
		subsystems.update();
		pros::delay(1);
}
	}


