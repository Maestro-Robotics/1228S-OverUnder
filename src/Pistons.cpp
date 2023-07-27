#include "pros/adi.hpp"

#include "Pistons.hpp"

Pistons::Pistons(uint8_t const CataPistonPort, uint8_t const TrackingWheelPistonPort, uint8_t const IntakeLaunchPort1, uint8_t const IntakeLaunchPort2) : CatapultAngleChange{CataPistonPort}, LiftTrackingWheel{TrackingWheelPistonPort}, ExpandIntake1{IntakeLaunchPort1}, ExpandIntake2{IntakeLaunchPort2} {}

void Pistons::InitialLaunch(){
    ExpandIntake1.set_value(true);
    ExpandIntake2.set_value(true);
}

void Pistons::LiftWheel(){
    LiftTrackingWheel.set_value(true);
}

void Pistons::ChangeAngle(bool tf){
    CatapultAngleChange.set_value(tf);}