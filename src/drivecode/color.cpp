#include <iostream>
#include <queue>
#include "drivecode/color.hpp"

int sortState = 2; //change back to 0
bool sortButtonPressed = false;
std::queue<bool> wrongColor;
bool prevWrong = false;
bool blockDetected = false;

// void waitUntilCorrect(char color) {
//     if(color == 'R') {
//         while(!(0 < lowerColor.get_hue() && lowerColor.get_hue() < 25)) {
//             std::cout<<"waiting\n";
//             pros::delay(10);
//         }
//         std::cout<<"done\n";
//     } else if(color == 'B') {
//         while(!(200 < lowerColor.get_hue() && lowerColor.get_hue() < 240)) {
//             pros::delay(10);
//         }
//     }
// }

void updateColorSort() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) { //cycle color sort modes
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
        if(sortState == 0) { //if no sort, run nothing
            pros::delay(10);
            continue;
        }

        if(sortState == 1) { //score red, sort blue
            if(0 < lowerColor.get_hue() && lowerColor.get_hue() < 25) { //if a red block is detected,
                if(!blockDetected) { //for the first time (toggle style logic),
                    blockDetected = true;
                    wrongColor.push(false); //push a red block (false) to queue
                    // std::cout<<wrongColor.back()<<"   I SAW RED "<<"\n";
                }
            } else if(200 < lowerColor.get_hue() && lowerColor.get_hue() < 240) { //if a blue block is detected,
                if(!blockDetected) { //and a ring hasn't been detected yet,
                    blockDetected = true;
                    wrongColor.push(true); //push a blue block (true) to queue
                    // std::cout<<wrongColor.back()<<"   I SAW BLUE "<<"\n";
                }
            } else {
                blockDetected = false;
            }
        }

        if(sortState == 2) { //score blue, sort red
            if(0 < lowerColor.get_hue() && lowerColor.get_hue() < 25) { //if a red block is detected,
                if(!blockDetected) { //for the first time (toggle style logic),
                    blockDetected = true;
                    wrongColor.push(true); //push a red block (true) to queue
                    std::cout<<wrongColor.back()<<"   I SAW RED "<<"\n";

                }
            } else if(200 < lowerColor.get_hue() && lowerColor.get_hue() < 240) { //if a blue block is detected,
                if(!blockDetected) { //and a ring hasn't been detected yet,
                    blockDetected = true;
                    wrongColor.push(false); //push a blue block (false) to queue
                    std::cout<<wrongColor.back()<<"   I SAW BLUE "<<"\n";
                }
            } else {
                blockDetected = false;
            }
        }


        if((intakeState == 5 || intakeState == 6) && !wrongColor.empty()) {
            if(wrongColor.front()) {
                intakeState = 6;
                prevWrong = true;
                //pros::delay(500);
                //intakeState = 5;
                std::cout<<"outtake\n";
            } else if(!wrongColor.front()) {
                // if(prevWrong) {
                //     waitUntilCorrect('R'); 
                // }
                intakeState = 5;
                prevWrong = false;
                std::cout<<"bucket\n";
            }
            wrongColor.pop();
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

void outtakeUntilCorrect(char color, int timeout) {
    int timeElapsed = 0;
    bool colorDetected = false;
    if(color == 'B') {
        while(true) {
            if(lowerColor.get_hue() > 0 && lowerColor.get_hue() < 20) { //if hue is red
                if(!colorDetected) { //"toggle" logic
                    intakeState = 3;
                }
                colorDetected = true;
            } else if(lowerColor.get_hue() > 200 && lowerColor.get_hue() < 240) {
                if(!colorDetected) { //"toggle" logic
                    intakeState = 1;
                    pros::delay(500);
                    intakeState = 0;
                    break;
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

    if(color == 'R') {
        while(true) {
            if(lowerColor.get_hue() > 200 && lowerColor.get_hue() < 240) { //if hue is red
                if(!colorDetected) { //"toggle" logic
                    intakeState = 3;
                }
                colorDetected = true;
            } else if(lowerColor.get_hue() > 200 && lowerColor.get_hue() < 240) {
                if(!colorDetected) { //"toggle" logic
                    intakeState = 1;
                    pros::delay(500);
                    intakeState = 0;
                    break;
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