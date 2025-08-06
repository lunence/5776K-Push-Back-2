#include <iostream>
#include "drivecode/intake.hpp"
#include "drivecode/pistons.hpp"

int intakeState = 0;

int velValue = 12000;
bool velButtonPressed = false;

bool l1Pressed = false;
bool l2Pressed = false;
bool r1Pressed = false;
bool downPressed = false;
bool bPressed = false;

int velState = 0;

void runIntake() {
    while(true) {
        switch(intakeState) {
            case 0: {
                bottomRoller.move_velocity(0);
                topRoller.move_velocity(0);
                indexer.move_velocity(0);
                break;
            }

            case 1: {
                bottomRoller.move_velocity(velValue);
                topRoller.move_velocity(velValue);
                indexer.move_velocity(-velValue);
                break;
            }

            case 2: {
                bottomRoller.move_velocity(velValue);
                topRoller.move_velocity(-velValue);
                indexer.move_velocity(-velValue);
                break;
            }

            case 3: {
                bottomRoller.move_velocity(-velValue);
                topRoller.move_velocity(-velValue);
                indexer.move_velocity(0);
                break;
            }

            case 4: {
                bottomRoller.move_velocity(-velValue);
                topRoller.move_velocity(-velValue);
                indexer.move_velocity(-velValue);
                break;
            }

            case 5: {
                bottomRoller.move_velocity(velValue);
                topRoller.move_velocity(-velValue); //change back to 0 if no color sort and if it affects something
                indexer.move_velocity(velValue);
                break;
            }

            case 6: { //color sort outtake
                bottomRoller.move_velocity(velValue);
                topRoller.move_velocity(-velValue);
                indexer.move_velocity(-velValue);
                break;
            }

        }

        pros::delay(10);
    }
}

void updateIntake() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) { //r2, stop all intake, state 0
        intakeState = 0;
    }
    
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) { //l1, long goal (indexer outtake), state 1
        if(!l1Pressed) {
            l1Pressed = true;
            if (intakeState == 1) {
                intakeState = 0;
            } else {
                intakeState = 1;
            }
        } 
    } else {
        l1Pressed = false;
    }
    
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) { //l2, mid goal (indexer outtake), state 2
        if(!l2Pressed) {
            l2Pressed = true;
            if (intakeState == 2) {
                intakeState = 0;
            } else {
                intakeState = 2;
            }
        }
    } else {
        l2Pressed = false;
    }
    
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) { //r1, low goal (standard), state 3
        if(!r1Pressed) {
            r1Pressed = true;
            if (intakeState == 3) {
                intakeState = 0;
            } else {
                intakeState = 3;
            }
        }
    } else {
        r1Pressed = false;
    }
        
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) { //down, low goal (clear bucket), state 4
        if(!downPressed) {
            downPressed = true;
            if (intakeState == 4) {
                intakeState = 0;
            } else {
                intakeState = 4;
            }
        }
    } else {
        downPressed = false;
    } 
    
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) { //b, load bucket
        if(!bPressed) {
            bPressed = true;
            if (intakeState == 5) {
                intakeState = 0;
            } else {
                intakeState = 5;
            }
        }
    } else {
        bPressed = false;
    }

    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) { //toggle velocity
        if(!velButtonPressed) {
            velButtonPressed = true;
            if(velState == 0) {
                velValue = 12000 * 0.6;
                controller.set_text(0, 0, "60%");

                velState = 1;
            } else if(velState == 1) {
                velValue = 12000;
                controller.set_text(0, 0, "100%");

                velState = 0;
            }
        }
    } else {
        velButtonPressed = false;
    }
}