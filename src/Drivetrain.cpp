#include <cmath>

#include "Drivetrain.hpp"

Drivetrain::Drivetrain(int8_t leftMotor1port, int8_t leftMotor2port, int8_t leftMotor3port, int8_t rightmotor1port, int8_t rightmotor2port, int8_t rightmotor3port)
	: LeftMotor1{ leftMotor1port, pros::E_MOTOR_GEARSET_06, true}
	, LeftMotor2{ leftMotor2port, pros::E_MOTOR_GEARSET_06 }
    , LeftMotor3{ leftMotor3port, pros::E_MOTOR_GEARSET_06 }
    , RightMotor1{ rightmotor1port, pros::E_MOTOR_GEARSET_06, true}
	, RightMotor2{ rightmotor2port, pros::E_MOTOR_GEARSET_06, true}
	, RightMotor3{ rightmotor3port, pros::E_MOTOR_GEARSET_06 } {}



static float scale(float const raw) {
	return std::pow(raw / 127.0f, 3.0f) * 600 * 0.75;
}

void Drivetrain::update(int32_t forward_backward_axis_int, int32_t left_right_axis_int) {
	switch (m_reference_frame) {
		case DrivetrainReferenceFrame::IntakeAtFront:
			break;
		case DrivetrainReferenceFrame::CatapultAtFront:
			forward_backward_axis_int *= -1;
			left_right_axis_int *= 1;
			break;
	}

	auto forward_backward_axis = static_cast<float>(forward_backward_axis_int);
	auto left_right_axis = static_cast<float>(left_right_axis_int);

	forward_backward_axis = scale(forward_backward_axis);
	left_right_axis = scale(left_right_axis);

	auto const left_velocity = static_cast<int32_t>(forward_backward_axis - left_right_axis);
	auto const right_velocity = static_cast<int32_t>(forward_backward_axis + left_right_axis);

	LeftMotor1.move_velocity(left_velocity);
	LeftMotor2.move_velocity(left_velocity);
    LeftMotor3.move_velocity(left_velocity);

	RightMotor1.move_velocity(right_velocity);
	RightMotor2.move_velocity(right_velocity);
    RightMotor3.move_velocity(right_velocity);
}

void Drivetrain::next_reference_frame() {
	switch (m_reference_frame) {
		case DrivetrainReferenceFrame::IntakeAtFront:
			m_reference_frame = DrivetrainReferenceFrame::CatapultAtFront;
			break;
		case DrivetrainReferenceFrame::CatapultAtFront:
			m_reference_frame = DrivetrainReferenceFrame::IntakeAtFront;
			break;
	}
}