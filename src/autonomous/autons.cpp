#include "autons.hpp"
#include <math.h>


void longGoalLeft() {
   //go to 3 blocks
   chassis.turnToHeading(-17, 1000);
   intakeState = 3;
   chassis.moveToPoint(-7.5, 25.4,1500, {.maxSpeed = 40});
   pros::delay(100);
   intakeState = 0;

   //go to mid goal
   chassis.turnToHeading(42, 1000);
   chassis.moveToPoint(1.27, 33.95, 1500);
   trapdoorState = 1; 
   pros::delay(100);
   intakeState = 1;
   pros::delay(450); //auton one ball
   intakeState = 5;
   pros::delay(250);
   intakeState = 0;
   trapdoorState = 0;
   pros::delay(150);


   // driving reverse to the matchload
   chassis.moveToPoint(-33, 1.8, 1000, {.forwards=false});
   chassis.waitUntilDone();
   littleWillState = 1;
   chassis.turnToHeading(182, 1000);
   chassis.waitUntilDone();
   intakeState = 3;
   
   // driving into the matchloader
   chassis.moveToPoint(-32.123, -12, 800, {.maxSpeed = 127});
   pros::delay(1000); // wait to intake

   
   // //back up from match loader
   chassis.moveToPoint(-32.4, 0.4, 1000, {.forwards = false, .maxSpeed = 90});
   chassis.waitUntilDone();
   hoodState = 1;
   littleWillState = 0;

   
   //turn to long goal and score
   trapdoorState = 1;
   pros::delay(500);
   chassis.turnToHeading(-4, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(-33, 16, 1000, {.maxSpeed = 40});
   chassis.waitUntilDone();
   hoodState = 1;
   intakeState = 1;

   while(true) {
    if(autonColor == 'R') {
        if(200 < colorLeft.get_hue() && colorLeft.get_hue() < 240 || 200 < colorRight.get_hue() && colorRight.get_hue() < 240) {
            intakeState = 0;
        }
    } else if(autonColor == 'B') {
        if(0 < colorLeft.get_hue() && colorLeft.get_hue() < 25 || 0 < colorRight.get_hue() && colorRight.get_hue() < 25) {
            intakeState = 0;
        }
    }
   }

}


void longGoalRight() {
   //go to 3 blocks
   chassis.turnToHeading(17, 1000);
   intakeState = 3;
   chassis.moveToPoint(7.5, 25.4,1500, {.maxSpeed = 40});
   pros::delay(250);
   //intakeState = 0;

   //go to mid low goal
   chassis.turnToHeading(-42.9, 1000);
   chassis.moveToPoint(-1.27, 33.95, 1500, {.maxSpeed=80});
   chassis.waitUntilDone();
   intakeState = 2;
   pros::delay(770);
   intakeState = 3;
   pros::delay(250);


   // driving reverse to the matchload
   chassis.moveToPoint(33, 1.8, 2000, {.forwards=false});
   chassis.waitUntilDone();
   littleWillState = 1;
   chassis.turnToHeading(-182, 1000);
   chassis.waitUntilDone();
   intakeState = 3;
   
   // driving into the matchloader
   chassis.moveToPoint(32, -12, 1250);
   //pros::delay(250); // wait to intake

   
   // //back up from match loader
   chassis.moveToPoint(32, 0.4, 1000, {.forwards = false, .maxSpeed = 90});
   chassis.waitUntilDone();
   pros::delay(100);
   hoodState = 1;
   littleWillState = 0;

   
   //turn to long goal and score
   trapdoorState = 1;
   pros::delay(500);
   chassis.turnToHeading(4, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(33, 16.51, 1000, {.maxSpeed = 40});
   chassis.turnToHeading(-4, 1000);
   chassis.waitUntilDone();
   hoodState = 1;
   intakeState = 1;

   while(true) {
    if(autonColor == 'R') {
        if(200 < colorLeft.get_hue() && colorLeft.get_hue() < 240 || 200 < colorRight.get_hue() && colorRight.get_hue() < 240) {
            intakeState = 0;
        }
    } else if(autonColor == 'B') {
        if(0 < colorLeft.get_hue() && colorLeft.get_hue() < 25 || 0 < colorRight.get_hue() && colorRight.get_hue() < 25) {
            intakeState = 0;
        }
    }
   }

}


void skills() {
    //go to 3 blocks
    chassis.turnToHeading(17, 1000);
    intakeState = 3;
    chassis.moveToPoint(7.5, 25.4,1500, {.maxSpeed = 40});
    pros::delay(250);
    //intakeState = 0;

    //go to mid low goal
    chassis.turnToHeading(-42.9, 1000);
    chassis.moveToPoint(-1.27, 33.95, 1500, {.maxSpeed=80});
    chassis.waitUntilDone();
    intakeState = 2;
    pros::delay(1000);


    // driving reverse to the matchload
    chassis.moveToPoint(33, 1.8, 2000, {.forwards=false});
    chassis.waitUntilDone();
    littleWillState = 1;
    chassis.turnToHeading(-182, 1000);
    chassis.waitUntilDone();
    intakeState = 3;
    
    // driving into the matchloader
    chassis.moveToPoint(32, -12, 1250);
    pros::delay(2000); // wait to intake

    
    // //back up from match loader
    chassis.moveToPoint(32, 0.4, 1000, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntilDone();
    pros::delay(100);
    hoodState = 1;
    littleWillState = 0;

    
    //turn to long goal and score
    trapdoorState = 1;
    pros::delay(500);
    chassis.turnToHeading(4, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(33, 16.51, 1000, {.maxSpeed = 40});
    chassis.turnToHeading(-4, 1000);
    chassis.waitUntilDone();
    hoodState = 1;
    intakeState = 1;
    pros::delay(1500);

    //go to park zone
    chassis.moveToPoint(32, 0.4, 1000, {.forwards = false});
    chassis.turnToHeading(-135, 1000);
    chassis.moveToPose(0, -5, -90, 1000, {.lead = 0.5, .maxSpeed = 90});
    intakeState = 2;
    chassis.moveToPoint(-24, -5, 1000, {.minSpeed = 127});

}
