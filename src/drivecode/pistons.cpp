#include "drivecode/pistons.hpp"
#include "drivecode/intake.hpp"

int littleWillState = 0;
int descoreState = 0;
int trapdoorState = 0;
int colorPistonState = 0;
int triggerval = 30;
int distanceval = 0;

bool littleWillPressed = false;
bool descorePressed = false;
bool trapPressed = false;

void updatePistons() {
    //little will
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_B)) { //b
        if(!littleWillPressed) {
            littleWillPressed = true;
            if(littleWillState == 0) {
                littleWillState = 1;
            } else if(littleWillState == 1){
                littleWillState = 0;
            }
        } 
    } else {
        littleWillPressed = false;
    }

    //descore
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_Y)) { //right
        if(!descorePressed) {
            descorePressed = true;
            if(descoreState == 0) {
                descoreState = 1;
            } else if (descoreState == 1){
                descoreState = 0;
            }
        }
    } else {
        descorePressed = false;
    }

    //trapdoor
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_RIGHT)) { //right
        if(!trapPressed) {
            trapPressed = true;
            if(trapdoorState == 0) {
                trapdoorState = 1;
            } else if (trapdoorState == 1){
                trapdoorState = 0;
            }
        }
    } else {
        trapPressed = false;
    } 

}

void trapdooreject() {
    //distanceval = distance.get();
    if (distance.get()<=30) {
        //trapdoorState = 1;
        topRoller.move_voltage(0);
        //pros::delay(20000);
        //trapdoorState = 0;
        //distanceval = distance.get();
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
            trapdooreject();
        }

        //color piston
        if(colorPistonState == 0) {
            colorPiston.set_value(false);
        } else if(colorPistonState == 1) {
            colorPiston.set_value(true);
        }

        pros::delay(10);
    }
}