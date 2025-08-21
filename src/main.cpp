#include "main.h"
#include "drivecode/intake.hpp"
#include "drivecode/objects.hpp"
#include "drivecode/util.hpp"
#include "pros/misc.h"
#include "drivecode/color.hpp"
#include "autonomous/autonSelector.hpp"
#include <iostream>

void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

void initialize() {
	pros::lcd::initialize();

	chassis.calibrate();
	// chassis.setPose(0, 0, 0);

	//autonSelector();

	taskInit();
	motorInit();
	sensorInit();
}

void disabled() {

}

void competition_initialize() {
	
}

void autonomous() {
	if(color == 'R') {
		switch(auton) {
			case 1: {
				std::cout<<"red auton 1\n";
				break;
			}
			case 2: {
				std::cout<<"red auton 2\n";
				break;
			}
			case 3: {
				std::cout<<"red auton 3\n";
				break;
			}
		}
	} else if(color == 'B') {
		switch(auton) {
			case 1: {
				std::cout<<"blue auton 1\n";
				break;
			}
			case 2: {
				std::cout<<"blue auton 2\n";
				break;
			}
			case 3: {
				std::cout<<"blue auton 3\n";
				break;
			}
		}
	} else {
		std::cout<<"testing\n";
	}
	
	chassis.turnToHeading(90, 5000);
	// chassis.moveToPoint(0, 24, 1000);
	// chassis.turnToHeading(-90, 1000);
	// chassis.moveToPoint(-24, 24, 1000);
}

void opcontrol() {
	while (true) {
		//subsystems
		updateIntake();
		updatePistons();
		updateColorSort();

		//drive
		//for single stick arcade, turn pros::E_CONTROLLER_ANALOG_RIGHT_X into pros::E_CONTROLLER_DIGITAL_LEFT_X
		//for regular arcade, turn pros::E_CONTROLLER_ANALOG_LEFT_X into pros::E_CONTROLLER_DIGITAL_RIGHT_X
		int throttle = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
		int turn = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
		chassis.arcade(throttle, turn);
		
		//delay
		pros::delay(10);
	}
}