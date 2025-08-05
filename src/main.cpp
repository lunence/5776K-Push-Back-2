#include "main.h"
#include "drivecode/intake.hpp"
#include "drivecode/objects.hpp"
#include "drivecode/util.hpp"
#include "pros/misc.h"
#include "drivecode/color.hpp"

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

	taskInit();
	motorInit();
	sensorInit();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	chassis.turnToHeading(45, 5000);
	//chassis.moveToPoint(0, 24, 3000);
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