#include "color.hpp"
#include "pros/misc.h"


bool colorPressed;
bool colorDetected;
int color = 0;

void updateColorSort() {
    if(controller.get_digital(pros::E_CONTROLLER_DIGITAL_LEFT)){
        if(!colorPressed) { //if the button is pressed
            color++; //add color state by increment of 1
            if(color == 3) { //if 3, run fuction, 
                color = 0; // off
            }
        }
        colorPressed = true; //run function
    } else {
        colorPressed = false; //if not, dont run function
    }
}

// function to update color sort (so like switch color from red to blue to no sort)


//function to run color sort
/*detect the color of the block using hue values.
Red sort: extend the piston to push out red, keep blue
Blue: extend piston to push out blue, keep red

when the hue value is between a certain range (red)
    extend the piston (set piston state)
    retract piston immediately
*/

void runColorSort(){
    while(true) {
        if(color == 0) {
            pros::delay(10);
            continue;
        }
        
        if(color == 1) { //score red, sort blue
            if(200 < colorLeft.get_hue() && colorLeft.get_hue() < 240 || 200 < colorRight.get_hue() && colorRight.get_hue() < 240) {
                if(!colorDetected) {
                    colorDetected = true;
                    
                    colorPistonState = 1;
                    colorPistonState = 0;
                }
                
            } 
            else {
                    colorDetected = false;
                }    
        
        }
            
        if(color == 2) { //score blue, sort red
            if(0 < colorLeft.get_hue() && colorLeft.get_hue() < 25 || 0 < colorRight.get_hue() && colorRight.get_hue() < 25) {
                if(!colorDetected) {
                    colorDetected = true;
                    
                    colorPistonState = 1;
                    colorPistonState = 0;
                }
            }
            else {
                    colorDetected = false;
                }
        }
    }
}