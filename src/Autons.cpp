#include "Pistons.hpp"
#include "Subsystems.hpp"
#include "main.h"
#include "pros/rtos.hpp"

// Contains all of the code for the different autons for team 1228S

Catapult catapult(15, 14);
Intake intake(11);
Pistons pistons('H');


ASSET(FrontGoal_txt);
ASSET(PassBarrier_txt);

void twentyFiveGoal(){
  
lemchassis.setPose(0, 0, 0);

pistons.launchWings(true);

lemchassis.turnToPID(347, 200, false);
pistons.launchWings(false);

lemchassis.moveToPID(-9, 44, 2000, true);
lemchassis.waitUntilDist(1);
intake.toggle(false, false);
catapult.cataSpinToPosition(0, -200);
lemchassis.waitUntilDist(1000);

lemchassis.turnToPID(90, 2000);
intake.toggle(true, false);
pros::delay(200);


lemchassis.moveTo(-33, 56, 270, 1500, true, true, 12, 0.2);
lemchassis.waitUntilDist(1);
intake.toggle(false, false);
lemchassis.waitUntilDist(10000);

lemchassis.turnToPID(90, 500);
lemchassis.moveToPID(10, 51, 1500, true);
lemchassis.waitUntilDist(5);
pistons.launchWings(true);
lemchassis.waitUntilDist(10000);

lemchassis.moveToPID(-10, 51, 300, false);

lemchassis.moveTo(-25, 32, 270, 2000, false, true, 12, 0.2);
lemchassis.moveToPID(-15, 32, 1000, false);

lemchassis.turnToPID(138, 1000);
intake.toggle(true, false);

lemchassis.moveToPID(8, 0, 1000, false);
lemchassis.moveToPID(-22, -5, 1000, true);
lemchassis.waitUntilDist(1);
intake.toggle(false, false);
lemchassis.waitUntilDist(10000);

lemchassis.turnToPID(90, 1000);
// pistons.launchWings(false);
// lemchassis.moveToPID(-11, 51, 1000, false);

// lemchassis.turnToPID(232, 300, false);
// lemchassis.moveToPID(-28, 36, 1000, true);
// lemchassis.waitUntilDist(1);
// intake.toggle(false, false);
// lemchassis.waitUntilDist(1000);

// lemchassis.turnToPID(69, 400);
// lemchassis.moveToPID(1, 49, 1000, true);
// lemchassis.waitUntilDist(1);
// intake.toggle(true, false);
// lemchassis.waitUntilDist(1000);

// lemchassis.moveToPID(-12, 48, 1000, false);
// lemchassis.turnToPID(152, 300);
// intake.toggle(false, true);

// lemchassis.moveTo(-2, -15, 270, 1000, false, true, 12);
// lemchassis.moveToPID(-26, 0, 1000, true);
// lemchassis.waitUntilDist(1);
// intake.toggle(false, false);
// lemchassis.waitUntilDist(1000);

// lemchassis.moveToPID(0, 0, 1000, false);
// lemchassis.turnToPID(66, 400, false);
// pistons.launchWings(true);

// lemchassis.moveTo(17, 31, 0, 1000, true, true, 12);
// lemchassis.waitUntilDist(25);
// pistons.launchWings(false);
// intake.toggle(true, false);
// lemchassis.waitUntilDist(1000);

// lemchassis.moveToPID(17, 35, 200, false);

// lemchassis.moveToPID(17, 27, 1000, false);
// intake.toggle(false, true);

// lemchassis.moveTo(-5, 0, 90, 1500, true, false, 25);
// lemchassis.waitUntilDist(5);
// pistons.launchBlocker(true);
// lemchassis.waitUntilDist(1000);

// lemchassis.moveToPID(-31, 0, 2000, false);
// pistons.launchBlocker(true);

}

void farSideAutonWin(){

GoalSide = false;
  
lemchassis.setPose(0, 0, 45);

pistons.launchWings(true);

lemchassis.moveToPID(7, 7, 2000, false);
lemchassis.swingTo(false, 90, 1000, false, false, 200, false);
pistons.launchWings(false);
lemchassis.moveToPID(37, 16, 2000, false);
lemchassis.moveTo(8, 1, 45, 2000, false, false, 12);

lemchassis.turnToPID(112, 2000);
lemchassis.moveToPID(53, -13, 2000, true);
lemchassis.waitUntilDist(10);
intake.toggle(false, false);
lemchassis.waitUntilDist(1000);

lemchassis.swingTo(false, 0, 1000, false, false, 200, false);
lemchassis.moveToPID(39, -17, 1000, false);
lemchassis.turnToPID(0, 1000);
catapult.cataSpinToPosition(0, -200);
intake.toggle(false, true);

lemchassis.moveTo(-20, 0, 270, 1000, false, true, 9);
lemchassis.turnToPID(180, 1000);
lemchassis.moveToPID(11, -43, 2000, true);
lemchassis.waitUntilDist(10);
intake.toggle(true, false);
lemchassis.waitUntilDist(1000);
pistons.launchBlocker(true);
}

void farSideMatchLoad(){

GoalSide = false;
matchLoadAuto = true;
  
lemchassis.setPose(0, 0, 45);

pistons.launchWings(true);

lemchassis.moveToPID(7, 7, 2000, false);
lemchassis.swingTo(false, 90, 1000, false, false, 200, false);
pistons.launchWings(false);
lemchassis.moveToPID(33, 16, 2000, false);
lemchassis.moveTo(8, 1, 45, 2000, false, false, 15);

lemchassis.turnToPID(112, 2000);
lemchassis.moveToPID(53, -13, 2000, true);
lemchassis.waitUntilDist(10);
intake.toggle(false, false);
lemchassis.waitUntilDist(1000);

lemchassis.swingTo(false, 0, 1000, false, false, 200, false);
lemchassis.moveToPID(39, -17, 1000, false);
lemchassis.turnToPID(0, 1000);
catapult.cataSpinToPosition(0, -200);
intake.toggle(false, true);

lemchassis.moveTo(14, 17, 340, 2000, false, true, 12);
}

void farSideElims(){

GoalSide = false;
matchLoadAuto = true;
  
lemchassis.setPose(0, 0, 0);
pistons.launchWings(true);

lemchassis.turnToPID(13, 200);
pistons.launchWings(false);

lemchassis.moveToPID(10, 45, 2000, true);
lemchassis.waitUntilDist(1);
catapult.cataSpinToPosition(0, -200);
intake.toggle(false, false);
lemchassis.waitUntilDist(1000);

lemchassis.swingTo(false, 270, 1000, false, false, 200, false);
lemchassis.turnToPID(270, 200);
lemchassis.moveToPID(10, 33, 1000, false);
catapult.cataSpinToPosition(0, -200);
intake.toggle(false, true);

lemchassis.turnToPID(224, 1000);
lemchassis.moveToPID(-16, 5, 2000, false);
lemchassis.turnToPID(133, 1000);
lemchassis.moveToPID(-25, 22, 2000, false);
lemchassis.moveToPID(-20, 10, 2000, false);
lemchassis.turnToPID(245, 1000);
lemchassis.moveToPID(-19, 7, 2000, false);

}

void goalSide10Point(){
 lemchassis.setPose(0, 0, 0);

 lemchassis.moveToPID(0, 50, 2000, false);
 lemchassis.moveToPID(0, 0, 2000, false)
;
// intake.toggle(false, false);

// lemchassis.moveTo(0, 3, 0, 2000, false, true, 2);

// lemchassis.moveTo(32, -50, 270, 2000, false, false, 9);

// lemchassis.setPose(0, 0, 0);

// lemchassis.moveTo(0, 10, 0, 2000, false, true, 10);

// pros::delay(100);

// lemchassis.moveToPID(0, -10, 2000, false);
// lemchassis.turnToPID(180, 2000);

// intake.toggle(true, false);

// lemchassis.moveToPID(0, -10, 2000, false);

// intake.toggle(false, true);
}

void Skills(){
lemchassis.setPose(-38,56,0);

pistons.launchWings(true);
lemchassis.moveTo(-37, 66, 18, 2000, false, true, 10);
pistons.launchWings(false);

const int timeout = 32000;
uint32_t start_time = pros::millis();


catapult.cataMatchLoad(-200);
while (true){
if (pros::millis() - start_time > timeout) {
      std::printf("Spin motor timeout reached");
      catapult.cataSpinToPosition(0, -200);
      break;
  }
}

lemchassis.moveTo(-61, 79, 90, 2000, false, false, 12);


lemchassis.setPose(60, -35, 180);

lemchassis.follow(PassBarrier_txt, 10000, 12, false, true);

lemchassis.follow(FrontGoal_txt, 3000, 10, false, true);

lemchassis.turnTo(-39, 0, 1000);
pistons.launchWings(true);

lemchassis.setPose(0, 0, 0);
lemchassis.moveToPID(0, 50, 2000, false);
pistons.launchWings(false);

lemchassis.moveTo(20, 10, 0, 3000, false, true, 9);
pistons.launchWings(true);

lemchassis.moveTo(5, 50, 315, 2000, false, true, 12);
pistons.launchWings(false);

lemchassis.moveToPID(-30, 10, 3000, false);
pistons.launchWings(true);

lemchassis.moveTo(-15, 50, 0, 2000, false, true, 12);
pistons.launchWings(false);

lemchassis.moveTo(-40, 5, 315, 3000, false, true, 9);

lemchassis.moveTo(-61, 30, 220, 2000, false, true, 10);

lemchassis.moveTo(-30, 49, 270, 2000, false, false, 30);

lemchassis.moveTo(-61, 30, 220, 2000, false, true, 10);

lemchassis.moveTo(-30, 49, 270, 2000, false, false, 30);

lemchassis.moveTo(-61, 30, 220, 2000, false, true, 10);

lemchassis.moveTo(-30, 49, 270, 2000, false, false, 30);
}

void driverSkills() {
  lemchassis.setPose(-38,56,0);

pistons.launchWings(true);
lemchassis.moveTo(-37, 66, 22, 2000, false, true, 7);
pistons.launchWings(false);

const int timeout = 32000;
uint32_t start_time = pros::millis();


catapult.cataMatchLoad(-200);
while (true){
if (pros::millis() - start_time > timeout) {
      std::printf("Spin motor timeout reached");
      catapult.cataSpinToPosition(0, -200);
      break;
  }
}

lemchassis.moveTo(-61, 79, 90, 2000, false, false, 12);


opcontrol();
}

void lemGoalSideTest(){

  lemchassis.setPose(0, 0, 0);

  intake.toggle(false, false);

  lemchassis.moveTo(30, -46, 270, 3000, true, false, 15);
  lemchassis.waitUntilDist(15);
  lemchassis.waitUntilDist(1000);

  lemchassis.setPose(0, 0, 0);

  lemchassis.moveTo(0, 10, 0, 2000, false, true, 10);

  intake.toggle(false, true);
  lemchassis.turnTo(0, 0, 2000);
  intake.toggle(true, false);
  pros::delay(300);

  lemchassis.moveTo(0, -10, 0, 1000, false, true, 15);

  lemchassis.moveTo(24, 0, 144, 2000, true, true, 10);
  lemchassis.waitUntilDist(10);
  intake.toggle(true, true);
  intake.toggle(false, false);
  lemchassis.waitUntilDist(1000);

  lemchassis.moveTo(50, -26, 140, 2000, false, true, 15);

  lemchassis.turnTo(36, -28, 2000);
  intake.toggle(true, true);
  intake.toggle(true, false);

  lemchassis.moveTo(19, -33, 270, 2000, true, true, 12);
  lemchassis.waitUntilDist(15);
  intake.toggle(true, false);
  pistons.launchWings(true);
  lemchassis.waitUntilDist(10000);


  lemchassis.moveTo(45, -17, 47, 2000, true, true, 7);
  lemchassis.waitUntilDist(5);
  intake.toggle(true, true);
  pistons.launchWings(false);
  intake.toggle(false, false);
  lemchassis.waitUntilDist(1000);

  lemchassis.moveTo(19, -33, 270, 2000, true, true, 12);
  lemchassis.waitUntilDist(15);
  intake.toggle(true, false);
  intake.toggle(true, false);
  pistons.launchWings(true);
  lemchassis.waitUntilDist(1000);


  // lemchassis.moveTo(-7, 10, 270, 2000, false, true, 15);
  // pistons.InitialLaunch(false);

  // intake.toggle(false, true);

  // lemchassis.turnTo(-7, -2, 2000);
  // pistons.InitialLaunch(false);
  // intake.toggle(true, false);

  // lemchassis.moveTo(-7, -6, 180, 2000, false, true, 30);
}




