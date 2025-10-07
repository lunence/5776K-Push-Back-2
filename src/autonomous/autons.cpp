 #include "autons.hpp"
 #include <math.h>


void longGoalLeft() {
    trapDescoreState = 1;
    //go to 3 blocks
    chassis.turnToHeading(-17, 1000);
    intakeState = 3;
    chassis.moveToPoint(-7.5, 25.4,1500, {.maxSpeed = 40});

    //go to mid goal
    chassis.turnToHeading(42.9, 1000);
    chassis.moveToPoint(1.27, 33.95, 1500);
    trapDescoreState = 1; 
    pros::delay(2000);
    intakeState = 1;
    pros::delay(350); //auton one ball
    intakeState = 0;
    trapDescoreState = 0;
    pros::delay(150);


    // driving reverse to the matchload
    chassis.moveToPoint(-33, 1.8, 1000, {.forwards=false});
    chassis.waitUntilDone();
    littleWillState = 1;
    chassis.turnToHeading(180, 1000);
    chassis.waitUntilDone();
    intakeState = 3;
    
    // driving into the matchloader
    chassis.moveToPoint(-31.123, -12, 1000);
    pros::delay(3000); // wait to intake

    
    // //back up from match loader
    chassis.moveToPoint(-31.4, 0.4, 1000, {.forwards = false});
    chassis.waitUntilDone();
    hoodState = 1;
    littleWillState = 0;

    
    //turn to long goal and score
    trapDescoreState = 1;
    pros::delay(1500);
    chassis.turnToHeading(-4, 1000);
    chassis.waitUntilDone();
    chassis.moveToPoint(-33, 15.51, 1000, {.maxSpeed = 40});
    chassis.turnToHeading(4, 1000);
    chassis.waitUntilDone();
    hoodState = 1;
    intakeState = 1;




}

