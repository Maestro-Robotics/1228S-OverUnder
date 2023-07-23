#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>
#include "Catapult.hpp"
#include "main.h"
#include "pros/llemu.hpp"
#include "pros/rtos.hpp"


Catapult::Catapult(int8_t const CataPort, uint8_t const RotationPort) : CataMotor{ CataPort }, CataRotationSensor{ RotationPort } {
    std::printf("constructor");
}

void Catapult::SpinToTarget(int targetAngle, int angleRange) {
    const int timeout = 3000; // set timeout to 3 seconds
    uint32_t start_time = pros::millis();

    //std::printf("abs = %d\n",std::abs(CataRotationSensor.get_angle() - targetAngle));

     CataMotor.move_velocity(150);

    // Loop until the rotation sensor reaches the desired range of the target angle
    while (std::abs(CataRotationSensor.get_angle() - targetAngle) > angleRange) {

         //std::printf("get_angle() : %d\n",CataRotationSensor.get_angle());
         //std::printf("abs = %d\n",std::abs(CataRotationSensor.get_angle() - targetAngle));
 
        if (pros::millis() - start_time > timeout) {
            std::printf("Spin motor timeout reached");
            break;

        }
    
    }
    CataMotor.move_velocity(0);
}


void Catapult::CataSpinToPosition(int positiontype){
    if (positiontype == 0){
        CataMotor.move_velocity(150);
        pros::Task::delay(300);
        SpinToTarget(35400, 250);
    }

    else {
        SpinToTarget(260, 5);
    }
}

    
