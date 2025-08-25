#include "autons.hpp"

void redSWP() {
    //go to match loader
    chassis.moveToPoint(0, 29, 1000);
    littleWillState = 1;
    chassis.turnToHeading(90, 1000);
    chassis.moveToPoint(8, 30.76, 500, {.minSpeed=127});
    chassis.waitUntilDone();
    intakeState = 5;
    pros::delay(1000);
    intakeState = 0;

    //back away from match loader and turn to long goal
    chassis.moveToPoint(-8, 30.76, 1000, {.forwards = false});
    chassis.waitUntilDone();
    littleWillState = 0;
    chassis.turnToHeading(-90, 1000);

    //go to long goal and score
    chassis.moveToPoint(-21, 30.5, 1000);
    chassis.waitUntilDone();
    intakeState = 1;
    pros::delay(1000);

    //go to middle right blocks
    chassis.moveToPoint(-1, 30.5, 1000, {.forwards = false});
    chassis.moveToPose( -28.2, 7.5, 274, 1000, {.lead = 0.4, .maxSpeed = 60});
    chassis.moveToPoint(-36.4, 7.5, 1000, {.maxSpeed = 80});
    pros::delay(2000);
    intakeState = 0; 

    //move to center bottom goal and score
    chassis.turnToHeading(214.9, 1000);
    chassis.moveToPoint(-44.2, -5, 1000);
    chassis.waitUntilDone();
    intakeState = 3;
}
