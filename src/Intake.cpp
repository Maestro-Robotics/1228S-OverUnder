#include "Intake.hpp"

// Constructor for Intake class
Intake::Intake(int8_t const Intakeport) : IntakeMotor{ Intakeport } {}

int velocity = -600;


// Function to toggle the intake's direction and set it on or off
void Intake::toggle(bool const reverse, bool off) {
    if (off) {
        IntakeMotor.move_velocity(0);
    }
    else{
        if (reverse){
            velocity = 600;
        }
        else if(reverse == false){
            velocity = -600;
        }

        IntakeMotor.move_velocity(velocity);
        
        }
}

// Function to calculate the velocity based on the direction (forward or reverse)
int32_t Intake::reverse_velocity(int32_t const velocity) const {
    // Otherwise, return the original velocity for forward direction
    return -1 * velocity;
}
