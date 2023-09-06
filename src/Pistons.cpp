// Include necessary header files
#include "pros/adi.hpp"
#include "Pistons.hpp"

pros::ADIDigitalOut actuateIntake({{12, 'C'}});
pros::ADIDigitalOut actuateWings({{12, 'B'}});

// Constructor for the Pistons class
// Initializes the ADI objects representing the pneumatic pistons
Pistons::Pistons(uint8_t const elevationPort)
    : elevationLaunch(elevationPort) {}

// Function to control the pistons used for the initial launch of the intake mechanism
// Parameters:
// - boolean: true to expand the intake, false to retract it
void Pistons::InitialLaunch(bool boolean) {
    actuateIntake.set_value(boolean);
}

// Function to control the piston used to change the state of the Wings
void Pistons::launchWings(bool tf) {
    actuateWings.set_value(tf);
}

void Pistons::launchElevation() {
    elevationLaunch.set_value(true);
}
