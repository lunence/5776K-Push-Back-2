 #include "autons.hpp"

void redSWP() {
    //go to match loader
    chassis.moveToPoint(0, 28, 1000);
    littleWillState = 1;
    chassis.turnToHeading(88, 1000);
    chassis.moveToPoint(10, 29.7, 500, {.minSpeed=127});
    chassis.waitUntilDone();
    //chassis.turnToHeading(95, 500, {.earlyExitRange = 3});
    //chassis.turnToHeading(90, 500);
    intakeState = 5;
    pros::delay(1275); //decrease
    intakeState = 0;

    //back away from match loader and turn to long goal
    chassis.moveToPoint(-7, 30, 1000, {.forwards = false});\
   
    chassis.waitUntilDone();
    littleWillState = 0;
    trapdoorState = 1;
    chassis.turnToHeading(-85, 1000);

    //go to long goal and score
    chassis.moveToPoint(-23, 30.5, 1500);
    chassis.waitUntilDone();
    intakeState = 1;
    pros::delay(1000);

    //go to middle right blocks
    chassis.moveToPoint(-1, 30, 1000, {.forwards = false});
 intakeState = 3;
    pros::delay(500);
    intakeState = 5;


    // chassis.turnToHeading(-126.4, 1000);
    // chassis.moveToPoint(-21, 13.2, 1000);
     trapdoorState = 0;
    chassis.moveToPose(-21, 13.2, -127, 3000, {.earlyExitRange = 3});

    chassis.moveToPoint(-24.2, 11, 5000, {.maxSpeed = 20});

    // // blocks jammed -----------
    // // chassis.moveToPose( -28.2, 8.5, 275, 1000, {.lead = 0.4, .maxSpeed = 50}); //change angle
    // // chassis.moveToPoint(-32.4, 8.5, 1000, {.maxSpeed = 50});
    // // blocks jammed -----------

    intakeState = 5;
    // pros::delay(2000);
    //intakeState = 0; 

    //move to center bottom goal and score
    chassis.turnToHeading(-134.4, 1000);
    chassis.moveToPoint(-39.1, -2.2, 1000); //go further into low goal
    chassis.waitUntilDone();
    chassis.turnToHeading(-134.9, 1000);
    velValue *= 0.8;
    intakeState = 3;
    pros::delay(1000);
    velValue = 12000;
    intakeState = 5; 


    // //get left blocks 

    // chassis.moveToPoint(-18.2, 17.6, 1000, {.forwards = false});
    // chassis.turnToHeading(-169, 1000);
    // chassis.moveToPoint(-27.19, -27.9, 3000, {.maxSpeed = 80});
    // chassis.moveToPoint(-29.3, -39.3, 3000, {.maxSpeed = 20});

    // pros::delay(1000);
    // chassis.turnToHeading(-42.5, 1000);
    // //chassis.moveToPoint()
}
    