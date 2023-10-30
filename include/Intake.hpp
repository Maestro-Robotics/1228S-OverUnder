#pragma once

#include <cstdint>
#include "pros/motors.hpp"

class Intake {
private:
	pros::Motor IntakeMotor;

public:
	Intake(int8_t const IntakePort);
	void toggle(bool const reverse, bool off);
};