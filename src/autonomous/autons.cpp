 #include "autons.hpp"

void redSWP() {
    //go to match loader
    chassis.moveToPoint(0, 27.5, 1000);
    littleWillState = 1;
    chassis.turnToHeading(90, 1000);
    chassis.moveToPoint(8, 29.2, 500, {.minSpeed=127});
    chassis.waitUntilDone();
    //chassis.turnToHeading(95, 500, {.earlyExitRange = 3});
    chassis.turnToHeading(90, 500);
    intakeState = 5;
    pros::delay(1500); //decrease
    intakeState = 0;

    //back away from match loader and turn to long goal
    chassis.moveToPoint(-7, 29.7, 1000, {.forwards = false});
    chassis.waitUntilDone();
    littleWillState = 0;
    trapdoorState = 1;
    chassis.turnToHeading(-91, 1000);

    //go to long goal and score
    chassis.moveToPoint(-20, 30.5, 1000);
    chassis.waitUntilDone();
    intakeState = 1;
    pros::delay(1000);

    //go to middle right blocks
    chassis.moveToPoint(-1, 28, 1000, {.forwards = false});
    chassis.moveToPose( -28.2, 8.5, 275, 1000, {.lead = 0.4, .maxSpeed = 60}); //change angle
    chassis.moveToPoint(-32.4, 8.5, 1000, {.maxSpeed = 60});
    intakeState = 5;
    pros::delay(2000);
    intakeState = 0; 

    //move to center bottom goal and score
    chassis.turnToHeading(218.1, 1000);
    chassis.moveToPoint(-40.5, -1.6, 1000); //go further into low goal
    chassis.waitUntilDone();
    intakeState = 3;
    pros::delay(1000);
    intakeState = 5; 

    // //get left blocks 
    // chassis.moveToPoint(-30, 14.8, 1000, {.forwards = false});
    // chassis.turnToHeading(180, 1000);
    // chassis.moveToPoint(-29.89, -42.2, 3000, {.maxSpeed = 80});
    // pros::delay(1000);
    // chassis.turnToHeading(-42.5, 1000);
    // //chassis.moveToPoint()
}
    