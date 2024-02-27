// Include necessary header files
#include "pros/adi.hpp"
#include "Pistons.hpp"

// Constructor for the Pistons class
// Initializes the ADI objects representing the pneumatic pistons
Pistons::Pistons(uint8_t const bWingR, uint8_t const bWingL, uint8_t const fWingR, uint8_t const fWingL, uint8_t const hangRatchet)
    : actuateBRightWings(bWingR),
      actuateBLeftWings(bWingL),
      actuateFRightWings(fWingR),
      actuateFLeftWings(fWingL),
      actuateRatchet(hangRatchet) {}

void Pistons::launchBackWings(bool left, bool right) {
    actuateBLeftWings.set_value(left);
    actuateBRightWings.set_value(right);
}

void Pistons::launchFrontwings(bool left, bool right) {
    actuateFLeftWings.set_value(left);
    actuateFRightWings.set_value(right);
}

void Pistons::closeFrontWings(){
    actuateFLeftWings.set_value(false);
    actuateFRightWings.set_value(false);
}

void Pistons::closeFrontWings(bool left, bool right){
    actuateFLeftWings.set_value(left);
    actuateFRightWings.set_value(right);
}

void Pistons::closeBackWings(){
    actuateBLeftWings.set_value(false);
    actuateBRightWings.set_value(false);
}

void Pistons::closeBackWings(bool left, bool right){
    actuateBLeftWings.set_value(left);
    actuateBRightWings.set_value(right);
}

void Pistons::engageRatchet(bool trueFalse){
    actuateRatchet.set_value(trueFalse);
}