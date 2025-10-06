 #include "autons.hpp"
 #include <math.h>


void longGoalRight() {

    chassis.turnToHeading(-17, 1000);
    intakeState = 3;
    chassis.moveToPoint(-7.5, 25.4,1500, {.maxSpeed = 60});
    
   // chassis.turnToHeading(40.2, 1500);

    // chassis.turnToHeading(41, 1000);  
    // chassis.moveToPoint(1.7, 33.3, 1500);

    // intakeState = 4; 

    

}

