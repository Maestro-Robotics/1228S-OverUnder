#include "Pistons.hpp"
#include "Subsystems.hpp"
#include "main.h"
#include "pros/rtos.hpp"

// Contains all of the code for the different autons for team 1228S

Catapult catapult(15, 14);
Intake intake(11);
Pistons pistons('H');


ASSET(FrontGoal_txt);

void twentyFiveGoal(){
  
lemchassis.setPose(0, 0, 0);

pistons.launchWings(true);

lemchassis.turnToPID(345, 200, false);
pistons.launchWings(false);

lemchassis.moveToPID(-14, 47, 1500, true);
lemchassis.waitUntilDist(1);
intake.toggle(false, false);
catapult.cataSpinToPosition(0, -200);
lemchassis.waitUntilDist(1000);

lemchassis.turnToPID(90, 500);
intake.toggle(true, false);
pros::delay(200);

lemchassis.turnToPID(260, 500);
lemchassis.moveToPID(-30, 52, 1000, true);
lemchassis.waitUntilDist(1);
intake.toggle(false, false);
lemchassis.waitUntilDist(10000);

lemchassis.moveToPID(-27, 51, 500, false);

lemchassis.turnToPID(90, 500);
lemchassis.moveToPID(3, 49, 2000, true);
lemchassis.waitUntilDist(5);
pistons.launchWings(true);
lemchassis.waitUntilDist(10000);

lemchassis.moveToPID(-14, 49, 2000, false);
pistons.launchWings(false);

lemchassis.turnToPID(245, 500);
lemchassis.moveToPID(-20, 37, 1000, false);
lemchassis.moveToPID(-12, 43, 1000, false);

lemchassis.turnToPID(125, 500);
intake.toggle(true, false);
lemchassis.turnToPID(145, 200);

lemchassis.moveToPID(15, -1, 1000, true);
lemchassis.waitUntilDist(5);
intake.toggle(false, true);
lemchassis.waitUntilDist(1000);

lemchassis.turnToPID(250, 1000);
intake.toggle(false, false);

lemchassis.setPose(lemchassis.getPose().x, lemchassis.getPose().y, 270);

lemchassis.moveToPID(-13, -1, 1000, false);

lemchassis.moveToPID(14, -7, 1000, false);
lemchassis.turnToPID(84, 1000);

pistons.launchWings(true);
lemchassis.moveTo(44, 30, 0, 2000, true, true, 12);
lemchassis.waitUntilDist(15);
pistons.launchWings(false);
lemchassis.waitUntilDist(10000);
}

void testGoal(){
    
lemchassis.setPose(0, 0, 0);

pistons.launchWings(true);

lemchassis.turnToPID(345, 200, false);
pistons.launchWings(false);

lemchassis.moveToPID(-14, 47, 1500, true);
lemchassis.waitUntilDist(1);
intake.toggle(false, false);
catapult.cataSpinToPosition(0, -200);
lemchassis.waitUntilDist(1000);

lemchassis.turnToPID(90, 500);
intake.toggle(true, false);
pros::delay(200);

lemchassis.turnToPID(260, 500);
lemchassis.moveToPID(-30, 52, 1000, true);
lemchassis.waitUntilDist(1);
intake.toggle(false, false);
lemchassis.waitUntilDist(10000);

lemchassis.moveToPID(-27, 51, 500, false);

lemchassis.turnToPID(90, 500);
lemchassis.moveToPID(3, 49, 2000, true);
lemchassis.waitUntilDist(5);
pistons.launchWings(true);
lemchassis.waitUntilDist(10000);

lemchassis.moveToPID(-14, 49, 2000, false);
pistons.launchWings(false);

lemchassis.turnToPID(245, 500);
lemchassis.moveToPID(-20, 37, 1000, false);
lemchassis.moveToPID(-12, 43, 1000, false);

lemchassis.turnToPID(125, 500);

lemchassis.moveToPID(15, -1, 1000, false);

lemchassis.turnToPID(90, 1000);

pistons.launchWings(true);
lemchassis.moveTo(44, 30, 0, 2000, true, true, 12);
lemchassis.waitUntilDist(15);
pistons.launchWings(false);
lemchassis.waitUntilDist(10000);

}

void disruptClose(){
  lemchassis.moveToPID(0, 38, 1000, false);
  lemchassis.turnToPID(270, 1000);
  intake.toggle(true, false);
  pistons.launchWings(true);

  lemchassis.moveToPID(22, 38, 1000, false);
  pistons.launchWings(false);

  lemchassis.moveToPID(-13, 38, 2000, false);
  lemchassis.moveToPID(13, 38, 2000, false);
  lemchassis.turnToPID(330, 1000);



}

void farSideAutonWin(){

GoalSide = false;

matchLoadAuto = true;
  
lemchassis.setPose(0, 0, 45);

lemchassis.moveTo(-32, -15, 90, 2000, false, false, 18);

lemchassis.moveTo(-5, -8, 45, 2000, false, true, 15);

pistons.launchWings(true);
lemchassis.turnToPID(0, 2000, false);

pros::delay(200);
pistons.launchWings(false);

lemchassis.moveTo(3, 35, 0, 2000, false, true, 12);
intake.toggle(true, false);

}

void farSideMatchLoad(){

GoalSide = false;

matchLoadAuto = true;
  
lemchassis.setPose(0, 0, 45);

lemchassis.moveTo(-32, -15, 90, 2000, false, false, 18);

lemchassis.moveTo(-5, -8, 45, 2000, false, true, 15);

pistons.launchWings(true);
lemchassis.turnToPID(0, 2000, false);

pros::delay(200);
pistons.launchWings(false);

lemchassis.moveTo(3, 35, 0, 2000, false, true, 12);
intake.toggle(true, false);

lemchassis.moveToPID(-5, -8, 2000, false);

lemchassis.turnToPID(165, 1000);

intake.toggle(true, true);
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
lemchassis.moveTo(-37, 66, 18, 2000, false, true, 10, 0.2);
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

lemchassis.moveTo(-68, 79, 90, 2000, false, false, 12);


lemchassis.setPose(-59,27,0);

lemchassis.follow(FrontGoal_txt, 10000, 20, false, true);

lemchassis.turnToPID(90, 1000);
pistons.launchWings(true);

lemchassis.setPose(0, 0, 0);
lemchassis.moveToPID(0, 30, 2000, false);
pistons.launchWings(false);

lemchassis.moveToPID(0, 20, 2000, false, 100, false);

pistons.launchWings(true);
lemchassis.moveToPID(0, 40, 2000, false);
pistons.launchWings(false);

lemchassis.moveTo(-20, 5, 0, 3000, false, true, 12, 0.2, 80);
pistons.launchWings(true);

lemchassis.moveToPID(10, 5, 3000, false, 100);
lemchassis.moveToPID(10, 30, 3000, false);
pistons.launchWings(true);

lemchassis.moveToPID(10, 15, 2000, false);
lemchassis.moveToPID(10, 40, 2000, false);
pistons.launchWings(false);

lemchassis.moveToPID(10, 5, 2000, false);

lemchassis.moveTo(55, 40, 180, 2000, false, true, 12, 0.2, 80);
pistons.launchWings(true);

lemchassis.moveTo(0, 50, 180, 1500, false, true, 12);

lemchassis.moveTo(55, 40, 180, 2000, false, false, 12);

lemchassis.moveTo(0, 50, 180, 1500, false, true, 12);

lemchassis.moveTo(55, 40, 180, 2000, false, false, 12);
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



