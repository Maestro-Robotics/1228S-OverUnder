#pragma once

#include "Pistons.hpp"
#include "pros/adi.hpp"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"


extern Pistons pistons; 

class PTO{
    private:
        pros::Motor fullMotor;
        pros::Motor halfMotor;
        pros::Rotation liftRotation;
        pros::ADIDigitalOut PTOPiston;

    public:
        PTO(int8_t const fullMotorPort, int8_t const halfMotorPort, uint8_t const liftRotationPort, uint8_t const PTOPistonPort);

        int currentAngle = liftRotation.get_position();

        void changeBrakeMode(pros::motor_brake_mode_e);
        void engagePTO(bool trueFalse);
        void liftToAngle(int velocity, int fullRotations);
};