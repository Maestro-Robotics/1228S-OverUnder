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

void goalSide(){
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

    // chassis.set_turn_pid(45, TURN_SPEED);
    // chassis.wait_drive();
    // chassis.set_drive_pid(30, DRIVE_SPEED, false);
    // chassis.wait_drive();
    // pistons.launchWings(false);
    // intake.toggle(true, false);
    // chassis.set_turn_pid(0, TURN_SPEED);
    // chassis.wait_drive();
    // intake.toggle(true, true);
    // chassis.set_drive_pid(25, DRIVE_SPEED, false);
    // chassis.wait_drive();

    chassis.set_drive_pid(-40, DRIVE_SPEED, true, true);
    chassis.wait_drive();

    pistons.launchWings(false);

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

    chassis.set_swing_pid(LEFT_SWING, 90, SWING_SPEED);
    chassis.wait_drive();

    pistons.launchWings(true);

    intake.toggle(true, false);
    pistons.InitialLaunch(false);

    chassis.set_drive_pid(50, DRIVE_SPEED, false, true);
    chassis.wait_drive();

    pistons.launchWings(false);

    chassis.set_drive_pid(-50, DRIVE_SPEED, false, true);
    chassis.wait_drive();

    intake.toggle(true, true);

    chassis.set_turn_pid(-90, TURN_SPEED);
    chassis.wait_drive();

    pistons.InitialLaunch(true);
    intake.toggle(false, false);

    chassis.set_drive_pid(40, DRIVE_SPEED, true, true);
    chassis.wait_drive();

    chassis.set_drive_pid(-40, DRIVE_SPEED, true, true);
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

void farSideSafe(){
  GoalSide = false;

  chassis.set_angle(45);

  pistons.launchWings(true);

  chassis.set_drive_pid(40, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_swing_pid(LEFT_SWING, 90, 80);
  chassis.wait_drive();

  //chassis.set_turn_pid(90, 80);
  pistons.launchWings(false);

  intake.toggle(true, false);
  chassis.set_drive_pid(50, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_drive_pid(-50, DRIVE_SPEED, true);
  chassis.wait_drive();

  intake.toggle(false, true);

  chassis.set_turn_pid(135, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(115, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(90, TURN_SPEED);
  chassis.wait_drive();

  pistons.InitialLaunch(true);
  intake.toggle(false, false);
  chassis.set_drive_pid(30, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-30, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  catapult.cataSpinToPosition(0, -200);

  chassis.set_angle(0);

  chassis.set_turn_pid(130, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(50, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_drive_pid(-50, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(0, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(-20, DRIVE_SPEED, false);
  chassis.wait_drive();

  catapult.cataSpinToPosition(0, -200);

  chassis.set_drive_pid(20, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(225, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(100, 127, false);
  chassis.wait_drive();


}


void farSide(){
  GoalSide = false;

  pistons.launchWings(true);
  pros::delay(100);
  pistons.launchWings(false);

  chassis.set_turn_pid(18, TURN_SPEED);
  chassis.wait_drive();

  pistons.launchWings(false);

  chassis.set_drive_pid(140, DRIVE_SPEED, true);
  chassis.wait_until(60);
  pistons.InitialLaunch(true);
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

  pistons.InitialLaunch(false);
  pistons.launchWings(true);

  chassis.set_drive_pid(57, DRIVE_SPEED, false);
  chassis.wait_drive();

  chassis.set_turn_pid(-290, TURN_SPEED);
  chassis.wait_drive();

  chassis.set_drive_pid(150, DRIVE_SPEED, false);
  chassis.wait_drive();
}

void SkillsDevelopment(){
  pistons.launchWings(true);
  pros::delay(500);
  pistons.launchWings(false);

  chassis.set_drive_pid(50, DRIVE_SPEED, true);
  chassis.wait_drive();

  chassis.set_turn_pid(20, TURN_SPEED);
  chassis.wait_drive();

  const int timeout = 30000;
  uint32_t start_time = pros::millis();

  pistons.InitialLaunch(true);
  
  catapult.cataMatchLoad(-200);
  while (true){

  chassis.set_turn_pid(20, TURN_SPEED);
    chassis.wait_drive();
    chassis.set_drive_pid(1, DRIVE_SPEED, true);
    chassis.wait_drive();
  if (pros::millis() - start_time > timeout) {
        std::printf("Spin motor timeout reached");
        catapult.cataSpinToPosition(0, -200);
        break;
    }
}
chassis.set_turn_pid(110, TURN_SPEED);
chassis.wait_drive();

chassis.set_drive_pid(-65, DRIVE_SPEED, false);
chassis.wait_drive();

chassis.set_turn_pid(135, TURN_SPEED);
chassis.wait_drive();

chassis.set_drive_pid(100, DRIVE_SPEED, true);
chassis.wait_drive();

chassis.set_turn_pid(180, TURN_SPEED);
chassis.wait_drive();

chassis.set_drive_pid(230, DRIVE_SPEED, true, true);
chassis.wait_drive();

chassis.set_turn_pid(240, TURN_SPEED);
chassis.wait_drive();
pistons.InitialLaunch(false);

chassis.set_drive_pid(40, DRIVE_SPEED, false);
chassis.wait_drive();

chassis.set_turn_pid(270, TURN_SPEED);
chassis.wait_drive();

chassis.set_drive_pid(55, 127, false);
chassis.wait_drive();

chassis.set_drive_pid(-55, DRIVE_SPEED, false);
chassis.wait_drive();

chassis.set_drive_pid(55, 127, false);
chassis.wait_drive();

chassis.set_drive_pid(-60, DRIVE_SPEED, false);
chassis.wait_drive();

chassis.set_turn_pid(-45, TURN_SPEED);
chassis.wait_drive();

chassis.set_drive_pid(100, DRIVE_SPEED, true);
chassis.wait_drive();

chassis.set_turn_pid(-90, TURN_SPEED);
chassis.wait_drive();

chassis.set_drive_pid(40, DRIVE_SPEED, true, true);
chassis.wait_drive();

chassis.set_turn_pid(-135, TURN_SPEED);
chassis.wait_drive();

pistons.launchWings(true);

chassis.set_drive_pid(50, DRIVE_SPEED, false);
chassis.wait_drive();

chassis.set_swing_pid(LEFT_SWING, -180, SWING_SPEED);
chassis.wait_drive();

chassis.set_drive_pid(50, DRIVE_SPEED, false);
chassis.wait_drive();

pistons.launchWings(false);

chassis.set_drive_pid(-100, DRIVE_SPEED, false);
chassis.wait_drive();

pistons.launchWings(true);

chassis.set_drive_pid(100, DRIVE_SPEED, false);
chassis.wait_drive();

pistons.launchWings(false);

chassis.set_turn_pid(-225, TURN_SPEED);
chassis.wait_drive();

chassis.set_drive_pid(-100, DRIVE_SPEED, true, true);
chassis.wait_drive();

pistons.launchWings(true);

chassis.set_drive_pid(100, DRIVE_SPEED, false);
chassis.wait_drive();

pistons.launchWings(false);

chassis.set_drive_pid(-100, DRIVE_SPEED, false);
chassis.wait_drive();











}