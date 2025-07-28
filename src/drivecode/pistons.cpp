#include "drivecode/pistons.hpp"

int littleWillState = 0;
int hoodState = 0;

bool UpPressed = false;
bool XPressed = false;

void updatePistons() {
    //little will
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_X)) { //x
        if(!XPressed) {
            XPressed = true;
            if(littleWillState == 0) {
                littleWillState = 1;
            } else if(littleWillState = 1){
                littleWillState = 0;
            }
        } 
    } else {
        XPressed = false;
    }

    //hood
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) { //UP
        if(!UpPressed) {
            UpPressed = true;
            if(hoodState == 0) {
                hoodState = 1;
            } else if (hoodState = 1){
                hoodState = 0;
            }
        }
    } else {
        UpPressed = false;
    }
    //trapdoor

    

}

void runPistons() {
    //little will
    if(littleWillState == 0) {
        littleWill.set_value(false);
    } else if(littleWillState == 1) {
        littleWill.set_value(true);
    } 
    
    //hood
    if(hoodState == 0) {
        hood.set_value(false);
    } else if(hoodState == 1) {
        hood.set_value(true);
    }

    
}