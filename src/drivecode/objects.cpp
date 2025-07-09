#include "main.h"

//motor definitions
pros::Motor bottomRoller(0, pros::MotorGearset::blue);
pros::Motor topRoller(0, pros::MotorGearset::green);
pros::Motor indexer(0, pros::MotorGearset::green);

pros::MotorGroup leftMotors({0, 0, 0}, pros::MotorGearset::blue);
pros::MotorGroup rightMotors({0, 0, 0}, pros::MotorGearset::blue);

//sensor definitions
pros::Optical color(0);
pros::Imu imu(0);
pros::Rotation horizRotation(0);
pros::Rotation vertRotation(0);

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
    3,
    3,
    1,
    100,
    3,
    500,
    20
);

lemlib::ControllerSettings angularController( //TODO: tune error zones, pids
    10,
    0,
    3,
    3,
    1,
    100,
    3,
    500,
    20
);

lemlib::Chassis chassis(
    drivetrain,
    lateralController,
    angularController,
    odomSensors
);

//control definitions
pros::Controller controller(pros::E_CONTROLLER_MASTER);