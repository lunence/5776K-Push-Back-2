#include "drivecode/util.hpp"
#include "drivecode/objects.hpp"
#include <iostream>

//motor brake modes
void motorInit() {
    bottomRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    topRoller.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    indexer.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
    chassis.setBrakeMode(pros::E_MOTOR_BRAKE_COAST);
}

void sensorInit() {
    upperColor.set_led_pwm(100);
    lowerColor.set_led_pwm(100);
}

//begin all tasks
void taskInit() {
    pros::Task screenTask(runScreen, "screen task");
    pros::Task intakeTask(runIntake, "intake task");
    //pros::Task consoleTask(runConsole, "console task");
    pros::Task pistonTask(runPistons, "piston task");
    pros::Task colorTask(runColorSort, "color task");
}

//brain task
void runScreen() {

    while(true) {
        lemlib::Pose pose = chassis.getPose();
        pros::screen::print(pros::E_TEXT_MEDIUM, 1, "x: %.3f", pose.x);
        pros::screen::print(pros::E_TEXT_MEDIUM, 2, "y: %.3f", pose.y);
        pros::screen::print(pros::E_TEXT_MEDIUM, 3, "heading: %.3f", pose.theta);
        pros::screen::print(pros::E_TEXT_MEDIUM, 4, "Lower Color: %.3f", lowerColor.get_hue());
        pros::screen::print(pros::E_TEXT_MEDIUM, 5, "Upper Color: %.3f", upperColor.get_hue());
        pros::screen::print(pros::E_TEXT_MEDIUM, 6, "odom rotations: %.3f", vertRotation.get_position()/36000.0);

        pros::delay(50);
    }
}

//console task
void runConsole() {

    while(true) {
        lemlib::Pose pose = chassis.getPose();

        std::cout<<"X: "<<std::to_string(pose.x)<<"\n";
        std::cout<<"Y: "<<std::to_string(pose.y)<<"\n";
        std::cout<<"Theta: "<<std::to_string(pose.theta)<<"\n";
        std::cout<<"color: "<<lowerColor.get_hue()<<"\n\n";

        pros::delay(500);
    }
}

void runController() {
    
}