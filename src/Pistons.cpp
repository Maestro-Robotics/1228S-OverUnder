// Include necessary header files
#include "pros/adi.hpp"
#include "Pistons.hpp"

pros::ADIDigitalOut Arm({{17, 'H'}});

bool ArmState = true;

// Constructor for the Pistons class
// Initializes the ADI objects representing the pneumatic pistons
Pistons::Pistons(uint8_t const CataPistonPort, uint8_t const TrackingWheelPistonPort, uint8_t const IntakeLaunchPort1, uint8_t const IntakeLaunchPort2)
    : CatapultAngleChange{CataPistonPort}, LiftTrackingWheel{TrackingWheelPistonPort}, ExpandIntake1{IntakeLaunchPort1}, ExpandIntake2{IntakeLaunchPort2} {}

// Function to control the pistons used for the initial launch of the intake mechanism
// Parameters:
// - boolean: true to expand the intake, false to retract it
void Pistons::InitialLaunch(bool boolean) {
    ExpandIntake1.set_value(boolean);
    ExpandIntake2.set_value(boolean);
}

// Function to control the piston used to lift the tracking wheel
void Pistons::LiftWheel() {
    LiftTrackingWheel.set_value(true);
}

// Function to control the piston used to change the catapult angle
// Parameters:
// - tf: true to change the angle, false to keep it unchanged
void Pistons::ChangeAngle(bool tf) {
    CatapultAngleChange.set_value(tf);
}


void Pistons::ArmMove() {
    Arm.set_value(ArmState);
    
    ArmState = !ArmState;
}