#include "drivecode/intake.hpp"

int bottomState = 0;
int topState = 0;
int indexState = 0;

int velValue = 12000;
bool velButtonPressed = false;
bool prevPressed = false;
int velState = 0;

void runIntake() {
    while(true) {
    
        //bottom roller
        if(bottomState == 0) { //rest
            bottomRoller.move_velocity(0);
        } else if (bottomState == 1) { //intake
            bottomRoller.move_velocity(velValue);
        } else if (bottomState == 2) { //outtake
            bottomRoller.move_velocity(-velValue);
        }

        //top roller
        if(topState == 0) { //rest
            topRoller.move_velocity(0);
        } else if (topState == 1) { //spin forward, long goal
            topRoller.move_velocity(velValue);
        } else if (topState == 2) { //spin backward, mid goal / outtake
            topRoller.move_velocity(-velValue);
        }

        //indexer
        if(indexState == 0) {
            indexer.move_velocity(0);
        } else if (indexState == 1) { //index in
            indexer.move_velocity(velValue);
        } else if (indexState == 2) { //index out
            indexer.move_velocity(-velValue);
        }

        pros::delay(10);
    }
}

void updateIntake() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) { //r2, stop all intake
        bottomState = 0;
        topState = 0;
        indexState = 0;
    }
    
    //TODO: add n-key rollover
    else if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) { //l1, long goal
        if(prevPressed == false) {
            if (bottomState == 1 && topState == 1 && indexState == 0) {
                bottomState = 0;
                topState = 0;
                indexState = 0;
            } else {
                bottomState = 1;
                topState = 1;
                indexState = 0;
            }

            prevPressed = true;
        } else {
            prevPressed = false;
        }
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) { //l2, mid goal
        if(prevPressed == false) {
            if (bottomState == 1 && topState == 2 && indexState == 0) {
                bottomState = 0;
                topState = 0;
                indexState = 0;
            } else {
                bottomState = 1;
                topState = 2;
                indexState = 0;
            }

            prevPressed = true;
        } else {
            prevPressed = false;
        }
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) { //r1, low goal
        if(prevPressed == false) {
            if (bottomState == 2 && topState == 2 && indexState == 0) {
                bottomState = 0;
                topState = 0;
                indexState = 0;
            } else {
                bottomState = 2;
                topState = 2;
                indexState = 0;
            }

            prevPressed = true;
        } else {
            prevPressed = false;
        }
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) { //down, low goal + clear bucket 
        if(prevPressed == false) {
            if (bottomState == 2 && topState == 2 && indexState == 2) {
                bottomState = 0;
                topState = 0;
                indexState = 0;
            } else {
                bottomState = 2;
                topState = 2;
                indexState = 2;
            }

            prevPressed = true;
        } else {
            prevPressed = false;
        }
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) { //right, mid goal + clear bucket
        if(prevPressed == false) {
            if (bottomState == 1 && topState == 2 && indexState == 2) {
                bottomState = 0;
                topState = 0;
                indexState = 0;
            } else {
                bottomState = 1;
                topState = 2;
                indexState = 2;
            }

            prevPressed = true;
        } else {
            prevPressed = false;
        }
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) { //y, long goal + clear bucket
        if(prevPressed == false) {
            if (bottomState == 1 && topState == 1 && indexState == 2) {
                bottomState = 0;
                topState = 0;
                indexState = 0;
            } else {
                bottomState = 1;
                topState = 1;
                indexState = 2;
            }

            prevPressed = true;
        } else {
            prevPressed = false;
        }
    } else if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) { //b, load bucket
        if(prevPressed == false) {
            if (bottomState == 1 && topState == 0 && indexState == 1) {
                bottomState = 0;
                topState = 0;
                indexState = 0;
            } else {
                bottomState = 1;
                topState = 0;
                indexState = 1;
            }

            prevPressed = true;
        } else {
            prevPressed = false;
        }
    }

    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_A)) { //toggle velocity
        if(!velButtonPressed) {
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

        velButtonPressed = true;
    } else {
        velButtonPressed = false;
    }
}