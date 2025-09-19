#include <iostream>
#include "drivecode/intake.hpp"
#include "drivecode/pistons.hpp"
#include <iostream>

int intakeState = 0;

int velValue = 12000;
bool velButtonPressed = false;

bool onePressed = 0;
bool twoPressed = false;
bool threePressed = false;
bool fourPressed = false;

int velState = 0;

void runIntake() {
    while(true) {
        //std::cout<<"intake vel: "<<bottomRoller.get_voltage()<<".  expected vel: "<<velValue<<"\n";
        switch(intakeState) {
            case 0: { //stop intake
                bottomRoller.move_voltage(0);
                topRoller.move_voltage(0);
                break;
            }

            case 1: { //long goal
                bottomRoller.move_voltage(velValue);
                topRoller.move_voltage(velValue);
                break; 
            }

            case 2: { //mid goal
                bottomRoller.move_voltage(velValue);
                topRoller.move_voltage(-velValue);
                break;
            }

            case 3: { //low goal
                bottomRoller.move_voltage(-velValue);
                topRoller.move_voltage(-velValue);
                break;
            }

            case 4: { //load intake (only bottom rollers)
                bottomRoller.move_voltage(velValue);
                topRoller.move_voltage(0); 
                break;
            }

        }

        

        pros::delay(10);
    }
}

void updateIntake() {
    // if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) { //r2, stop all intake, state 0
    //     intakeState = 0;
    // }

    std::cout<<"running\n";
    
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1)) { //l1, long goal (indexer outtake), state 1
        std::cout<<"pressed L1\n";
        if(!onePressed) {
            std::cout<<"toggle\n";
            onePressed = 1;
            if (intakeState == 1) {
                intakeState = 0;
            } else {
                intakeState = 1;
            }
        } 
    } else {
        onePressed = 0;
    }
    
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2)) { //l2, mid goal (indexer outtake), state 2
        std::cout<<"pressed L2\n";
        if(!twoPressed) {
            std::cout<<"toggle\n";
            twoPressed = true;
            if (intakeState == 2) {
                intakeState = 0;
            } else {
                intakeState = 2;
            }
        }
    } else {
        twoPressed = false;
    }
    
    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1)) { //r1, low goal (standard), state 3
        if(!threePressed) {
            threePressed = true;
            if (intakeState == 3) {
                intakeState = 0;
            } else {
                intakeState = 3;
            }
        }
    } else {
        threePressed = false;
    }

    if (controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) { //r2, load intake, state 4
        if(!fourPressed) {
            fourPressed = true;
            if (intakeState == 4) {
                intakeState = 0;
            } else {
                intakeState = 4;
            }
        }
    } else {
        fourPressed = false;
    }
        

    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)) { //toggle voltage
        if(!velButtonPressed) {
            velButtonPressed = true;
            if(velState == 0) {
                velValue = 12000 * 0.6;
                velState = 1;
            } else if(velState == 1) {
                velValue = 12000;
                velState = 0;
            }
        }
    } else {
        velButtonPressed = false;
    }
}