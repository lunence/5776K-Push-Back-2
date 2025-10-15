#include "autons.hpp"
#include <math.h>


void longGoalLeft() {
   //go to 3 blocks
   chassis.turnToHeading(-17, 1000);
   intakeState = 3; //one ball
   //intakeState = 1; //4 ball
   chassis.moveToPoint(-7.5, 25.4,1500, {.maxSpeed = 40});
   pros::delay(100);
   intakeState = 0; //uncomment for one ball

   //go to mid goal
   chassis.turnToHeading(42, 1000);
   chassis.moveToPoint(1.27, 33.95, 1500);
   trapdoorState = 1; 
    //pros::delay(100);
   intakeState = 1;
   pros::delay(650); // 1500 all balls //450 auton one ball 
   intakeState = 5;
   pros::delay(250);
   intakeState = 0;
   trapdoorState = 0;
    pros::delay(150);


   // driving reverse to the matchload
   chassis.moveToPoint(-33, 1.8, 1250, {.forwards=false});
   chassis.waitUntilDone();
   //trapdoorState = 0; //only for 4 on mid
   littleWillState = 1;
   chassis.turnToHeading(182, 1000);
   chassis.waitUntilDone();
   intakeState = 3;
   
   // driving into the matchloader
   chassis.moveToPoint(-32, -14, 1500, {.maxSpeed = 100});
   //chassis.moveToPoint(-32, -8, 500, {.forwards = false});
   pros::delay(300); // wait to intake

   
   // //back up from match loader
   chassis.moveToPoint(-32, 0.4, 1000, {.forwards = false, .maxSpeed = 90});
   chassis.waitUntilDone();
   hoodState = 1;
   littleWillState = 0;

   
   //turn to long goal and score
   trapdoorState = 1;
   pros::delay(500);
   chassis.turnToHeading(-4, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(-33, 17, 1000, {.maxSpeed = 40});
   chassis.waitUntilDone();
   chassis.turnToHeading(3, 500);
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
   pros::delay(850);
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
   chassis.moveToPoint(32.5, -12, 1250);
   //pros::delay(250); // wait to intake

   
   // //back up from match loader
   chassis.moveToPoint(32.5, 0.4, 1000, {.forwards = false, .maxSpeed = 90});
   chassis.waitUntilDone();
   pros::delay(100);
   hoodState = 1;
   littleWillState = 0;

   
   //turn to long goal and score
   trapdoorState = 1;
   pros::delay(500);
   chassis.turnToHeading(4, 1000);
   chassis.waitUntilDone();
   chassis.moveToPoint(33.5, 16.51, 1000, {.maxSpeed = 40});
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
    chassis.moveToPoint(-1.77, 34, 1500, {.maxSpeed=80});
    chassis.waitUntilDone();
    velValue = 12000*0.8;
    intakeState = 2;
    pros::delay(2000);
    velValue = 12000;


    // driving reverse to the matchload
    chassis.moveToPoint(32.5, 1.3, 2000, {.forwards=false});
    chassis.waitUntilDone();
    littleWillState = 1;
    chassis.turnToHeading(-182, 1000);
    chassis.waitUntilDone();
    intakeState = 3;
    
    // driving into the matchloader
    chassis.moveToPoint(31.5, -12, 1250);
    pros::delay(2000); // wait to intake

    
    // //back up from match loader
    chassis.moveToPoint(31.5, 0.4, 1000, {.forwards = false, .maxSpeed = 90});
    chassis.waitUntilDone();
    pros::delay(100);
    hoodState = 1;
    littleWillState = 0;

    
    //turn to long goal and score
    trapdoorState = 1;
    pros::delay(500);
    chassis.turnToHeading(4, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(32.5, 16.51, 1000, {.maxSpeed = 40});
    chassis.turnToHeading(-4, 1000);
    chassis.waitUntilDone();
    hoodState = 1;
    intakeState = 1;
    pros::delay(1500);

    //go to park zone
    chassis.moveToPoint(32, 0.4, 1000, {.forwards = false});
    chassis.turnToHeading(-140, 1000);
    chassis.moveToPose(0, -14, -90, 1000, {.lead = 0.5, .maxSpeed = 90});
    intakeState = 2;
    chassis.moveToPoint(-24, -14, 10000, {.minSpeed = 127});

}

void sawpLow() {
    //go to match loader
    littleWillState = 1;
    intakeState = 3;
    chassis.moveToPoint(0,29, 1000);
    chassis.turnToHeading(88, 750);
    chassis.moveToPoint(4, 29.5, 1000, {.minSpeed = 50});
    pros::delay(750);

    //go back and score long goal
    chassis.moveToPoint(-6, 30.5, 500, {.forwards = false, .maxSpeed = 100});
    intakeState = 0;
    littleWillState = 0;
    hoodState = 1;
    trapdoorState = 1;
    chassis.turnToHeading(-83, 1000, {.maxSpeed = 90});
    chassis.moveToPoint(-16, 32, 1000, {.minSpeed = 50});
    intakeState = 1;
    pros::delay(1500);

    //go to low
    chassis.moveToPoint(-1.97, 31.6, 500, {.forwards = false});
    chassis.turnToHeading(-125, 500);
    intakeState = 3;
    chassis.moveToPoint(-29.6, 2.9, 1000, {.maxSpeed = 40});
    chassis.moveToPoint(-36.9, -1.6, 1000);
    pros::delay(250);
    velValue = 12000*0.8;
    intakeState = 2;
    velValue = 12000;
    pros::delay(1000);

    //other blocks
    chassis.moveToPoint(-26.2, 9.1, 500, {.forwards = false});
    intakeState = 3;
    chassis.turnToHeading(180, 500);
    chassis.moveToPoint(-29, -18, 1000, {.minSpeed = 80});
    chassis.moveToPoint(-29, -38.4, 500, {.maxSpeed = 40}); 

    //long goal
    chassis.turnToHeading(90, 500);
    chassis.moveToPose(-16, -64.8, -90, 2000, {.lead = 0.5});
    chassis.moveToPoint(-18, -65, 1000);
    intakeState = 1;

}

void sawpMid() {
    //go to match loader
    littleWillState = 1;
    intakeState = 3;
    chassis.moveToPoint(0,28.5, 1000);
    chassis.turnToHeading(88, 750);
    chassis.moveToPoint(6, 30, 1000, {.minSpeed = 50});
    pros::delay(500);

    //go back and score long goal
    chassis.moveToPoint(-6, 29.5, 500, {.forwards = false, .maxSpeed = 100});
    intakeState = 0;
    littleWillState = 0;
    hoodState = 1;
    trapdoorState = 1;
    chassis.turnToHeading(-81, 1000, {.maxSpeed = 90});
    chassis.moveToPoint(-16, 31, 1000, {.minSpeed = 50});
    intakeState = 1;
    pros::delay(750); //all blocks 1500
    intakeState = 0;
    trapdoorState = 0;

    //get first clump of blocks
    chassis.moveToPoint(-1.97, 31.6, 500, {.forwards = false});
    chassis.turnToHeading(-125, 500);
    hoodState = 0;
    intakeState = 3;
    chassis.moveToPoint(-15, 18.7, 500, {.minSpeed = 80});
    chassis.moveToPoint(-27, 6.7, 1000, {.maxSpeed = 40}); 
    pros::delay(100);

    // get second clump of blocks
    chassis.turnToHeading(180, 1000);
    chassis.moveToPoint(-27, -18, 1000, {.minSpeed = 80});
    chassis.moveToPoint(-27, -36, 500, {.maxSpeed = 40});
    pros::delay(100); 

    //mid goal
    chassis.turnToHeading(-45, 1000);
    chassis.moveToPoint(-34.8, -30.52, 1000);
    trapdoorState = 1;
    intakeState = 1;
    pros::delay(100); //750 for 3 blocks
    intakeState = 0;
    trapdoorState = 0;

    //long goal
    chassis.moveToPoint(2.8, -64.2, 2000, {.forwards = false});
    hoodState = 1;
    chassis.turnToHeading(-87, 500);
    chassis.moveToPoint(-16, -63.3, 1000);
    trapdoorState = 1;
    intakeState = 1;
}