#include "main.h"


 Catapult catapult(15, 14);
 Intake intake(11);
 Pistons pistons('H');

 
ASSET(FrontGoal_txt);
ASSET(PassBarrier_txt);

void lemGoalSideTest(){

    pistons.launchWings(true);
  lemchassis.moveTo(-30, 14, 270, 2000, false, true, 10);
  pistons.launchWings(false);
  lemchassis.moveTo(-30, 10, 270, 2000, false, true, 10);
  pistons.InitialLaunch(true);
  intake.toggle(false, false);
  lemchassis.moveTo(-33, -30, 220, 2000, false, true, 10);
  intake.toggle(false, false);
  lemchassis.moveTo(-65, -20, 0, 2000, false, true, 10);
  pistons.InitialLaunch(false);
  pistons.launchWings(true);
  intake.toggle(true, false);
  lemchassis.moveTo(-65, 10, 0, 1500, false, true, 10);
  intake.toggle(false, true);
  pistons.InitialLaunch(true);
  pistons.launchWings(false);
  intake.toggle(false, false);
  lemchassis.moveTo(-65, -30, 200, 2000, false, true, 10);
  lemchassis.moveTo(-65, -20, 0, 2000, false, true, 10);
  intake.toggle(false, true);
  pistons.InitialLaunch(false);
  pistons.launchWings(true);
  intake.toggle(true, false);
  lemchassis.moveTo(-65, 10, 0, 1500, false, true, 10);
  lemchassis.moveTo(-65, 15, 0, 500, false, true, 10);
  lemchassis.moveTo(0, -30, 180, 2000, false, true, 10);
}


void Skills(){
  
lemchassis.setPose(-38,56,0);

pistons.launchWings(true);
lemchassis.moveTo(-37, 66, 22, 2000, false, true, 7);
pistons.launchWings(false);

const int timeout = 32000;
uint32_t start_time = pros::millis();

pistons.InitialLaunch(true);

catapult.cataMatchLoad(-200);
while (true){
if (pros::millis() - start_time > timeout) {
      std::printf("Spin motor timeout reached");
      catapult.cataSpinToPosition(0, -200);
      break;
  }
}

lemchassis.moveTo(-61, 79, 90, 2000, false, false, 12);

pistons.InitialLaunch(true);

lemchassis.setPose(60, -35, 180);

lemchassis.follow(PassBarrier_txt, 10000, 12, false, true);

pistons.InitialLaunch(false);
pistons.launchWings(true);

lemchassis.follow(FrontGoal_txt, 3000, 10, false, true);

lemchassis.turnTo(-39, 0, 1000);

lemchassis.setPose(0, 0, 0);
lemchassis.moveTo(0, 50, 0, 2000, false, true, 9);
pistons.launchWings(false);

lemchassis.moveTo(20, 10, 0, 3000, false, true, 9);
pistons.launchWings(true);

lemchassis.moveTo(5, 50, 0, 2000, false, true, 12);
pistons.launchWings(false);

lemchassis.moveTo(-30, 10, 0, 3000, false, true, 9);
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


void farSideAutonWin(){
GoalSide = false;
  
lemchassis.setPose(0, 0, 0);

pistons.launchWings(true);

lemchassis.moveTo(7, 14, 90, 2000, false, true, 9);
pistons.launchWings(false);

lemchassis.moveTo(22, 15, 90, 2000, false, true, 12);

lemchassis.moveTo(7, -2, 108, 2000, false, false, 9);

lemchassis.moveTo(43, -12, 100, 2000, true, true, 9);
lemchassis.waitUntilDist(5);
pistons.InitialLaunch(true);
intake.toggle(false, false);
lemchassis.waitUntilDist(1000);

pros::delay(500);

lemchassis.turnTo(43, 0, 3000);
catapult.cataSpinToPosition(0, -200);

lemchassis.setPose(0,0,0);

lemchassis.moveTo(-9, 4, 135, 2000, false, false, 4);

lemchassis.moveTo(2, -8, 140, 2000, false, true, 2);

lemchassis.moveTo(-8, -2, 0, 2000, false, false, 4);

pros::delay(500);

lemchassis.turnTo(-6, 10, 2000);
catapult.cataSpinToPosition(0, -200);

lemchassis.moveTo(-48, 19, 270, 2000, true, true, 12);
lemchassis.waitUntilDist(5);
pistons.InitialLaunch(false);
intake.toggle(false, true);
lemchassis.waitUntilDist(10000);

lemchassis.moveTo(-50, -14, 180, 2000, false, true, 12);
}


void twentyFiveGoal(){

lemchassis.setPose(0, 0, 0);
 pistons.InitialLaunch(true);
 intake.toggle(false, false);

lemchassis.moveTo(30, -53, 270, 3000, true, false, 15);
lemchassis.waitUntilDist(15);
pistons.InitialLaunch(false);
lemchassis.waitUntilDist(1000);

lemchassis.setPose(0, 0, 0);

lemchassis.moveTo(0, 20, 0, 2000, false, true, 10);

intake.toggle(false, true);
lemchassis.turnTo(0, 0, 2000);
intake.toggle(true, false);
pistons.launchWings(true);
pros::delay(300);

lemchassis.moveTo(0, -20, 0, 1000, false, true, 15);

lemchassis.moveTo(24, 0, 144, 2000, true, true, 10);
lemchassis.waitUntilDist(10);
intake.toggle(true, true);
intake.toggle(false, false);
pistons.InitialLaunch(true);
pistons.launchWings(false);
lemchassis.waitUntilDist(1000);

lemchassis.moveTo(50, -26, 140, 2000, false, true, 15);

intake.toggle(false, true);

lemchassis.moveTo(19, -33, 270, 2000, true, true, 12);
lemchassis.waitUntilDist(15);
pistons.InitialLaunch(false);
intake.toggle(true, false);
pistons.launchWings(true);
lemchassis.waitUntilDist(10000);

intake.toggle(false, true);
pistons.launchWings(false);
pistons.InitialLaunch(true);
intake.toggle(false, false);

lemchassis.moveTo(47, -15, 58, 2000, false, true, 7);

lemchassis.moveTo(-7, 10, 270, 2000, false, true, 15);
pistons.InitialLaunch(false);

intake.toggle(false, true);

lemchassis.turnTo(-7, -2, 2000);
pistons.InitialLaunch(false);
intake.toggle(true, false);

lemchassis.moveTo(-7, -6, 180, 2000, false, true, 30);
}






