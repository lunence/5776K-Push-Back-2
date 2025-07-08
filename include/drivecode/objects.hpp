#include "lemlib/chassis/chassis.hpp"
#include "main.h"

//motor declarations
extern pros::Motor bottomRoller;
extern pros::Motor indexer;
extern pros::Motor topRoller;

extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;

//sensor declarations
extern pros::Optical color;
extern pros::Imu imu;

//drivetrain declarations
extern lemlib::TrackingWheel horizOdom;
extern lemlib::TrackingWheel vertOdom;
extern lemlib::Drivetrain drivetrain;
extern lemlib::Chassis chassis;

//control declarations
extern pros::Controller controller;

//init functions
void motorInit();