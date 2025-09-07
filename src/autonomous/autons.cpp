 #include "autons.hpp"
 #include <math.h>

void longGoalRight() {
    //go to match loader
    chassis.moveToPoint(0, 29,1500, {.maxSpeed = 80});
    chassis.turnToHeading(90, 1000);
    chassis.waitUntilDone();
    littleWillState = 1;
    pros::delay(200);
    leftMotors.move_voltage(10000);
    rightMotors.move_voltage(10000);
    pros::delay(500);
    intakeState = 5;
    leftMotors.move_voltage(-1000);
    rightMotors.move_voltage(-1000);
    pros::delay(250);
    leftMotors.move_voltage(10000);
    rightMotors.move_voltage(10000);
    pros::delay(200);
    leftMotors.move_voltage(0);
    rightMotors.move_voltage(0);
    // pros::delay(250);
    // leftMotors.move_voltage(6000);
    // rightMotors.move_voltage(6000);

    //perform intaking at matchloader
    // leftMotors.move_voltage(800);
    // rightMotors.move_voltage(800);
    pros::delay(500); //decrease
    // leftMotors.move_voltage(0);
    // rightMotors.move_voltage(0);
    // intakeState = 0;
    // pros::delay(100);

    chassis.setPose(10, 29, chassis.getPose().theta);

    //back away from match loader
    leftMotors.move_voltage(-6000);
    rightMotors.move_voltage(-6000);
    pros::delay(250); //decrease
    leftMotors.move_voltage(0);
    rightMotors.move_voltage(0);
    pros::delay(250);
    littleWillState = 0;

    //turn, go to long goal, and score
    chassis.turnToHeading(-85.6, 1000);
    chassis.waitUntilDone();

    // return;

    trapdoorState = 1;
    //chassis.moveToPoint(-20, 28, 1000, {.maxSpeed = 90});

    leftMotors.move_voltage(5000);
    rightMotors.move_voltage(5000);
    pros::delay(1000);

    intakeState = 1;
    //pros::delay(1500);
    leftMotors.move_voltage(0);
    rightMotors.move_voltage(0);

    // pros::delay(250);
    // intakeState = 3;
    // pros::delay(50);
    // intakeState = 1;
    pros::delay(1000);
    return;

}

void longGoalLeft() {
    //go to match loader
    chassis.moveToPoint(0, -29,1000, {.maxSpeed = 80});
    chassis.turnToHeading(-90, 1000);
    chassis.waitUntilDone();
    littleWillState = 1;
    pros::delay(200);
    leftMotors.move_voltage(10000);
    rightMotors.move_voltage(10000);
    pros::delay(500);
    leftMotors.move_voltage(-1000);
    rightMotors.move_voltage(-1000);
    pros::delay(250);
    leftMotors.move_voltage(10000);
    rightMotors.move_voltage(10000);
    pros::delay(200);
    leftMotors.move_voltage(0);
    rightMotors.move_voltage(0);
    // pros::delay(250);
    // leftMotors.move_voltage(6000);
    // rightMotors.move_voltage(6000);

    //perform intaking at matchloader
    intakeState = 5;
    // leftMotors.move_voltage(800);
    // rightMotors.move_voltage(800);
    pros::delay(500); //decrease
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
    pros::delay(250);
    littleWillState = 0;

    //turn, go to long goal, and score
    chassis.turnToHeading(86, 1000);
    chassis.waitUntilDone();

    // return;

    trapdoorState = 1;
    //chassis.moveToPoint(-20, 28, 1000, {.maxSpeed = 90});

    leftMotors.move_voltage(5000);
    rightMotors.move_voltage(5000);
    pros::delay(1000);

    intakeState = 1;
    //pros::delay(1500);
    leftMotors.move_voltage(0);
    rightMotors.move_voltage(0);

    return;

}

void redSWP() {
    longGoalRight();

    //go to middle right blocks
    chassis.moveToPoint(0, 30, 1000, {.forwards = false});
    intakeState = 3;
    trapdoorState = 0;
    pros::delay(500);
    intakeState = 5;
    chassis.moveToPose(-15.8, 10.6, -116.8, 2000);
    chassis.moveToPoint(-32.72, 2.9, 1000, {.maxSpeed = 50});
    

    //move to center bottom goal and score
    velValue *= 0.4;
    chassis.turnToHeading(-128.6, 500);
    chassis.moveToPoint(-44.2, -7.4, 1500, {.maxSpeed = 50}); //go further into low goal
    chassis.waitUntilDone();
    //chassis.turnToHeading(-139, 1000);
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
    
void skills() {
    leftMotors.move_voltage(-12000);
    rightMotors.move_voltage(-12000);
    pros::delay(1000);
    leftMotors.move_voltage(0);
    rightMotors.move_voltage(0);
}