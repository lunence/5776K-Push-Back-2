#include "drivecode/color.hpp"

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

void waitUntilIntaked(int number, bool color, int timeout) {
    int timeElapsed = 0;
    int count = 0;
    bool colorDetected = false;

    if(color) { //color true is red
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

    if(!color) {
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