#include "Intake.hpp"

// Constructor for Intake class
Intake::Intake(int8_t const Intakeport) :
 IntakeMotor{ Intakeport } {}

int velocity = 600;

// Function to toggle the intake's direction and set it on or off
void Intake::toggle(bool const reverse, bool off) {
    if (off) {
        IntakeMotor.move_velocity(0);
    }
    else{
        if (reverse){
            velocity = -600;
        }
        else if(reverse == false){
            velocity = 600;
        }

        IntakeMotor.move_velocity(velocity);
        
        }
}
