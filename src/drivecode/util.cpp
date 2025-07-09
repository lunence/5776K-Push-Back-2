#include "util.hpp"

//motor brake modes
void motorInit() {
    bottomRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    topRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    indexer.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
}

//begin all tasks
void taskInit() {
    pros::Task screenTask(runScreen, "screen task");
    pros::Task intakeTask(runIntake, "intake task");
}

//brain task
void runScreen() {
    while(true) {
        pros::lcd::print(0, "X: \f", chassis.getPose().x);
        pros::lcd::print(0, "Y: \f", chassis.getPose().y);
        pros::lcd::print(0, "Theta: \f", chassis.getPose().theta);

        pros::delay(50);
    }
}