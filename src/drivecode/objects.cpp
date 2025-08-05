#include "main.h"

//motor definitions
pros::Motor bottomRoller(11, pros::MotorGearset::blue);
pros::Motor topRoller(-12, pros::MotorGearset::blue);
pros::Motor indexer(15, pros::MotorGearset::green);

pros::MotorGroup leftMotors({-10, -9, -3}, pros::MotorGearset::blue);
pros::MotorGroup rightMotors({20, 8, 7}, pros::MotorGearset::blue);

//piston definitions
pros::ADIDigitalOut littleWill ('A'); //not correct pls fix later
pros::ADIDigitalOut hood ('B');
pros::ADIDigitalOut trapdoor ('C');

//sensor definitions
pros::Optical upperColor(0); //TODO: fix port
pros::Optical lowerColor(1); //TODO: fix port
pros::Imu imu(16);
pros::Rotation horizRotation(-19);
pros::Rotation vertRotation(2);

//drivetrain definitions
lemlib::TrackingWheel horizOdom(
    &horizRotation, 
    lemlib::Omniwheel::NEW_2, 
    -2.637
);

lemlib::TrackingWheel vertOdom(
    &vertRotation, 
    lemlib::Omniwheel::NEW_2, 
    0
);

lemlib::OdomSensors odomSensors(
    &vertOdom,
    nullptr,
    &horizOdom,
    nullptr,
    &imu
);

lemlib::Drivetrain drivetrain(
    &leftMotors,
    &rightMotors,
    0,
    lemlib::Omniwheel::NEW_325,
    450,   
    8
);

lemlib::ControllerSettings lateralController( //TODO: tune error zones, pids
    10,
    0,
    10,
    3,
    1,
    100,
    3,
    500,
    0
);

lemlib::ControllerSettings angularController( //TODO: tune error zones, pids
    3.8,
    0,
    18.7,
    3,
    1,
    100,
    3,
    500,
    0
);

lemlib::Chassis chassis(
    drivetrain,
    lateralController,
    angularController,
    odomSensors
);

//control definitions
pros::Controller controller(pros::E_CONTROLLER_MASTER);