#include "Intake.hpp"


Intake::Intake(int8_t const Intakeport) : IntakeMotor{ Intakeport } {}

void Intake::set_on(bool value) {
	m_on = value;
	auto velocity = 0;
	if (m_on) {
		velocity = reverse_velocity(-600);
	}
	IntakeMotor.move_velocity(velocity);
}

void Intake::toggle(bool const reverse, bool off) {
	if (m_on) {
		m_reverse = false;
	}

	m_reverse = reverse;
    if (off) {
        set_on(false);
    } else {
        set_on(!m_on);
    }
}


int32_t Intake::reverse_velocity(int32_t const velocity) const {
	if (m_reverse) {
		return -1 * velocity;
	}
	return velocity;
}