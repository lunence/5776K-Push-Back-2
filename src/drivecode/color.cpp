#include <iostream>
#include "drivecode/color.hpp"

/*

if color sort red
    if color red
        push wrong
    if color blue
        push right

if color sort blue
    if color blue
        push wrong
    if color red
        push right

if detect above bucket
    prev wrong finished
else
    prev wrong not finished

keep track of:
first two blocks in intake
if wrong block is above bucket
if right block is fully scored

if color right
    if prev wrong not finished 
        wait
    intake bucket
if color wrong
    if prev right not bucket
        wait
    intake outake


if sort mid
    if color right
        if prev correct
            dont wait
        if prev wrong
            wait until prev wrong outtake
        set intake top
    if color wrong
        if prev wrong
            dont wait
        if prev correct
            wait until prev correct scored
        set intake mid

*/

int sortState = 0;
bool sortButtonPressed = false;

void updateColorSort() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
        if(!sortButtonPressed) {
            sortState++;
            if(sortState == 3) {
                sortState = 0;
            }
        }

        sortButtonPressed = true;
    } else {
        sortButtonPressed = false;
    }
}

void runColorSort() {
    while(true) {
        // std::cout<<"red: "<<lowerColor.get_rgb().red<<"       "<<"blue: "<<lowerColor.get_rgb().blue<<"       "<<"green: "<<lowerColor.get_rgb().green<<"       \n";
        // if(lowerColor.get_hue() > 0 && lowerColor.get_hue() < 20) {
        //     std::cout<<"red\n";
        // } else if(lowerColor.get_hue() > 200 && lowerColor.get_hue() < 240) {
        //     std::cout<<"blue\n";
        // } else {
        //     std::cout<<"none\n";
        // }

        if(sortState == 0) {
            pros::delay(10);
            continue;
        }

        if(sortState == 1) {
            switch(intakeState) {
                case 0: {
                }

                case 1: {
                }

                case 2: {
                }

                case 3: {
                }

                case 4: {
                }

                case 5: {
                }
            }
        }

        if(sortState == 2) {
            switch(intakeState) {
                case 0: {
                }

                case 1: {
                }

                case 2: {
                }

                case 3: {
                }

                case 4: {
                }

                case 5: {
                }
            }
        }


        pros::delay(10);
    }
}

//'R' = red, 'B' = blue
void waitUntilIntaked(int number, char color, int timeout) {
    int timeElapsed = 0;
    int count = 0;
    bool colorDetected = false;

    if(color == 'R') {
        while(true) {
            if(lowerColor.get_hue() > 0 && lowerColor.get_hue() < 20) { //if hue is red
                if(!colorDetected) { //"toggle" logic
                    count++; //increment count
                    if (count == number) {
                        break;
                    }
                }
                colorDetected = true;
            } else {
                colorDetected = false;
            }

            if(timeout <= timeElapsed * 10) { //timeout
                break;
            }

            pros::delay(10);
        }
    }

    if(color == 'B') {
        while(true) {
            if(lowerColor.get_hue() > 200 && lowerColor.get_hue() < 240) { //if hue is red
                if(!colorDetected) { //"toggle" logic
                    count++; //increment count
                    if (count == number) {
                        break;
                    }
                }
                colorDetected = true;
            } else {
                colorDetected = false;
            }

            if(timeout <= timeElapsed * 10) { //timeout
                break;
            }

            pros::delay(10);
        }
    }
}