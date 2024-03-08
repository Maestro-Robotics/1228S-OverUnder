#include "Pistons.hpp"
#include "Subsystems.hpp"
#include "autons.hpp"
#include "main.h"
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

  lemchassis.moveToPoint(0, -4, 2000, {.forwards = false, .earlyExitRange = 2});


  lemchassis.moveToPose(-14, 48, -14, 2500, {.chasePower = 18, .minSpeed = 127, .earlyExitRange = 2});
  lemchassis.moveToPose(-3, -8, 65, 2000, {.forwards = false, .chasePower = 18, .lead = 0, .earlyExitRange = 2});
  lemchassis.waitUntilDone();
  intake.toggle(true, false);
  pros::delay(600);

  lemchassis.turnToHeading(-90, 800);
  lemchassis.waitUntilDone();
  intake.toggle(false, false);

  lemchassis.moveToPoint(-34, -5, 2000, {.forwards = true, .earlyExitRange = 2});
  lemchassis.moveToPose(13, -1, -97, 2000, {.forwards = false, .chasePower = 18, .earlyExitRange = 2});
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, false);
    lemchassis.moveToPose(36, 29, -180, 2000, {.forwards = false,.minSpeed = 127, .earlyExitRange = 2});
    lemchassis.waitUntil(17);
    pistons.closeBackWings();
  lemchassis.moveToPoint(34, 17, 2000, {.forwards = true, .earlyExitRange = 2});
  lemchassis.turnToHeading(0, 800);
  lemchassis.moveToPoint(34, 27, 2000, {.forwards = true, .earlyExitRange = 2});







 
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
    
  lemchassis.setPose(0, 0, 45);

  intake.toggle(false, false);
  lemchassis.moveToPoint(9, 9, 800);
  lemchassis.waitUntilDone();

  pistons.launchBackWings(true, false);

  lemchassis.moveToPoint(0, 0, 700, {.forwards = false});
  lemchassis.turnToHeading(0, 1000);

  lemchassis.turnToHeading(180, 1000);
  lemchassis.waitUntilDone();
  pistons.closeBackWings();
  intake.toggle(true, false);
  pistons.launchFrontwings(true, true);

  lemchassis.moveToPose(-5, -41, 180, 2000);
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
  lemchassis.moveToPose(13, -26, 384, 1000, {.forwards = false, .chasePower = 18, .lead = 0});
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, false);

  //Matchload
  const int timeout = 21000;
  uint32_t start_time = pros::millis();
  //lemchassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  catapult.cataMatchLoad(160);
  while (true){
  if (pros::millis() - start_time > timeout) {
        std::printf("Spin motor timeout reached");
        catapult.cataMatchLoad(0);
        break;
    }
  }

  //Clear Defensive Side
  lemchassis.moveToPoint(27, 16, 900, {.earlyExitRange = 6});
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
  lemchassis.moveToPoint(92, -15.5, 800, {.forwards = false});
  lemchassis.swingToAngle(180, false, 1000);

  //Push right side
  lemchassis.moveToPoint(116, 56, 2000, {.forwards = false});
  lemchassis.waitUntil(37);
  pistons.launchBackWings(true, false);
  //lemchassis.swingToAngle(145, false, 1000);
  lemchassis.moveToPose(80, 91, 90, 2000, {.forwards = false, .minSpeed = 127, .earlyExitRange = 3});
  lemchassis.waitUntil(13);
  pistons.launchBackWings(false, false);
  lemchassis.moveToPoint(100, 92, 1000);
  lemchassis.moveToPoint(80, 91, 1000, {.forwards = false});

  //Push right-mid
  lemchassis.moveToPoint(97, 87, 1000);
  lemchassis.waitUntilDone();
  pistons.closeBackWings();
  lemchassis.turnToHeading(199, 800);

  lemchassis.moveToPose(89, 58, 201, 1000, {.lead = 0.3,.minSpeed = 90});
  lemchassis.waitUntilDone();
  intake.toggle(true, true);
  // // lemchassis.waitUntil(15);
  // // pistons.launchBackWings(true, true);
  // // // lemchassis.moveToPoint(74, 58, 1000, {.forwards = false});
  // //lemchassis.swingToAngle(348, false, 1000, 90);
  lemchassis.moveToPose(68.2, 86, 0, 2500, {.forwards = true, .lead = 0.6, .minSpeed = 127});
  lemchassis.moveToPoint(68.2, 70, 1000, {.forwards = false});
  lemchassis.moveToPoint(68.2, 86, 1000);

  //Push Mid
  lemchassis.moveToPoint(71, 54, 1000, {.forwards = false});
  // lemchassis.waitUntilDone();
  lemchassis.turnToHeading(90, 1000);
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, true);
    lemchassis.moveToPose(54, 86, 180, 2500, {.forwards = false, .chasePower = 18, .lead = 0.85, .minSpeed = 100});
    // lemchassis.waitUntil(8);
    // pistons.launchBackWings(true, true);
    lemchassis.waitUntilDone();
    pistons.closeBackWings();

  lemchassis.moveToPoint(55, 52, 1000);
  lemchassis.turnToHeading(90, 1000);
  lemchassis.moveToPoint(26, 52, 1000, {.forwards = false});
  lemchassis.waitUntilDone();
  pistons.launchBackWings(false, true);
  lemchassis.turnToHeading(582, 1000);

  lemchassis.moveToPose(49, 84 , 180, 2000, {.forwards = false, .maxSpeed = 90});
  lemchassis.waitUntil(3);
  pistons.launchBackWings(true, true);
  lemchassis.waitUntilDone();
  pistons.closeBackWings();

  //May remove
  lemchassis.moveToPoint(50, 62, 1000);
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, true);
  lemchassis.moveToPoint(50, 84, 1000, {.forwards = false});
  lemchassis.waitUntilDone();
  pistons.closeBackWings();
  //

  lemchassis.moveToPoint(48, 52, 1000);
  lemchassis.turnToHeading(485, 1000);
    lemchassis.moveToPose(-3, 75 , 464, 2000, {.forwards = false, .chasePower = 18});
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, false);
    lemchassis.moveToPose(27, 100 , 270, 2000, {.forwards = false, .minSpeed = 127});
    lemchassis.waitUntilDone();
    pto.engagePTO(true);
    lemchassis.moveToPoint(12, 99, 1000);

    lemchassis.moveToPoint(27, 98, 1000, {.forwards = false});
    lemchassis.waitUntilDone();
    pistons.closeBackWings();
    lemchassis.moveToPose(-6, 41 , 545, 2000, {.forwards = true});
    lemchassis.waitUntilDone();
    pistons.engageRatchet(true);
		pto.changeBrakeMode(pros::E_MOTOR_BRAKE_COAST);
		catapult.cataMatchLoad(200);








  // lemchassis.moveToPose(67, 60, 20, 1000, {.forwards = false, .lead = 0});
  // lemchassis.swingToAngle(540, true, 1000);
  // lemchassis.waitUntil(20);
  // pistons.launchBackWings(true, true);
  // lemchassis.moveToPoint(51, 84, 1000, {.forwards = false});

  // lemchassis.moveToPose(81, 45, 317, 2500, {.forwards = false});
  // lemchassis.turnToHeading(448, 800);
  // lemchassis.waitUntilDone();
  // pistons.launchBackWings(true, true);
  // lemchassis.moveToPose(49, 84, 180, 2500, {.forwards = false, .maxSpeed = 75});
  // lemchassis.waitUntilDone();
  // pistons.closeBackWings();
  // lemchassis.moveToPose(57, 47, 808, 2500, {.forwards = true});
  // lemchassis.moveToPoint(19, 48, 2000, {.forwards = false});
  // lemchassis.turnToHeading(939, 1000);
  // lemchassis.moveToPose(36, 84, 180, 2500, {.forwards = false, .maxSpeed = 75});



  



  // lemchassis.waitUntil(10);
  // pistons.launchBackWings(false, true);
  // lemchassis.waitUntilDone();
  // pistons.closeBackWings();
  // // lemchassis.moveToPoint(62, 69, 1000);
  // // lemchassis.waitUntilDone();
  // // pistons.launchBackWings(true, true);
  // // lemchassis.moveToPoint(62, 87, 1000, {.forwards = false});
  // // lemchassis.waitUntilDone();
  // // pistons.closeBackWings();
  // lemchassis.moveToPose(84, 50, 90, 1500);
  // lemchassis.waitUntilDone();
  // pistons.launchBackWings(true, true);
  // lemchassis.moveToPose(64, 87, 180, 1800, {.forwards = false, .maxSpeed = 90});


  // lemchassis.moveToPoint(50, 60, 1000, {.forwards = false});
  // lemchassis.waitUntilDone();
  // pistons.launchBackWings(true, true);
  // lemchassis.moveToPoint(50, 87, 2000, {.forwards = false, .maxSpeed = 80});
  // lemchassis.waitUntilDone();
  // pistons.closeBackWings();
  // lemchassis.moveToPoint(50, 57, 1000);



  // lemchassis.moveToPoint(27, 57, 2000,{.forwards = false});
  // lemchassis.waitUntilDone();
  // pistons.launchBackWings(false, true);
  // lemchassis.turnToHeading(229, 800);
  // lemchassis.waitUntilDone();
  // pistons.launchBackWings(true, true);
  // lemchassis.moveToPoint(47, 74, 1000, {.forwards = false, .maxSpeed = 90});
  // lemchassis.waitUntilDone();
  // pistons.closeBackWings();
  // lemchassis.moveToPoint(49, 58, 1000);
  // lemchassis.waitUntil(1);
  // pistons.launchBackWings(true, true);
  // lemchassis.moveToPoint(49, 89, 1000, {.forwards = false});

  //   lemchassis.waitUntil(15);
  // pistons.launchBackWings(false, true);
  // lemchassis.moveToPose(65, 85, 180, 2000, {.forwards = false, .minSpeed = 127});
  // lemchassis.moveToPoint(65, 55, 1000);
  // lemchassis.waitUntil(5);
  // pistons.closeBackWings();
  // intake.toggle(false, false);
  // lemchassis.turnToHeading(90, 700);


  // lemchassis.moveToPose(105, 64, 64, 1500, {.chasePower = 18} );
  // lemchassis.moveToPose(72, 84, 180, 2000, {.forwards = false, .chasePower = 18, .lead = 0.9, .minSpeed = 127, .earlyExitRange = 3});
  // lemchassis.waitUntil(5);
  // pistons.launchBackWings(false, true);
  // lemchassis.waitUntilDone();
  // pistons.closeBackWings();
  // lemchassis.moveToPose(87, 47, 140, 1000);
  // lemchassis.turnToHeading(270, 700);
  // lemchassis.moveToPose(64, 86, 360, 1000 ,{.minSpeed = 127});







}

void driverSkills(){
  lemchassis.setPose(0, 0, 45);

  intake.toggle(false, false);
  lemchassis.moveToPose(-18, -8, 108, 1500, {.forwards = false, .chasePower = 18});
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, false);
  intake.toggle(true, false);

  // const int timeout = 22000;
  // uint32_t start_time = pros::millis();
  // lemchassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
  // catapult.cataMatchLoad(-180);
  // while (true){
  // if (pros::millis() - start_time > timeout) {
  //       std::printf("Spin motor timeout reached");
  //       catapult.cataMatchLoad(0);
  //       break;
  //   }
  // }

  pistons.closeBackWings();
  intake.toggle(false, false);

  lemchassis.moveToPoint(20, -25, 1800, {.forwards = true, .earlyExitRange = 4});

  lemchassis.turnToHeading(0, 800);
  pistons.launchBackWings(true, true);


  lemchassis.moveToPoint(14, -92, 2000, {.forwards = false, .earlyExitRange = 4});
  lemchassis.waitUntil(60);
  intake.toggle(true, false);
  lemchassis.moveToPoint(14, -80, 1000, {.forwards = true, .earlyExitRange = 3});
  lemchassis.moveToPoint(14, -95, 2000, {.forwards = false, .earlyExitRange = 4});
  lemchassis.moveToPoint(14, -80, 1000, {.forwards = true, .earlyExitRange = 3});


  lemchassis.turnToHeading(70, 600);

  lemchassis.moveToPose(8, -116, -90, 2000, {.forwards = false, .chasePower = 12, .lead = 0.85});
  pistons.closeBackWings();

  lemchassis.moveToPoint(68, -116, 1500, {.forwards = false, .earlyExitRange = 5});
  lemchassis.waitUntil(15);
  pistons.closeBackWings(true, false);
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, true);

  lemchassis.moveToPose(95, -87, -180, 2000, {.forwards = false, .chasePower = 15, .minSpeed = 127, .earlyExitRange = 5});
  lemchassis.waitUntil(15);
  pistons.launchBackWings(false, true);
  lemchassis.moveToPoint(95, -103, 1000, {.forwards = true, .earlyExitRange = 5});
  lemchassis.moveToPoint(95, -87, 700, {.forwards = false, .earlyExitRange = 5});
  lemchassis.waitUntilDone();
  pistons.closeBackWings();
  pistons.launchFrontwings(true, true);

  lemchassis.moveToPoint(92, -100, 1000, {.forwards = true, .earlyExitRange = 5});
  lemchassis.turnToHeading(-62, 400);

  lemchassis.moveToPose(53, -89,-70.38, 1500, {.forwards = true, .chasePower = 13, .earlyExitRange = 9});
  lemchassis.turnToHeading(0, 400);

  lemchassis.moveToPose(81, -69, 90, 2000, {.forwards = true, .chasePower = 18, .minSpeed = 127, .earlyExitRange = 2});
  lemchassis.waitUntilDone();
  pistons.closeFrontWings();

  lemchassis.moveToPoint(55, -70, 1300, {.forwards = false, .earlyExitRange = 4});

  lemchassis.moveToPose(86, -65,270, 2000, {.forwards = false, .chasePower = 13, .minSpeed = 127, .earlyExitRange = 2});
  lemchassis.waitUntil(3);
  pistons.launchBackWings(true, true);

  lemchassis.moveToPoint(55, -62, 1300, {.forwards = true, .earlyExitRange = 4});
  lemchassis.waitUntil(3);
  pistons.closeBackWings();

  lemchassis.moveToPoint(55, -30, 1600, {.forwards = false, .earlyExitRange = 4});
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, true);
  lemchassis.turnToHeading(315, 600);

  lemchassis.moveToPose(86, -48, 270, 2000, {.forwards = false, .minSpeed = 127, .earlyExitRange = 4});
  lemchassis.waitUntil(8);
  pistons.launchBackWings(true, false);

  lemchassis.moveToPoint(59, -48, 1500, {.forwards = true, .earlyExitRange = 3});
  // lemchassis.waitUntilDone();
  // pistons.launchBackWings(true, false);

  lemchassis.moveToPose(86, -55, 270, 2000, {.forwards = false, .minSpeed = 127, .earlyExitRange = 4});
  lemchassis.moveToPose(59, -48, 270, 1500, {.forwards = true, .earlyExitRange = 3});
  lemchassis.waitUntilDone();
  pistons.closeBackWings();
  


  lemchassis.moveToPoint(76, -5, 1500, {.forwards = false, .earlyExitRange = 3});
  lemchassis.waitUntilDone();
  pistons.launchBackWings(true, false);

  lemchassis.moveToPose(103, -26, 0, 2000, {.forwards = false, .minSpeed = 127, .earlyExitRange = 4});
  lemchassis.waitUntilDone();
  pto.engagePTO(true);
  pistons.closeBackWings();

  lemchassis.moveToPoint(103, -18, 1000, {.earlyExitRange = 2});
  lemchassis.moveToPoint(103, -26, 1000, {.forwards = false, .earlyExitRange = 4});
  lemchassis.waitUntilDone();
  pistons.engageRatchet(true);
  intake.toggle(true, false);



  lemchassis.moveToPose(38, 1, 270, 4000, {.forwards = true, .earlyExitRange = 4});
  lemchassis.waitUntil(5);
  pistons.closeBackWings();
  lemchassis.waitUntilDone();
  catapult.cataMatchLoad(-200);

















  // lemchassis.turnToHeading( 180, 500);
  //   lemchassis.moveToPoint(39, -89, 2000, {.forwards = true, .earlyExitRange = 2});


  


  
  

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
