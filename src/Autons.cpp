#include "Pistons.hpp"
#include "Subsystems.hpp"
#include "autons.hpp"
#include "lemlib/asset.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pose.hpp"
#include "main.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

// Contains all of the code for the different autons for team 1228S

Catapult catapult(15, 17);
Intake intake(11);
Pistons pistons('H', 'G');
pros::Optical optSen(18);

void twentyFiveGoal(){
  lemchassis.setPose(0, 0, 0);

  intake.toggle(false, false);

  lemchassis.moveToPoint(0, 3, 2000);
  lemchassis.waitUntil(2);
  lemchassis.cancelMotion();

  lemchassis.moveToPoint(0, -7, 2000, false);
  lemchassis.waitUntil(5);
  lemchassis.cancelMotion();

  lemchassis.moveToPose(32, -50, 180, 2500, {.forwards = false, .chasePower = 18, .minSpeed = 127});
  lemchassis.waitUntil(55);
  lemchassis.cancelMotion();

  lemchassis.moveToPose(7, -35, 319, 2500, {.forwards = true, .chasePower = 18, .minSpeed = 127});
  lemchassis.waitUntil(15);
  lemchassis.cancelMotion();

  intake.toggle(false, true);

  lemchassis.turnToPID(140, 1000);
  lemchassis.moveToPoint(12, -51, 2000);
  pistons.launchWings(true);
  lemchassis.turnToPID(90, 1000);
  pistons.launchWings(false);

  intake.toggle(true, false);

  lemchassis.moveToPose(48, -56, 90, 1000, {.forwards = true, .chasePower = 15, .minSpeed = 127});
  lemchassis.moveToPoint(23, -53, 1000, false);
  lemchassis.moveToPoint(41, -53, 1000);

  lemchassis.moveToPose(13, -40, 100, 2500, {.forwards = false, .chasePower = 18, .minSpeed = 127});

  intake.toggle(false, false);

  lemchassis.turnToPID(50, 1000);

  lemchassis.moveToPose(49, 1, 0, 2500, {.forwards = true, .chasePower = 18, .minSpeed = 127});
  lemchassis.waitUntil(38);
  lemchassis.cancelMotion();

  lemchassis.moveToPoint(49, -18, 2000, false);
  lemchassis.waitUntil(8);
  lemchassis.cancelMotion();

  lemchassis.turnToPID(162, 1000);
  intake.toggle(true, false);
  pros::Task::delay(200);

  lemchassis.turnTo(63, -4, 1000);
  intake.toggle(false, false);

  lemchassis.moveToPoint(63, -4, 2000);

  lemchassis.turnToPID(180, 1000);

  pistons.launchWings(true);
  lemchassis.moveToPoint(69, -38, 3000);
  lemchassis.waitUntil(10);
  intake.toggle(true, false);

}

void testGoal(){
  lemchassis.setPose(0, 0, 0);

  intake.toggle(false, false);
  lemchassis.moveToPoint(0, 33, 2000);
  lemchassis.waitUntil(30);
  lemchassis.cancelMotion();

  lemchassis.moveToPoint(0, 25, 2000, false);
  lemchassis.waitUntil(20);
  lemchassis.cancelMotion();

  lemchassis.turnTo(0, 0, 800);

  lemchassis.moveToPoint(1, 5, 1000);
  lemchassis.swingToAngle(133, true, 500);

  lemchassis.moveToPoint(7, -7, 1000);
  lemchassis.waitUntilDone();
  pistons.launchWings(true);

  lemchassis.turnToPID(90, 550);
  lemchassis.moveToPose(21, -13, 90, 2000, {.chasePower = 12, .minSpeed = 127});
  lemchassis.waitUntilDone();
  pistons.launchWings(false);
  intake.toggle(true, false);
  lemchassis.moveToPoint(36, -15, 1000);

  lemchassis.moveToPose(3, 3, 130, 1200, {.forwards = false, .chasePower = 18});

  lemchassis.swingToAngle(58, true, 400);
  lemchassis.waitUntilDone();
  intake.toggle(false, false);


  lemchassis.moveToPose(57, 39, 45, 2000, {.forwards = true, .chasePower = 18});
  lemchassis.turnToPID(180, 500);
  lemchassis.waitUntilDone();
  pistons.launchWings(true);
  intake.toggle(true, false);

  lemchassis.moveToPoint(61, 5, 2000);

  lemchassis.moveToPoint(61, 25, 1000, false);
  lemchassis.waitUntilDone();
  pistons.launchWings(false);

  lemchassis.swingToAngle(347, false, 500);
  lemchassis.waitUntilDone();
  intake.toggle(false, false);

  lemchassis.moveToPoint(39, 39, 2000);
  lemchassis.swingToAngle(180, false, 500);
  lemchassis.waitUntilDone();
  pistons.launchWings(true);

  lemchassis.moveToPoint(55, 5, 1500);
  lemchassis.waitUntil(15);
  intake.toggle(true, false);

  lemchassis.moveToPoint(55, 30, 1000, false);

  }

void disruptClose(){
  lemchassis.moveToPoint(0, 38, 1000, false);
  lemchassis.turnToPID(270, 1000);
  intake.toggle(true, false);
  pistons.launchWings(true);

  lemchassis.moveToPoint(22, 38, 1000, false);
  pistons.launchWings(false);

  lemchassis.moveToPoint(-13, 38, 2000, false);
  lemchassis.moveToPoint(13, 38, 2000, false);
  lemchassis.turnToPID(330, 1000);



}

void closeSideAWP(){
  GoalSide = false;
    
  lemchassis.setPose(0, 0, 45);

  lemchassis.moveToPose(-27, -15, 90, 2000, {.forwards = false, .chasePower = 18, .minSpeed = 110});

  lemchassis.moveToPose(-5, -8, 45, 2000, {.forwards = true, .chasePower = 18});
  lemchassis.waitUntilDone();
  pistons.launchWings(true);

  lemchassis.turnToPID(0, 800);

  // lemchassis.setPose(-50, -52, 90);
  intake.toggle(false, false);
  pistons.launchWings(false);

  lemchassis.moveToPose(-50, 20, -90, 2500, {.chasePower = 18, .minSpeed = 110});

  lemchassis.moveToPose(-15, 1, -45, 2000, {.forwards = false, .chasePower = 18});
  lemchassis.waitUntilDone();
  pistons.launchWings(true);
  lemchassis.turnToPID(53, 1000);
  intake.toggle(true, false);

  lemchassis.moveToPose(2, 35.5, 0, 2000, {.forwards = true, .chasePower = 18});
  while (optSen.get_proximity() <= 200) {
    pros::delay(5);
        }
  lemchassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  lemchassis.cancelMotion();
}

void closeSideElims(){
  GoalSide = false;
    
  lemchassis.setPose(0, 0, 45);

  lemchassis.moveToPose(-26.2, -15, 90, 2000, {.forwards = false, .chasePower = 18});

  lemchassis.moveToPose(-5, -8, 45, 2000, {.forwards = true, .chasePower = 18});
  lemchassis.waitUntilDone();
  pistons.launchWings(true);

  lemchassis.turnToPID(0, 800);

  intake.toggle(false, false);
  pistons.launchWings(false);

  lemchassis.moveToPose(-50, 20, -90, 2500, {.chasePower = 18, .minSpeed = 110});

  lemchassis.moveToPose(-15, 1, -45, 2000, {.forwards = false, .chasePower = 18});
  lemchassis.waitUntilDone();
  pistons.launchWings(true);
  lemchassis.turnToPID(53, 1000);
  intake.toggle(true, false);

  lemchassis.moveToPose(2, 37, 0, 2000, {.forwards = true, .chasePower = 18});
  while (optSen.get_proximity() <= 200) {
    pros::delay(5);
        }
  lemchassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  lemchassis.cancelMotion();

  pistons.launchWings(false);

  lemchassis.moveToPoint(-5, -8, 1500, false);
}

void preloadGoal(){
 lemchassis.setPose(0, 0, 0);

 lemchassis.moveToPoint(0, 50, 2000);
 lemchassis.moveToPoint(0, 0, 2000, false)
;
}

void Skills(){
  lemchassis.setPose(0, 0, 135);

  lemchassis.moveToPose(-35, 24, 90, 1500, {.forwards = false, .chasePower = 12, .minSpeed = 127});
  lemchassis.moveToPoint(-15, 17, 800);

  lemchassis.moveToPose(-8, 23, 20.5, 1500, {.forwards = true, .chasePower = 12});

  const int timeout = 29900;
  uint32_t start_time = pros::millis();
  lemchassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);

  catapult.cataMatchLoad(-200);
  while (true){
  if (pros::millis() - start_time > timeout) {
        std::printf("Spin motor timeout reached");
        catapult.cataSpinToPosition(0, -200);
        break;
    }
  }

  //pros::Task::delay(1000);

  lemchassis.moveToPose(4, -4, -33, 1500, {.forwards = false, .chasePower = 12, .minSpeed = 110});
  lemchassis.waitUntil(19);
  lemchassis.cancelMotion();

  lemchassis.turnToPID(0, 300);

  lemchassis.moveToPoint(0, -70, 3000, false);
  lemchassis.waitUntil(67);
  lemchassis.cancelMotion();

  lemchassis.turnToPID(45, 300);

  lemchassis.moveToPoint(-13, -89, 500, false);
  lemchassis.moveToPose(-43, -99, 90, 1500, {.forwards = false, .chasePower = 18, .lead = 0.3, .minSpeed = 127});

  lemchassis.moveToPoint(-13, -85, 1200);
  lemchassis.moveToPose(-43, -96, 90, 2000, {.forwards = false, .chasePower = 18, .lead = 0.3, .minSpeed = 127});

  lemchassis.moveToPoint(-30, -95, 1000);
  lemchassis.turnToPID(0, 600);
  pistons.launchWings(true);

  lemchassis.moveToPose(-49, -51, -90, 1800, {.forwards = true, .chasePower = 18, .maxSpeed = 90});
  lemchassis.turnToPID(-135, 300, false);

  intake.toggle(true, false);
  lemchassis.moveToPose(-56, -83, -180, 1800, {.forwards = true, .chasePower = 18, .minSpeed = 127}, false);
  pistons.launchWings(false);
  lemchassis.moveToPoint(-56, -63, 800, false, 127, false);
  pistons.launchWings(true);
  lemchassis.moveToPoint(-56 , -83, 1000, true, 127, false);
  pistons.launchWings(false);

  lemchassis.moveToPose(-44, -50, -90, 1800, {.forwards = false, .chasePower = 18, .maxSpeed = 127}, false);
  pistons.launchWings(true);
  lemchassis.moveToPose(-90, -42, -217, 2500, { .chasePower = 18}, false);
  intake.toggle(true, true);

  lemchassis.moveToPose(-69, -87, -180, 1800, {.forwards = true, .chasePower = 18, .minSpeed = 127}, false);
  pistons.launchWings(false);
  lemchassis.moveToPose(-66, -53, -180, 800, {.forwards = false, .chasePower = 12, .minSpeed = 127});
  pistons.launchWings(true);
  lemchassis.moveToPoint(-66 , -83, 1000, true, 127, false);
  pistons.launchWings(false);

  lemchassis.moveToPoint(-69, -51, 1400, false);
  lemchassis.turnToPID(250, 600);
  pistons.launchWings(true);

  lemchassis.moveToPose(-110, -65, 270, 2000, {.chasePower = 18, .minSpeed = 100}, false);
  // pistons.launchWings(true);

  // lemchassis.moveToPose(-100, -78, -114, 2000, {.chasePower = 18});
  // lemchassis.waitUntil(39);
  // intake.toggle(false, true);

  lemchassis.swingToAngle(140, true, 600, false, 127, false);
  pistons.launchWings(true);

  // // lemchassis.moveToPose(-122, -57, 0, 1000, {.chasePower = 18});
  // // lemchassis.moveToPoint(-120, -70, 1000, false);

  // // lemchassis.turnToPID(-30, 800);

  lemchassis.moveToPose(-80, -95, 90, 2000, {.chasePower = 12, .minSpeed = 127});
  lemchassis.waitUntil(15);
  pistons.launchWings(false);
  intake.toggle(true, false);

  //lemchassis.swingToAngle(270, true, 2000);
  lemchassis.moveToPose(-117, -87, -40, 1000, {.forwards = false, .chasePower = 18, .minSpeed = 127}, false);
  lemchassis.moveToPose(-80, -95, 90, 2000, {.chasePower = 12, .minSpeed = 127});
  //lemchassis.moveToPose(-81, -106, -90, 2000, {.chasePower = 18, .minSpeed = 127});
  
  lemchassis.moveToPose(-117, -87, -40, 1000, {.forwards = false, .chasePower = 18, .minSpeed = 127});

  lemchassis.moveToPose(-80, -95, -90, 2000, {.chasePower = 18, .minSpeed = 127});
  lemchassis.moveToPose(-117, -87, -40, 1000, {.forwards = false, .chasePower = 18, .minSpeed = 127});





  





}

void driverSkills(){
  lemchassis.setPose(0, 0, 0);

  pistons.launchWings(true);
  lemchassis.moveToPose(-1, 10, 21, 2000, {.forwards = true, .chasePower = 10, .lead = 0.3});

  //pros::Task::delay(1000);

  const int timeout = 30000;
  uint32_t start_time = pros::millis();


  catapult.cataMatchLoad(-200);
  while (true){
  if (pros::millis() - start_time > timeout) {
        std::printf("Spin motor timeout reached");
        catapult.cataSpinToPosition(0, -200);
        break;
    }
  }

  pistons.launchWings(false);
  lemchassis.moveToPose(-31, 23, 90, 2500, {.forwards = false, 12});

  lemchassis.moveToPose(6.89, -13.476, 180, 2000, {.forwards = true, .chasePower = 15});
  lemchassis.waitUntil(26);
  lemchassis.cancelMotion();

  lemchassis.moveToPoint(6.89, -67.476, 2000, true);
  lemchassis.waitUntil(25);
  lemchassis.cancelMotion();

  pistons.launchWings(true);

  lemchassis.moveToPose(-34.57, -105, 270, 2500, {.forwards = true, .chasePower = 15, .minSpeed = 127});
  lemchassis.waitUntil(60);
  pistons.launchWings(false);

  intake.toggle(true, false);

  lemchassis.moveToPoint(-8, -105, 2000, false);
  lemchassis.waitUntil(22);
  lemchassis.cancelMotion();

  lemchassis.moveToPoint(-35, -105, 1300, true);
  lemchassis.waitUntil(25);
  lemchassis.cancelMotion();

  lemchassis.moveToPoint(-8, -105, 1500, false);
  lemchassis.waitUntil(22);
  lemchassis.cancelMotion();
  
  // lemchassis.moveToPoint(-35, -105, 2000, true);
  // lemchassis.waitUntil(25);
  // lemchassis.cancelMotion();

  // lemchassis.moveToPoint(-8, -105, 1500, false);
  // lemchassis.waitUntil(22);
  // lemchassis.cancelMotion();

  lemchassis.turnTo(-32, -54, 1000);

  lemchassis.moveToPoint(-32, -54, 2000, true);
  lemchassis.waitUntil(15);
  pistons.launchWings(true);
  lemchassis.waitUntil(30);
  lemchassis.cancelMotion();

  lemchassis.turnToPID(270, 1000);

  lemchassis.moveToPoint(-45, -73, 2000, true);
  lemchassis.waitUntil(15);
  lemchassis.cancelMotion();

  lemchassis.turnToPID(180, 1000);

  lemchassis.moveToPose(-43, -120, 180 , 2500, {.forwards = true, .chasePower = 18, .minSpeed = 127});
  // lemchassis.waitUntilDone();
  // pistons.launchWings(false);

  lemchassis.moveToPose(-43, -73, 180 , 2000, {.forwards = false, .chasePower = 18, .minSpeed = 127});
  lemchassis.waitUntil(20);
  lemchassis.cancelMotion();

  // lemchassis.moveToPose(-43, -105, 180 , 2000, {.forwards = true, .chasePower = 18, .minSpeed = 127});
  // lemchassis.waitUntil(65);
  // lemchassis.cancelMotion();

  //pistons.launchWings(false);
  lemchassis.moveToPose(-31, -85, 270 , 2000, {.forwards = false, .chasePower = 18});

  lemchassis.moveToPoint(-54, -75, 2000, true);
  lemchassis.waitUntil(15);
  lemchassis.cancelMotion();

  pistons.launchWings(true);
  lemchassis.turnToPID(180, 1000);

  lemchassis.moveToPose(-54, -120, 180 , 2000, {.forwards = true, .chasePower = 18, .minSpeed = 127});
  // lemchassis.waitUntilDone();
  // pistons.launchWings(false);

  lemchassis.moveToPose(-54, -73, 180 , 2000, {.forwards = false, .chasePower = 18, .minSpeed = 127});
  lemchassis.waitUntil(30);
  lemchassis.cancelMotion();

  // lemchassis.moveToPose(-57, -105, 180 , 2000, {.forwards = true, .chasePower = 18, .minSpeed = 127});
  // lemchassis.waitUntil(65);
  // lemchassis.cancelMotion();

  lemchassis.moveToPose(-55, -65, 180 , 2000, {.forwards = false, .chasePower = 18, .minSpeed = 127});
  //pistons.launchWings(false);

  //intake.toggle(false, true);

  lemchassis.turnToPID(230, 1000);
  pistons.launchWings(true);

  lemchassis.moveToPoint(-105, -109, 2000, true);
  lemchassis.waitUntil(40);
  lemchassis.cancelMotion();
  pistons.launchWings(false);

  lemchassis.turnToPID(180, 1000);
  
  lemchassis.moveToPoint(-105, -81, 2000, false);
  lemchassis.waitUntil(20);
  lemchassis.cancelMotion();
  pistons.launchWings(true);

  lemchassis.moveToPose(-60, -123, 90, 2000, {.forwards = true, .chasePower = 15, .minSpeed = 127});

  intake.toggle(false, true);
  pistons.launchWings(false);

  lemchassis.moveToPose(-104, -91, 180, 2000, {.forwards = false, .chasePower = 15, .minSpeed = 127});
  lemchassis.waitUntil(50);
  lemchassis.cancelMotion();

  pistons.launchWings(true);
  lemchassis.moveToPose(-60, -125, 90, 3000, {.forwards = true, .chasePower = 18, .minSpeed = 127});

  lemchassis.moveToPose(-104, -91, 180, 2000, {.forwards = false, .chasePower = 15, .minSpeed = 127});

  

}
