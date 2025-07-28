#include "drivecode/util.hpp"

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
    pros::Task pistonTask(runPistons, "piston task");
}

//brain task
void runScreen() {
    lemlib::Pose pose = chassis.getPose();

    while(true) {
        pros::lcd::print(1, "X: \f", pose.x);
        pros::lcd::print(2, "Y: \f", pose.y);
        pros::lcd::print(3, "Theta: \f", pose.theta);
        pros::lcd::print(4, "Lower Color: \f", 234);
        pros::lcd::print(5, "Upper Color: \f", 234);

        pros::delay(50);
    }
}

//console task
void runConsole() {

    while(true) {
        lemlib::Pose pose = chassis.getPose();

        std::cout<<"X: "<<std::to_string(pose.x)<<"\n";
        std::cout<<"Y: "<<std::to_string(pose.y)<<"\n";
        std::cout<<"Theta: "<<std::to_string(pose.theta)<<"\n\n";

        pros::delay(1000);
    }
}