#include "Pistons.hpp"
#include "Subsystems.hpp"
#include "autons.hpp"
#include "lemlib/asset.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pose.hpp"
#include "main.h"
#include "pros/rtos.hpp"

// Contains all of the code for the different autons for team 1228S

Catapult catapult(15, 14);
Intake intake(11);
Pistons pistons('H', 'G');


ASSET(FrontGoal_txt);
ASSET(PassBarrierTest_txt);

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

  lemchassis.moveToPoint(63, -4, 2300, true);
  lemchassis.turnToPID(180, 1000);

  pistons.launchWings(true);
  intake.toggle(true, false);

  lemchassis.moveToPoint(63, -42, 2000);

  lemchassis.moveToPoint(63, -8, 2000, false);
  intake.toggle(false, true);
  lemchassis.turnToPID(270, 1000);

  lemchassis.moveToPoint(21, -2, 2000);


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

void farSideAutonWin(){

GoalSide = false;
  
lemchassis.setPose(0, 0, 45);

lemchassis.moveToPose(-35, -15, 90, 2000, {.forwards = false, .chasePower = 18});

lemchassis.moveToPose(-5, -8, 45, 2000, {.forwards = true, .chasePower = 18});
lemchassis.waitUntilDone();
pistons.launchWings(true);

lemchassis.turnToPID(0, 2000);

pros::delay(200);
pistons.launchWings(false);

lemchassis.moveToPose(3, 35.5, 0, 2000, {.forwards = true, .chasePower = 18});
intake.toggle(true, false);
pistons.launchWings(true);

}

void farSideMatchLoad(){

lemchassis.setPose(0, 0, 45);

lemchassis.moveToPose(-35, -15, 90, 2000, {.forwards = false, .chasePower = 18});

lemchassis.moveToPose(-5, -8, 45, 2000, {.forwards = true, .chasePower = 18});
lemchassis.waitUntilDone();
pistons.launchWings(true);

lemchassis.turnToPID(0, 2000);

pros::delay(200);
pistons.launchWings(false);

lemchassis.moveToPose(3, 35.5, 0, 2000, {.forwards = true, .chasePower = 18});
intake.toggle(true, false);

lemchassis.moveToPoint(-5, -8, 2000, false);

lemchassis.turnToPID(165, 1000);

intake.toggle(true, true);
}


void goalSide10Point(){
 lemchassis.setPose(0, 0, 0);

 lemchassis.moveToPoint(0, 50, 2000, false);
 lemchassis.moveToPoint(0, 0, 2000, false)
;
}

void Skills(){
  lemchassis.setPose(-38,56,0);

pistons.launchWings(true);
pistons.launchWings(false);

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



lemchassis.setPose(-59,27,0);

lemchassis.follow(FrontGoal_txt, 10000, 22, false, true);

lemchassis.turnToPID(90, 1000);
pistons.launchWings(true);

lemchassis.setPose(0, 0, 0);
lemchassis.moveToPoint(0, 30, 2000, false);
pistons.launchWings(false);

lemchassis.moveToPoint(0, 20, 2000, false, 100, false);

pistons.launchWings(true);
lemchassis.moveToPoint(0, 40, 2000, false);
pistons.launchWings(false);

pistons.launchWings(true);

pistons.launchWings(true);

lemchassis.moveToPoint(5, 15, 2000, false);
lemchassis.moveToPoint(5, 40, 2000, false);
pistons.launchWings(false);


lemchassis.moveToPoint(10, 5, 2000, false);

pistons.launchWings(true);


}

void driverSkills(){
  lemchassis.setPose(0, 0, 0);

  pistons.launchWings(true);
  lemchassis.moveToPose(-1, 10, 18, 2000, {.forwards = true, .chasePower = 10, .lead = 0.2});

  //pros::Task::delay(1000);

  const int timeout = 29000;
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
  lemchassis.moveToPose(-31, 23, 90, 2500, {.forwards = false,  12});

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

  lemchassis.moveToPoint(-45, -63, 2000, true);
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
  lemchassis.moveToPose(-31, -75, 270 , 2000, {.forwards = false, .chasePower = 18});

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
