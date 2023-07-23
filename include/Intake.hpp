#pragma once

#include <cstdint>
#include "pros/motors.hpp"

class Intake {
private:
	pros::Motor IntakeMotor;
	int m_on = false;
	bool m_reverse = false;

public:
	Intake(int8_t const IntakePort);
	void set_on(bool const value);
	void toggle(bool const reverse, bool off);
	int32_t reverse_velocity(int32_t const velocity) const;

};