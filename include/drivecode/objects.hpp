#include "main.h"

//motor declarations
extern pros::Motor bottomRoller;
extern pros::Motor indexer;
extern pros::Motor topRoller;

extern pros::MotorGroup leftMotors;
extern pros::MotorGroup rightMotors;

//piston declarations
extern pros::ADIDigitalOut littleWill;
extern pros::ADIDigitalOut hood;
extern pros::ADIDigitalOut trapdoor;

//sensor declarations
extern pros::Optical upperColor;
extern pros::Optical lowerColor;
extern pros::Imu imu;

//drivetrain declarations
extern lemlib::TrackingWheel horizOdom;
extern lemlib::TrackingWheel vertOdom;
extern lemlib::Drivetrain drivetrain;
extern lemlib::Chassis chassis;

//control declarations
extern pros::Controller controller;
