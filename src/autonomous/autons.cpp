 #include "autons.hpp"
 #include <math.h>

void redSWP() {
    //go to match loader
    chassis.moveToPoint(0, 28, 1000, {.maxSpeed = 80});
    chassis.turnToHeading(90, 1000);
    chassis.waitUntilDone();
    littleWillState = 1;
    pros::delay(200);
    leftMotors.move_voltage(12000);
    rightMotors.move_voltage(12000);
    pros::delay(400);

    //perform intaking at matchloader
    intakeState = 5;
    leftMotors.move_voltage(1000);
    rightMotors.move_velocity(1000);
    pros::delay(1100); //decrease
    leftMotors.move_voltage(0);
    rightMotors.move_voltage(0);
    intakeState = 0;

    // if(abs(chassis.getPose().x-28)>3 || abs(chassis.getPose().theta-90)>3 ) { //TODO: did ts work
    //     chassis.setPose(chassis.getPose().x, 29, 90);
    //     std::cout<<"position reset\n";
    // }


    //back away from match loader
    chassis.moveToPoint(-7, 28.9, 1000, {.forwards = false, .maxSpeed = 80});
    chassis.waitUntilDone();
    littleWillState = 0;

    //turn, go to long goal, and score
    chassis.turnToHeading(-90, 1000);
    chassis.waitUntilDone();
    trapdoorState = 1;
    chassis.moveToPoint(-19.95, 31, 1000, {.maxSpeed = 90}); //TODO: did some coord change, undo if no work
    leftMotors.move_velocity(100);
    rightMotors.move_velocity(100);
    pros::delay(600);
    intakeState = 1;
    pros::delay(1500);
    leftMotors.move_velocity(0);
    rightMotors.move_velocity(0);


    //go to middle right blocks
    chassis.moveToPoint(-1, 30, 1000, {.forwards = false});
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
    