#include "main.h"
#include "drivecode/intake.hpp"
#include "drivecode/objects.hpp"
#include "drivecode/util.hpp"
#include "lemlib/chassis/chassis.hpp"
#include "pros/misc.h"
#include "drivecode/color.hpp"
#include "autonomous/autonSelector.hpp"
#include "autonomous/autons.hpp"
#include "pros/motors.h"
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
	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_BRAKE);
	chooseAuton();
}

void opcontrol() {
	chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
	velValue = 12000;
	intakeState = 0;
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