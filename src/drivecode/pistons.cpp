#include "drivecode/pistons.hpp"
#include "drivecode/intake.hpp"

int littleWillState = 0;
int descoreState = 0;
int trapdoorState = 0;

bool rightPressed = false;
bool BPressed = false;
bool YPressed = false;

void updatePistons() {
    //little will
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) { //b
        if(!BPressed) {
            BPressed = true;
            if(littleWillState == 0) {
                littleWillState = 1;
            } else if(littleWillState == 1){
                littleWillState = 0;
            }
        } 
    } else {
        BPressed = false;
    }

    //descore
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) { //right
        if(!YPressed) {
            YPressed = true;
            if(descoreState == 0) {
                descoreState = 1;
            } else if (descoreState == 1){
                descoreState = 0;
            }
        }
    } else {
        YPressed = false;
    }

    //trapdoor
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) { //right
        if(!rightPressed) {
            rightPressed = true;
            if(trapdoorState == 0) {
                trapdoorState = 1;
            } else if (trapdoorState == 1){
                trapdoorState = 0;
            }
        }
    } else {
        rightPressed = false;
    }
    

}

void runPistons() {

    while(true) {
        //little will
        if(littleWillState == 0) {
            littleWill.set_value(false);
            //velValue = 12000;
        } else if(littleWillState == 1) {
            littleWill.set_value(true);
            //velValue = 12000 * 0.6;
        } 
        
        //descore
        if(descoreState == 0) {
            descore.set_value(false);
        } else if(descoreState == 1) {
            descore.set_value(true);
        }

        //trapdoor
        if(trapdoorState == 0) {
            trapdoor.set_value(false);
        } else if(trapdoorState == 1) {
            trapdoor.set_value(true);
        }

        pros::delay(10);
    }
}