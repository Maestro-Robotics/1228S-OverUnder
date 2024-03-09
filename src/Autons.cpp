#include "Pistons.hpp"
#include "Subsystems.hpp"
#include "autons.hpp"
#include "main.h"
#include "pros/motors.h"
#include "pros/rtos.hpp"

// Contains all of the code for the different autons for team 1228S
  Catapult catapult(12, 15);
  Intake intake(8);
  Pistons pistons('H', 'A', 'C', 'B', 'E');
  PTO pto(12, 15, 19, 'G');
  Subsystems subsystems(catapult, intake, pistons, pto);
pros::Optical optSen(18);

void twentyFiveGoal(){
  lemchassis.setPose(0, 0, 0);

  intake.toggle(false, false);

  lemchassis.moveToPoint(0, -3, 1000, {.forwards = false});
  lemchassis.moveToPoint(0, 32, 1500);
  lemchassis.moveToPoint(0, 6, 1000, {.forwards = false});
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, false);

  lemchassis.moveToPose(31, -22, 90, 2000, {.forwards = false, .lead = 0.4, .minSpeed = 100});
  lemchassis.waitUntil(18);
  pistons.closeBackWings();

  lemchassis.moveToPoint(15, -22, 1000, {.forwards = false});
  lemchassis.turnToHeading(90, 1000);
  lemchassis.moveToPoint(34, -24, 1000);








 
}

void testGoal(){
  lemchassis.setPose(0, 0, 0);

  intake.toggle(false, false);
  lemchassis.moveToPoint(0, 33, 2000);
  lemchassis.waitUntil(30);
  lemchassis.cancelMotion();

  lemchassis.moveToPoint(0, 29, 2000, {.forwards = false});
  lemchassis.waitUntil(25);
  lemchassis.cancelMotion();

  lemchassis.turnToHeading(0, 0, 800);

  lemchassis.moveToPoint(1, 16, 1000);
  lemchassis.swingToAngle(133, true, 500);

  // lemchassis.moveToPoint(5, -5, 1000);
  // lemchassis.waitUntilDone();
  // pistons.launchFrontwings(true, true);

  // lemchassis.turnToHeading(90, 550);
  lemchassis.moveToPose(21, -29, 90, 2000, {.chasePower = 12, .minSpeed = 127});
  lemchassis.waitUntilDone();
  pistons.closeFrontWings();
  intake.toggle(true, false);
  lemchassis.moveToPoint(36, -15, 1000);

  lemchassis.moveToPose(3, 3, 130, 1200, {.forwards = false, .chasePower = 18});

  lemchassis.swingToAngle(58, true, 400);
  lemchassis.waitUntilDone();
  intake.toggle(false, false);


  lemchassis.moveToPose(57, 39, 45, 2000, {.forwards = true, .chasePower = 18});
  lemchassis.turnToHeading(180, 500);
  lemchassis.waitUntilDone();
  pistons.launchFrontwings(true, true);
  intake.toggle(true, false);

  lemchassis.moveToPoint(61, 5, 2000);

  lemchassis.moveToPoint(61, 25, 1000, {.forwards = false});
  lemchassis.waitUntilDone();
  pistons.closeFrontWings();

  lemchassis.swingToAngle(347, false, 500);
  lemchassis.waitUntilDone();
  intake.toggle(false, false);

  lemchassis.moveToPoint(39, 39, 2000);
  lemchassis.swingToAngle(180, false, 500);
  lemchassis.waitUntilDone();
  pistons.launchFrontwings(true, true);

  lemchassis.moveToPoint(55, 5, 1500);
  lemchassis.waitUntil(15);
  intake.toggle(true, false);

  lemchassis.moveToPoint(55, 30, 1000, {.forwards = false});

  }

void disruptClose(){
  lemchassis.moveToPoint(0, 38, 1000, {.forwards = false});
  lemchassis.turnToHeading(270, 1000);
  intake.toggle(true, false);
  pistons.launchFrontwings(true, true);

  lemchassis.moveToPoint(22, 38, 1000, {.forwards = false});
  pistons.closeFrontWings();

  lemchassis.moveToPoint(-13, 38, 2000, {.forwards = false});
  lemchassis.moveToPoint(13, 38, 2000, {.forwards = false});
  lemchassis.turnToHeading(330, 1000);



}

void closeSideAWP(){
  GoalSide = false;
    
  lemchassis.setPose(0, 0, 0);
  intake.toggle(false, false);

  lemchassis.moveToPoint(0, -4, 1000, {.forwards = false, .earlyExitRange = 2});

  lemchassis.moveToPose(16, 46, 0, 1500, {.lead = 0.3, .minSpeed = 110});
  lemchassis.moveToPoint(16, 43, 1000, {.forwards = false});
  lemchassis.turnToHeading(-90, 1000);
  lemchassis.waitUntilDone();
  pistons.launchBackWings(false, true);

  lemchassis.moveToPoint(32, 41, 1000, {.forwards = false});
  lemchassis.waitUntilDone();
  pistons.closeBackWings();

  lemchassis.setBrakeMode(pros::E_MOTOR_BRAKE_HOLD);
  lemchassis.moveToPoint(-3.3, 0.65, 2000);
  lemchassis.turnToHeading(-225, 1000);
  lemchassis.waitUntilDone();
  pistons.launchBackWings(false, true);
  intake.toggle(true, false);
  pros::delay(600);

  lemchassis.swingToAngle(-254, true, 500);
  lemchassis.turnToHeading(-270, 1000);
  lemchassis.waitUntilDone();
  pistons.closeBackWings();

  lemchassis.moveToPose(-12, 8, -212, 1000, {.forwards = false});
  lemchassis.waitUntilDone();
  pistons.launchBackWings(false, true);

  lemchassis.moveToPose(31, -8, -266, 2000, {.lead = 0.8});
  lemchassis.waitUntil(12);
  pistons.closeBackWings();
  }

void preloadGoal(){
 lemchassis.setPose(0, 0, 0);

 lemchassis.moveToPose(30, -18, 270, 2000, {.forwards = false, .chasePower = 18, .minSpeed = 127});
 lemchassis.moveToPose(0, 0, 0, 1000);

 
;
}

void Skills(){
  lemchassis.setPose(0, 0, 315);

  //Push preloads into Close Goal
  lemchassis.moveToPose(37, -24, 270, 2000, {.forwards = false, .minSpeed = 127, .earlyExitRange = 3});

  //Setup for Matchload position
  lemchassis.moveToPoint(18, -18, 800);
  lemchassis.turnToHeading(384, 800);
  lemchassis.moveToPose(13, -27.5, 382.5, 1000, {.forwards = false, .chasePower = 18, .lead = 0, .maxSpeed = 115});
  lemchassis.waitUntilDone();
  // pistons.launchBackWings(true, false);

  //Matchload
  const int timeout = 19500;
  uint32_t start_time = pros::millis();
  //lemchassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  catapult.cataMatchLoad(180);
  while (true){
  if (pros::millis() - start_time > timeout) {
        std::printf("Spin motor timeout reached");
        catapult.cataMatchLoad(0);
        break;
    }
  }

  //Clear Defensive Side
  lemchassis.moveToPoint(27, 15, 900, {.earlyExitRange = 6});
  lemchassis.waitUntil(5);
  pistons.closeBackWings();
  intake.toggle(false, false);


  lemchassis.turnToHeading(270, 1000);
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, false);
  lemchassis.moveToPoint(97, 11, 2500, {.forwards = false, .minSpeed = 127,.earlyExitRange = 2});

  lemchassis.moveToPoint(74, 8, 800, {.earlyExitRange = 5});
  lemchassis.waitUntilDone();
  pistons.closeBackWings();
  lemchassis.turnToHeading(320, 700);
  lemchassis.moveToPoint(90, -14.2, 800, {.forwards = false, .earlyExitRange = 2});
  lemchassis.swingToAngle(180, false, 1000);

  //Push right side
  lemchassis.moveToPoint(118, 56, 2000, {.forwards = false, .earlyExitRange = 2});
  lemchassis.waitUntil(37);
  pistons.launchBackWings(true, false);
  //lemchassis.swingToAngle(145, false, 1000);
  lemchassis.moveToPose(80, 93, 90, 2000, {.forwards = false, .minSpeed = 127, .earlyExitRange = 3});
  lemchassis.waitUntil(13);
  pistons.launchBackWings(false, false);
  lemchassis.moveToPoint(100, 92, 1000);
  lemchassis.moveToPoint(80, 93, 1000, {.forwards = false, .earlyExitRange = 2});

  //Push right-mid
  lemchassis.moveToPoint(97, 87, 1000);
  lemchassis.waitUntilDone();
  pistons.closeBackWings();
  lemchassis.turnToHeading(199, 800);

  lemchassis.moveToPose(89, 58, 201, 1000, {.lead = 0.3,.minSpeed = 90});
  lemchassis.waitUntilDone();
  intake.toggle(true, true);
  lemchassis.moveToPose(68.8, 86, 0, 2500, {.forwards = true, .lead = 0.6, .minSpeed = 127});
  lemchassis.moveToPoint(68.8, 70, 1000, {.forwards = false});
  lemchassis.moveToPoint(68.8, 86, 1000);

  //Push Mid
  lemchassis.moveToPoint(71, 54, 1000, {.forwards = false, .earlyExitRange = 2});
  // lemchassis.waitUntilDone();
  lemchassis.turnToHeading(90, 1000);
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, true);
    lemchassis.moveToPose(54, 86, 180, 2500, {.forwards = false, .chasePower = 15, .lead = 0.8, .minSpeed = 100});
    // lemchassis.waitUntil(8);
    // pistons.launchBackWings(true, true);
    lemchassis.waitUntilDone();
    pistons.closeBackWings();

  //May remove
  lemchassis.moveToPoint(54, 62, 1000, {.earlyExitRange = 2});
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, true);
  lemchassis.moveToPoint(54, 84, 1000, {.forwards = false, .earlyExitRange = 2});
  lemchassis.waitUntilDone();
  pistons.closeBackWings();
  //

  lemchassis.moveToPoint(55, 52, 1000);
  lemchassis.turnToHeading(90, 1000);
  lemchassis.moveToPoint(26, 52, 1000, {.forwards = false});
  lemchassis.waitUntilDone();
  pistons.launchBackWings(false, true);
  lemchassis.turnToHeading(582, 1000);

  lemchassis.moveToPose(52, 84 , 180, 2000, {.forwards = false, .maxSpeed = 90});
  lemchassis.waitUntil(3);
  pistons.launchBackWings(true, true);
  lemchassis.waitUntilDone();
  pistons.closeBackWings();

    //May remove
  lemchassis.moveToPoint(52, 62, 1000, {.earlyExitRange = 2});
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, true);
  lemchassis.moveToPoint(52, 84, 1000, {.forwards = false, .earlyExitRange = 2});
  lemchassis.waitUntilDone();
  pistons.closeBackWings();
  //

  lemchassis.moveToPoint(48, 54, 1000);
  lemchassis.turnToHeading(485, 1000);
    lemchassis.moveToPose(0, 78 , 464, 1500, {.forwards = false, .chasePower = 18});
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, false);
    lemchassis.moveToPose(38, 100 , 270, 2000, {.forwards = false, .minSpeed = 127});
    lemchassis.waitUntilDone();
    pto.engagePTO(true);
    lemchassis.moveToPoint(12, 99, 1000);

    lemchassis.moveToPoint(38, 102, 1000, {.forwards = false});
    lemchassis.waitUntilDone();
    pistons.closeBackWings();
    lemchassis.moveToPose(4, 43 , 545, 2000, {.forwards = true});
    lemchassis.waitUntilDone();
		pto.changeBrakeMode(pros::E_MOTOR_BRAKE_COAST);
		catapult.cataMatchLoad(200);
    pistons.engageRatchet(true);





}

void driverSkills(){
  lemchassis.setPose(0, 0, 315);

  //Push preloads into Close Goal
  lemchassis.moveToPose(37, -24, 270, 2000, {.forwards = false, .minSpeed = 127, .earlyExitRange = 3});

  //Setup for Matchload position
  lemchassis.moveToPoint(18, -18, 800);
  lemchassis.turnToHeading(384, 800);
  lemchassis.moveToPose(13, -27.5, 382, 1000, {.forwards = false, .chasePower = 18, .lead = 0, .maxSpeed = 110});
  lemchassis.waitUntilDone();

  //Matchload
  const int timeout = 19000;
  uint32_t start_time = pros::millis();
  //lemchassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  catapult.cataMatchLoad(180);
  while (true){
  if (pros::millis() - start_time > timeout) {
        std::printf("Spin motor timeout reached");
        catapult.cataMatchLoad(0);
        break;
    }
  }

  // //Clear Defensive Side
  // lemchassis.moveToPoint(27, 15, 900, {.earlyExitRange = 6});
  // lemchassis.waitUntil(5);
  // pistons.closeBackWings();
  // intake.toggle(false, false);


  // lemchassis.turnToHeading(270, 1000);
  // lemchassis.waitUntilDone();
  // pistons.launchBackWings(true, false);
  // lemchassis.moveToPoint(97, 11, 2500, {.forwards = false, .minSpeed = 127,.earlyExitRange = 2});

  // lemchassis.moveToPoint(74, 8, 800, {.earlyExitRange = 5});
  // lemchassis.waitUntilDone();
  // pistons.closeBackWings();
  // lemchassis.turnToHeading(320, 700);
  // lemchassis.moveToPoint(92, -15.5, 800, {.forwards = false, .earlyExitRange = 2});
  // lemchassis.swingToAngle(180, false, 1000);

  // lemchassis.moveToPoint(118, 56, 2000, {.forwards = false, .earlyExitRange = 2});


}

void pptest(){
  intake.toggle(false, false);
  lemchassis.moveToPose(-18, -8, 108, 1500, {.forwards = false, .chasePower = 18});
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, false);
  intake.toggle(true, false);

  lemchassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);

  catapult.cataMatchLoad(-180);
}
