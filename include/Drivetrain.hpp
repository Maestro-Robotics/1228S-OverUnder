#pragma once

#include <cstdint>
#include "pros/motors.hpp"

class Drivetrain {
private:
	pros::Motor LeftMotor1;
	pros::Motor LeftMotor2;
    pros::Motor LeftMotor3;
	pros::Motor RightMotor1;
    pros::Motor RightMotor2;
	pros::Motor RightMotor3;
public:
	Drivetrain(int8_t leftMotor1port, int8_t leftMotor2port, int8_t leftMotor3port, int8_t rightmotor1port, int8_t rightmotor2port, int8_t rightmotor3port);
	void update(int32_t forward_backward_axis, int32_t left_right_axis);
};