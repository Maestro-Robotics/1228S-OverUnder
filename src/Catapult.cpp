#include "Subsystems.hpp"

// Constructor for Catapult class
Catapult::Catapult(int8_t const fullMotorPort, int8_t const halfMotorPort) :
 fullMotor{ fullMotorPort },
 halfMotor{halfMotorPort} {}

bool running = false;

// Function to spin the catapult until stopped (Skills/Match loading)
void Catapult::cataMatchLoad(int velocity){
    if (running == true){
        fullMotor.move_velocity(0);
        halfMotor.move_velocity(0);
    }
    else{
        fullMotor.move_velocity(velocity);
        halfMotor.move_velocity(velocity);
    }
}


