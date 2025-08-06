#include <iostream>
#include <queue>
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

int sortState = 1; //change back to 0
bool sortButtonPressed = false;
std::queue<bool> wrongColor;
bool prevWrong = false;
bool blockDetected = false;

void waitUntilCorrect(char color) {
    if(color == 'R') {
        while(!(0 < lowerColor.get_hue() && lowerColor.get_hue() < 25)) {
            std::cout<<"waiting\n";
            pros::delay(10);
        }
        std::cout<<"done\n";
    } else if(color == 'B') {
        while(!(200 < lowerColor.get_hue() && lowerColor.get_hue() < 240)) {
            pros::delay(10);
        }
    }
}

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

        if(sortState == 1) { //score red, sort blue
            if(0 < lowerColor.get_hue() && lowerColor.get_hue() < 25) { //if a newly detected ring is red,
                if(!blockDetected) { //and a ring hasn't been detected yet,
                    blockDetected = true;
                    wrongColor.push(false);
                    std::cout<<wrongColor.back()<<"   I SAW RED "<<"\n";
                }
            } else if(200 < lowerColor.get_hue() && lowerColor.get_hue() < 240) {
                if(!blockDetected) { //and a ring hasn't been detected yet,
                    blockDetected = true;
                    wrongColor.push(true);
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