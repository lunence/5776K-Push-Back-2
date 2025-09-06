 #include "autons.hpp"
 #include <math.h>

void redSWP() {
    //go to match loader
    chassis.moveToPoint(0, 28,1000, {.maxSpeed = 80});
    chassis.turnToHeading(90, 1000);
    chassis.waitUntilDone();
    littleWillState = 1;
    pros::delay(200);
    leftMotors.move_voltage(12000);
    rightMotors.move_voltage(12000);
    pros::delay(400);

    //perform intaking at matchloader
    intakeState = 5;
    // leftMotors.move_voltage(800);
    // rightMotors.move_voltage(800);
    pros::delay(1000); //decrease
    // leftMotors.move_voltage(0);
    // rightMotors.move_voltage(0);
    // intakeState = 0;
    // pros::delay(100);

    //back away from match loader
    leftMotors.move_voltage(-6000);
    rightMotors.move_voltage(-6000);
    pros::delay(250); //decrease
    leftMotors.move_voltage(0);
    rightMotors.move_voltage(0);
    littleWillState = 0;

    //turn, go to long goal, and score
    chassis.turnToHeading(-90, 1000);
    chassis.waitUntilDone();

    // return;

    trapdoorState = 1;
    chassis.moveToPoint(-20, 28, 1000, {.maxSpeed = 90});

    leftMotors.move_velocity(100);
    rightMotors.move_velocity(100);
    pros::delay(600);

    intakeState = 1;
    pros::delay(1500);
    leftMotors.move_velocity(0);
    rightMotors.move_velocity(0);

    return;

    //go to middle right blocks
    chassis.moveToPoint(0, 28, 1000, {.forwards = false});
    intakeState = 3;
    trapdoorState = 0;
    pros::delay(500);
    intakeState = 5;
    chassis.moveToPose(-23.4, 11.6, -126.8, 2000);
    chassis.turnToHeading(-133, 500);
    chassis.moveToPoint(-24.2, 11, 5000, {.maxSpeed = 20});

    // // blocks jammed -----------
    // // chassis.moveToPose( -28.2, 8.5, 275, 1000, {.lead = 0.4, .maxSpeed = 50}); //change angle
    // // chassis.moveToPoint(-32.4, 8.5, 1000, {.maxSpeed = 50});
    // // blocks jammed -----------

    intakeState = 5;
    // pros::delay(2000);
    //intakeState = 0; 

    //move to center bottom goal and score
    velValue *= 0.4;
    chassis.turnToHeading(-139, 1000);
    chassis.moveToPoint(-38, -1, 1000, {.maxSpeed = 50}); //go further into low goal
    chassis.waitUntilDone();
    chassis.turnToHeading(-139, 1000);
    intakeState = 3;
    pros::delay(1500);



    // //get left blocks 

    // chassis.moveToPoint(-18.2, 17.6, 1000, {.forwards = false});
    // chassis.turnToHeading(-169, 1000);
    // chassis.moveToPoint(-27.19, -27.9, 3000, {.maxSpeed = 80});
    // chassis.moveToPoint(-29.3, -39.3, 3000, {.maxSpeed = 20});

    // pros::delay(1000);
    // chassis.turnToHeading(-42.5, 1000);
    // //chassis.moveToPoint()
}
    