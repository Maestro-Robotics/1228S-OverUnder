#include "pros/adi.hpp"

#include "Pistons.hpp"

Pistons::Pistons(uint8_t const CataPistonPort, uint8_t const TrackingWheelPistonPort, uint8_t const IntakeLaunchPort) : CatapultAngleChange{CataPistonPort}, LiftTrackingWheel{TrackingWheelPistonPort}, ExpandIntake{IntakeLaunchPort} {}

void Pistons::InitialLaunch(){
    ExpandIntake.set_value(true);
}

void Pistons::LiftWheel(){
    LiftTrackingWheel.set_value(true);
}