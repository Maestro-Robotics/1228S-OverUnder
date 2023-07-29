#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include "Catapult.hpp"
#include "pros/rtos.hpp"

Catapult::Catapult(int8_t const CataPort, uint8_t const RotationPort, uint8_t const DistancePort) : CataMotor{ CataPort }, CataRotationSensor{ RotationPort} ,CataDistanceSensor{DistancePort} {}

void Catapult::SpinToTarget(int targetAngle, int angleRange, int velocity) {
     const int timeout = 3000; // set timeout to 3 seconds
     uint32_t start_time = pros::millis();

    //std::printf("abs = %d\n",std::abs(CataRotationSensor.get_angle() - targetAngle));

    CataMotor.move_velocity(velocity);
    pros::Task::delay(300);

    // Loop until the rotation sensor reaches the desired range of the target angle
    while (std::abs(CataRotationSensor.get_angle() - targetAngle) > angleRange) {

        //chassis.print("CataRotationSensor.get_angle() : %d\n",CataRotationSensor.get_angle());
        
        chassis.arcade_standard(ez::SPLIT);

         //std::printf("get_angle() : %d\n",CataRotationSensor.get_angle());
         //std::printf("abs = %d\n",std::abs(CataRotationSensor.get_angle() - targetAngle));
 
         if (pros::millis() - start_time > timeout) {
             std::printf("Spin motor timeout reached");
             break;
    }

        pros::delay(1);
        }
        
        CataMotor.move_velocity(0);
    }
    



void Catapult::CataSpinToPosition(int positiontype, int velocity){
    if (positiontype == 0){

        SpinToTarget(35200, 260, velocity);
    } 
    else if (positiontype == 1)
    {
        SpinToTarget(34000, 160, velocity);
    }
    

    else {
        SpinToTarget(260, 5, velocity);
    }
}

void Catapult::MatchLoadSkills(int range, double buffer){
    int now = 0;

    while (range < now){
        if (CataDistanceSensor.get() < buffer){
            pros::delay(100);
            CataSpinToPosition(0, 200);
            now += 1;
        }
        pros::delay(1);
    }
}

    
