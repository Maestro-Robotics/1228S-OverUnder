#include "main.h"

// Define constants for drive and turn speeds
const int DRIVE_SPEED = 127; // This is 110/127 (around 87% of max speed). We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower. When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;


Catapult catapult(2, 5, 16);
Intake intake(1);
Pistons pistons('A', 'B', 'C', 'D');

// Function to execute the Goal Side Autonomous 1 routine
void GoalSideRush() {
  GoalSide = true;

  // Lift the wheel using the pistons
  pistons.ChangeAngle(GoalSide);
  pistons.LiftWheel();

  chassis.set_drive_pid(42, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);

  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-5, DRIVE_SPEED, false);
  chassis.wait_drive();

  pistons.InitialLaunch(false);
  intake.toggle(false, true);

  chassis.set_drive_pid(12, 127, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-25, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-65, TURN_SPEED);
  pistons.InitialLaunch(true);
  chassis.wait_drive();

  chassis.set_drive_pid(55, DRIVE_SPEED, true);
  intake.toggle(false, false);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  intake.toggle(true, true);
  chassis.wait_drive();

  chassis.set_drive_pid(5, DRIVE_SPEED, false);
  intake.toggle(true, false);
  pistons.InitialLaunch(false);
  chassis.wait_drive();

  chassis.set_drive_pid(18, DRIVE_SPEED, true);
  intake.toggle(false, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-15, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(225, TURN_SPEED);
  pistons.InitialLaunch(true);
  intake.toggle(false, false);
  chassis.wait_drive();

  chassis.set_drive_pid(30, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-25, DRIVE_SPEED, true);
  pistons.InitialLaunch(false);
  intake.toggle(false, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(3, DRIVE_SPEED, false);
  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  pistons.InitialLaunch(false);
  chassis.set_drive_pid(20, DRIVE_SPEED, false);
  chassis.wait_drive();
}

// Function to execute the Goal Side Autonomous 2 routine
void GoalSideSafe() {

  GoalSide = true;

  pistons.LiftWheel();
  pistons.ChangeAngle(GoalSide);

  chassis.set_drive_pid(42, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);

  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-3, DRIVE_SPEED, false);
  chassis.wait_drive();

  pistons.InitialLaunch(false);
  intake.toggle(false, true);

  chassis.set_drive_pid(8, 127, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-25, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(255, TURN_SPEED);
  pistons.InitialLaunch(true);
  chassis.wait_drive();

  chassis.set_drive_pid(55, DRIVE_SPEED, true);
  intake.toggle(false, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-5, DRIVE_SPEED, false);
  pistons.InitialLaunch(false);
  chassis.wait_drive();

  chassis.set_turn_pid(20, TURN_SPEED);
  intake.toggle(true, true);
  chassis.wait_drive();

  chassis.set_drive_pid(26, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  chassis.set_drive_pid(20, DRIVE_SPEED, false);
  intake.toggle(false, true);
  pistons.InitialLaunch(false);
  chassis.wait_drive();

  chassis.set_drive_pid(-12, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, TURN_SPEED);
  pistons.InitialLaunch(true);
  intake.toggle(false, false);
  chassis.wait_drive();

  chassis.set_drive_pid(15, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(45, TURN_SPEED);
  chassis.wait_drive();
}

// Function to execute the Far Side Autonomous routine
void FarSide() {

  GoalSide = false;

  pistons.LiftWheel();

   chassis.set_drive_pid(40, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-40, DRIVE_SPEED, true);
  chassis.wait_drive();

  intake.toggle(true, true);

  chassis.set_turn_pid(225, TURN_SPEED);
  chassis.wait_drive(); 

  chassis.set_drive_pid(42, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(270, TURN_SPEED);

  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-3, DRIVE_SPEED, false);
  chassis.wait_drive();

  pistons.InitialLaunch(false);
  intake.toggle(false, true);

  chassis.set_drive_pid(10, 127, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(359, TURN_SPEED);
  chassis.wait_drive();
 
  chassis.set_drive_pid(28, DRIVE_SPEED, true);
  chassis.wait_drive();  

  chassis.set_turn_pid(290, TURN_SPEED);
  pistons.InitialLaunch(true);
  intake.toggle(false, false);
  chassis.wait_drive();

  chassis.set_drive_pid(50, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(180, TURN_SPEED);
  chassis.wait_drive();

  catapult.CataSpinToPosition(0, 150);
  chassis.wait_drive();
  
  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();
  
  chassis.set_drive_pid(20, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(135, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(70, 127, true);
}

// Function to execute the Skills routine
void SkillsDevelopment() {
  GoalSide = true;
  SkillsMode = true;

  // Lift the wheel using the pistons
  pistons.LiftWheel();

  // Move backward to a specific target position
  chassis.set_drive_pid(-10, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(45, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(42, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-90, TURN_SPEED);

  // Launch the catapult and toggle the intake
  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-3, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Retract the catapult and toggle the intake
  pistons.InitialLaunch(false);
  intake.toggle(false, true);

  // Move forward to a specific target position
  chassis.set_drive_pid(10, 127, false);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-270, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(8, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-340, TURN_SPEED);
  chassis.wait_drive();

  // Launch the catapult and load the ball
  pistons.InitialLaunch(true);
  catapult.MatchLoadSkills(22, 40);
  catapult.CataSpinToPosition(0, 140);

  // Turn to a specific angle
  chassis.set_turn_pid(-343, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-50, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(5, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-15, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Toggle the intake
  intake.toggle(false, false);

  // Turn to a specific angle
  chassis.set_turn_pid(-70, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(38, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Delay to wait for the piston to settle
  pros::delay(400);

  // Turn to a specific angle
  chassis.set_turn_pid(-360, TURN_SPEED);
  chassis.wait_drive();

  // Spin the catapult to a specific position
  catapult.CataSpinToPosition(0, 140);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-20, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(10, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(20, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-15, DRIVE_SPEED, false);
  chassis.wait_drive();

  // Move forward to a specific target position and toggle the intake
  chassis.set_drive_pid(15, DRIVE_SPEED, true, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  // Move forward to a specific target position
  chassis.set_drive_pid(60, DRIVE_SPEED, true);
  chassis.wait_until(60);

  // Turn to a specific angle
  chassis.set_turn_pid(-30, TURN_SPEED);
  chassis.wait_drive();

  // Launch the catapult and load the ball
  catapult.MatchLoadSkills(22, 40);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-5, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-315, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-20, DRIVE_SPEED, true);
  chassis.wait_drive();

  // Turn to a specific angle
  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  // Move backward to a specific target position
  chassis.set_drive_pid(-20, DRIVE_SPEED, true);
  chassis.wait_drive();
}

// Function to execute the SkillsMatchOnly routine
void SkillsMatchLoadOnly() {
  GoalSide = true;
  SkillsMode = true;
  pistons.LiftWheel();

  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_drive_pid(45, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive(); 

  chassis.set_drive_pid(42, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, TURN_SPEED);

  pistons.InitialLaunch(true);
  intake.toggle(true, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-3, DRIVE_SPEED, false);
  chassis.wait_drive();

  pistons.InitialLaunch(false);
  intake.toggle(false, true);

  chassis.set_drive_pid(10, 127, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-8, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-270, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(8, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-340, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(3, DRIVE_SPEED, false);
  chassis.wait_drive();

  pistons.InitialLaunch(true);
  catapult.MatchLoadSkills(44, 40);
  catapult.CataSpinToPosition(0, 140);

  chassis.set_turn_pid(-343, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-50, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(5, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-15, DRIVE_SPEED, false);
  chassis.wait_drive();

  intake.toggle(false, false);
  chassis.set_turn_pid(-70, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(38, DRIVE_SPEED, true);
  chassis.wait_drive();

  pros::delay(400);

  chassis.set_turn_pid(-360, TURN_SPEED);
  chassis.wait_drive();

  catapult.CataSpinToPosition(0, 140);
  chassis.wait_drive();

  chassis.set_drive_pid(-20, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(10, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(20, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-15, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_drive_pid(15, DRIVE_SPEED, true, true);
  chassis.wait_drive();

  

  // chassis.set_turn_pid(-45, TURN_SPEED);
  // chassis.wait_drive();

  // chassis.set_drive_pid(-20, DRIVE_SPEED, true);
  // chassis.wait_drive();



  // chassis.set_turn_pid(-343, TURN_SPEED);
  // chassis.wait_drive();

  // chassis.set_drive_pid(-50, DRIVE_SPEED, true);
  // chassis.wait_drive();

  // chassis.set_turn_pid(-90, TURN_SPEED);
  // chassis.wait_drive();

  // chassis.set_drive_pid(80, DRIVE_SPEED, true);
  // intake.toggle(true, false);
  // chassis.wait_drive();

  // chassis.set_turn_pid(-45, TURN_SPEED);
  //   chassis.wait_drive();

  //   chassis.set_drive_pid(60, DRIVE_SPEED, true);
  //   intake.toggle(false, true);
  //   chassis.wait_drive();

  //   chassis.set_turn_pid(-30, TURN_SPEED);
  //   chassis.wait_drive();

  //   catapult.MatchLoadSkills(22, 40);

}
