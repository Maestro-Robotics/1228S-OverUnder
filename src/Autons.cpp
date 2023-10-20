#include "autons.hpp"
#include "main.h"
#include <sys/types.h>
const int DRIVE_SPEED = 115; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 100;
const int SWING_SPEED = 100;


Catapult catapult(15, 14);
Intake intake(11);
Pistons pistons('H');

///
// Constants
///

// It's best practice to tune constants when the robot is empty and with heavier game objects, or with lifts up vs down.
// If the objects are light or the cog doesn't change much, then there isn't a concern here.

void default_constants() {
  chassis.set_slew_min_power(80, 80);
  chassis.set_slew_distance(7, 7);
  chassis.set_pid_constants(&chassis.headingPID, 11, 0, 20, 0);
  chassis.set_pid_constants(&chassis.forward_drivePID, 0.45, 0, 2, 0);
  chassis.set_pid_constants(&chassis.backward_drivePID, 0.45, 0, 5, 0);
  chassis.set_pid_constants(&chassis.turnPID, 5, 0.003, 35, 15);
  chassis.set_pid_constants(&chassis.swingPID, 7, 0, 45, 0);
}

 
ASSET(FrontGoal_txt);
ASSET(PassBarrier_txt);

void twentyFiveGoal(){
  bool GoalSide = true;

  lemchassis.setPose(0, 0, 0);
  chassis.set_angle(45);

  pistons.launchWings(true);

  chassis.set_drive_pid(40, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_swing_pid(RIGHT_SWING, 0 , 80);
  chassis.wait_drive();

  intake.toggle(true, false);
  chassis.set_drive_pid(50, DRIVE_SPEED, false);
  chassis.wait_drive();

  intake.toggle(true, true);

  chassis.set_drive_pid(-40, DRIVE_SPEED, true, true);
  chassis.wait_drive();

  chassis.toggle_auto_drive(false);

  pistons.launchWings(false);
  

lemchassis.moveTo(0, -10, 0, 1000, false, true, 15);

lemchassis.moveTo(24, 0, 144, 2000, true, true, 10);
lemchassis.waitUntilDist(10);
intake.toggle(true, true);
intake.toggle(false, false);
lemchassis.waitUntilDist(1000);

chassis.toggle_auto_drive(true);

chassis.set_drive_pid(140, DRIVE_SPEED);
chassis.wait_drive();

chassis.set_turn_pid(0, TURN_SPEED);
chassis.wait_drive();

//lemchassis.moveTo(50, -26, 140, 2000, false, true, 15);
//lemchassis.turnTo(36, -28, 2000);

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

}

void PIDGoalSide(){
  bool GoalSide = true;
  pistons.launchWings(true);

  chassis.set_angle(45);

  chassis.set_drive_pid(40, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_swing_pid(RIGHT_SWING, 0 , 80);
  chassis.wait_drive();

  intake.toggle(true, false);
  chassis.set_drive_pid(50, DRIVE_SPEED, false);
  chassis.wait_drive();

  intake.toggle(true, true);

  chassis.set_drive_pid(-40, DRIVE_SPEED, true, true);
  chassis.wait_drive();

  pistons.launchWings(false);

  chassis.set_turn_pid(-70, TURN_SPEED);
  chassis.wait_until(-60);
  intake.toggle(false, false);
  chassis.wait_drive();

  chassis.set_drive_pid(140, DRIVE_SPEED, true, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-30, DRIVE_SPEED, true, true);
  chassis.wait_drive();
  intake.toggle(false, true);

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(50, DRIVE_SPEED, true, true);
  chassis.wait_drive();

  chassis.set_swing_pid(LEFT_SWING, 90, SWING_SPEED);
  chassis.wait_drive();

  pistons.launchWings(true);

  intake.toggle(true, false);

  chassis.set_drive_pid(50, DRIVE_SPEED, false, true);
  chassis.wait_drive();

  pistons.launchWings(false);

  chassis.set_drive_pid(-50, DRIVE_SPEED, false, true);
  chassis.wait_drive();

  intake.toggle(true, true);

  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  intake.toggle(false, false);

  chassis.set_drive_pid(40, DRIVE_SPEED, true, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-40, DRIVE_SPEED, true, true);
  chassis.wait_drive();
  intake.toggle(false, true);

  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();
  intake.toggle(true, false);
  pistons.launchWings(true);

  chassis.set_drive_pid(70, 127, false, true);
  chassis.wait_drive();
}

void PIDFarSide(){
  GoalSide = false;

  pistons.launchWings(true);
  pros::delay(100);
  pistons.launchWings(false);

  chassis.set_turn_pid(18, TURN_SPEED);
  chassis.wait_drive();

  pistons.launchWings(false);

  chassis.set_drive_pid(140, DRIVE_SPEED, true);
  chassis.wait_until(60);
  intake.toggle(false, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-30, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  pros::delay(300);

  catapult.cataSpinToPosition(0, -200);

  chassis.set_turn_pid(60, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(40, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-30, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  pros::delay(300);

  catapult.cataSpinToPosition(0, -200);

  chassis.set_turn_pid(-135, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(130, DRIVE_SPEED, true);
  chassis.wait_until(120);
  chassis.set_max_speed(80);
  chassis.wait_drive();

  chassis.set_turn_pid(-180, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-60, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_drive_pid(45, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-200, TURN_SPEED);
  chassis.wait_drive();

  pistons.launchWings(true);

  chassis.set_drive_pid(57, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-290, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(150, DRIVE_SPEED, false);
  chassis.wait_drive();
}

void farSideAutonWin(){

GoalSide = false;
  
lemchassis.setPose(0, 0, 0);

pistons.launchWings(true);

lemchassis.moveTo(22, 19, 90, 2000, true, true, 12);
lemchassis.waitUntilDist(15);
intake.toggle(true, false);
lemchassis.waitUntilDist(20);
pistons.launchWings(false);
lemchassis.waitUntilDist(1000);

intake.toggle(true, true);

lemchassis.moveTo(9, -2, 0, 2000, false, false, 12);

lemchassis.turnTo(37, -8, 1500);

lemchassis.moveTo(37, -8, 105, 2000, true, true, 9);
lemchassis.waitUntilDist(5);
intake.toggle(false, false);
lemchassis.waitUntilDist(1000);

lemchassis.moveTo(29, -12, 0 , 2500, false, false, 2, 0.3);
pros::delay(300);
catapult.cataSpinToPosition(0, -200);

intake.toggle(false, true);

lemchassis.moveTo(-4, 7, 315, 2000, false, true, 9);
pistons.launchWings(true);

lemchassis.turnTo(-7, 3, 2000);

lemchassis.moveTo(-11, -28, 180, 2000, false, true, 9);


}

void goalSide10Point(){
  
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

lemchassis.moveTo(0, -20, 0, 1000, false, true, 15);
}

void Skills(){
  
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


lemchassis.setPose(60, -35, 180);

lemchassis.follow(PassBarrier_txt, 10000, 12, false, true);

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




