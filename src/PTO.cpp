#include "PTO.hpp"
#include "Pistons.hpp"
#include "pros/motors.h"
#include "pros/rtos.hpp"

PTO::PTO(int8_t const fullMotorPort, int8_t const halfMotorPort, uint8_t const liftRotationPort, uint8_t const PTOPistonPort) :
 fullMotor{ fullMotorPort },
 halfMotor{halfMotorPort},
 liftRotation{liftRotationPort},
 PTOPiston{PTOPistonPort} {}

 void PTO::changeBrakeMode(pros::motor_brake_mode_e brakeMode){
    fullMotor.set_brake_mode(brakeMode);
    halfMotor.set_brake_mode(brakeMode);
 }

 void PTO::engagePTO(bool trueFalse){
    fullMotor.move_velocity(200);
    halfMotor.move_velocity(200);
    pros::Task::delay(450);
    PTOPiston.set_value(true);
    fullMotor.move_velocity(-200);
    halfMotor.move(-200);
    // PTOPiston.set_value(false);
    // pros::Task::delay(200);
    // PTOPiston.set_value(true);

    const int timeout = 2000;
    uint32_t start_time = pros::millis();
    
 pros::Task PTOEngaged {[=]{
  while (true){
  if (pros::millis() - start_time > timeout) {
        fullMotor.move_velocity(0);
        halfMotor.move_velocity(0);
        fullMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        halfMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
        break;
    }
  }
  }
 };
 }

 void PTO::liftToAngle(int velocity, int fullRotations){
    pros::Task PTOEngaged {[=]{
        while(liftRotation.get_position() != fullRotations){
            fullMotor.move_velocity(velocity);
            halfMotor.move_velocity(velocity);
        }
        fullMotor.move_velocity(0);
        halfMotor.move_velocity(0);
    }
    };
 }

