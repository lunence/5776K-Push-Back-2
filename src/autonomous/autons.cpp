#include "autons.hpp"

void redSWP() {
    //go to match loader
    chassis.moveToPoint(0, 29, 1000);
    littleWillState = 1;
    chassis.turnToHeading(90, 1000);
    chassis.moveToPoint(8, 30.76, 500, {.minSpeed=127});
    chassis.waitUntilDone();
    intakeState = 5;
    pros::delay(1500);
    intakeState = 0;

    //back away from match loader and turn to long goal
    chassis.moveToPoint(-8, 30.76, 1000, {.forwards = false});
    chassis.waitUntilDone();
    littleWillState = 0;
    chassis.turnToHeading(-90, 1000);

    //go to long goal and score
    chassis.moveToPoint(-19, 30.5, 1000);
    chassis.waitUntilDone();
    intakeState = 1;
    pros::delay(1000);

    //go to middle right blocks
    chassis.turnToHeading(209.2, 1000);
    chassis.moveToPoint(-29.5, 9.5, 1000);
}
