#include "Intake.hpp"

// Constructor for Intake class
Intake::Intake(int8_t const Intakeport) : IntakeMotor{ Intakeport } {}

// Function to set the intake on or off based on the value parameter
void Intake::set_on(bool value) {
    m_on = value;
    auto velocity = 0;

    // If the intake is set to be turned on, set the velocity based on the reverse flag
    if (m_on) {
        velocity = reverse_velocity(600);
    }

    // Move the intake motor with the calculated velocity
    IntakeMotor.move_velocity(velocity);
}

// Function to toggle the intake's direction and set it on or off
void Intake::toggle(bool const reverse, bool off) {
    // If the intake is currently on, reset the reverse flag to false to ensure proper direction
    if (m_on) {
        m_reverse = false;
    }

    // Set the reverse flag based on the provided reverse parameter
    m_reverse = reverse;

    // If the off flag is true, turn the intake off; otherwise, toggle its state
    if (off) {
        set_on(false);
    } else {
        set_on(!m_on);
    }
}

// Function to calculate the velocity based on the direction (forward or reverse)
int32_t Intake::reverse_velocity(int32_t const velocity) const {
    // If the reverse flag is true, return the negative of the provided velocity to reverse the direction
    if (m_reverse) {
        return -1 * velocity;
    }
    // Otherwise, return the original velocity for forward direction
    return velocity;
}
