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
    pros::Task consoleTask(runConsole, "console task");
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

//console task
void runConsole() {
    while(true) {
        std::cout<<"X: "<<std::to_string(chassis.getPose().x)<<"\n";
        std::cout<<"Y: "<<std::to_string(chassis.getPose().y)<<"\n";
        std::cout<<"Theta: "<<std::to_string(chassis.getPose().theta)<<"\n";

        pros::delay(1000);
    }
}