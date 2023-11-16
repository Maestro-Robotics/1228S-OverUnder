// Include necessary header files
#include "pros/adi.hpp"
#include "Pistons.hpp"

pros::ADIDigitalOut actuateElevation({{12, 'A'}});
pros::ADIDigitalOut actuateWings({{12, 'B'}});

// Constructor for the Pistons class
// Initializes the ADI objects representing the pneumatic pistons
Pistons::Pistons(uint8_t const elevationPort)
    : actuateBlocker(elevationPort) {}

// Function to control the pistons used for the launch of the blocker mechanism
// Parameters:
// - boolean: true to expand the blocker, false to retract it
void Pistons::launchBlocker(bool tf) {
    actuateBlocker.set_value(tf);
}

// Function to control the pistons used to change the state of the Wings
void Pistons::launchWings(bool tf) {
    actuateWings.set_value(tf);
}

// Function to control the piston used to launch the elevation state
void Pistons::launchElevation() {
    actuateElevation.set_value(true);
}
