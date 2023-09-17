#include "main.h"


/////
// For instalattion, upgrading, documentations and tutorials, check out website!
// https://ez-robotics.github.io/EZ-Template/
/////


const int DRIVE_SPEED = 115; // This is 110/127 (around 87% of max speed).  We don't suggest making this 127.
                             // If this is 127 and the robot tries to heading correct, it's only correcting by
                             // making one side slower.  When this is 87%, it's correcting by making one side
                             // faster and one side slower, giving better heading correction.
const int TURN_SPEED  = 100;
const int SWING_SPEED = 100;


Catapult catapult(15, 20);
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

void goalSideRush(){
    pistons.launchWings(true);

    chassis.set_angle(45);

    chassis.set_drive_pid(50, 70, true, true);
    chassis.wait_drive();
    chassis.set_turn_pid(0, 70);
    chassis.wait_drive();
    chassis.set_drive_pid(25, DRIVE_SPEED, true, true);
    chassis.wait_drive();
    chassis.set_turn_pid(45, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(30, DRIVE_SPEED, true, true);
    chassis.wait_drive();
    pistons.launchWings(false);
    intake.toggle(true, false);
    chassis.set_turn_pid(0, TURN_SPEED);
    chassis.wait_drive();
    intake.toggle(true, true);
    chassis.set_drive_pid(25, DRIVE_SPEED, false, true);
    chassis.wait_drive();

    chassis.set_drive_pid(-40, DRIVE_SPEED, true, true);
    chassis.wait_drive();
    chassis.set_turn_pid(-70, TURN_SPEED);
    chassis.wait_until(-60);
    pistons.InitialLaunch(true);
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
    pistons.launchWings(true);

    chassis.set_swing_pid(LEFT_SWING, 90, SWING_SPEED);
    chassis.wait_drive();
    
    pistons.InitialLaunch(false);
    intake.toggle(true, false);
    chassis.set_drive_pid(50, DRIVE_SPEED, false, true);
    chassis.wait_drive();

    pistons.launchWings(false);
    intake.toggle(true, true);
    chassis.set_drive_pid(-60, DRIVE_SPEED, true, true);
    chassis.wait_drive();

    chassis.set_turn_pid(-60, TURN_SPEED);
    chassis.wait_drive();

    pistons.InitialLaunch(true);
    intake.toggle(false, false);
    chassis.set_drive_pid(30, DRIVE_SPEED, true, true);
    chassis.wait_drive();

    chassis.set_drive_pid(-30, 127, true, true);
    chassis.wait_drive();
    intake.toggle(false, true);

    chassis.set_turn_pid(90, TURN_SPEED);
    chassis.wait_drive();
    pistons.InitialLaunch(false);
    intake.toggle(true, false);
    pistons.launchWings(true);

    chassis.set_drive_pid(70, 127, false, true);
    chassis.wait_drive();


}

void farSide(){
  pistons.launchWings(true);
  pros::delay(500);
  pistons.launchWings(false);

  chassis.set_turn_pid(32, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(160, DRIVE_SPEED, true);
  chassis.wait_until(60);
  pistons.InitialLaunch(true);
  intake.toggle(false, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-30, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  pros::delay(900);

  catapult.cataSpinToPosition(0, -200);

  chassis.set_turn_pid(-45, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(30, DRIVE_SPEED, true);
  chassis.wait_drive();

  pros::delay(800);

  chassis.set_turn_pid(-90, TURN_SPEED);
  chassis.wait_drive();

  catapult.cataSpinToPosition(0, -200);

  chassis.set_turn_pid(-135, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(160, DRIVE_SPEED, true);
  chassis.wait_drive();





  
}