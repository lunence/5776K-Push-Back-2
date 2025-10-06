#include "main.h"

//motor definitions
pros::Motor bottomRoller(12, pros::MotorGearset::blue);
pros::Motor topRoller(20, pros::MotorGearset::blue);

pros::MotorGroup leftMotors({-15, -13, -14}, pros::MotorGearset::blue);
pros::MotorGroup rightMotors({19, 18, 17}, pros::MotorGearset::blue);

//piston definitions
pros::ADIDigitalOut littleWill ('B'); 
pros::ADIDigitalOut trapDescore ('H');
//pros::ADIDigitalOut trapdoor ('G');
pros::ADIDigitalOut hood('A');
//pros::ADIDigitalOut colorPiston ('D');


//sensor definitions
pros::Optical colorLeft(12); //TODO: fix port
pros::Optical colorRight(3); //TODO: fix port
pros::Distance distance(1);
pros::Imu imu(16);
pros::Rotation horizRotation(4);
pros::Rotation vertRotation(-11);
pros::Distance distanceSense(1); 

//drivetrain definitions
lemlib::TrackingWheel horizOdom(
    &horizRotation, 
    lemlib::Omniwheel::NEW_2, 
    0
);

lemlib::TrackingWheel vertOdom(
    &vertRotation, 
    lemlib::Omniwheel::NEW_2, 
    0
);

lemlib::OdomSensors odomSensors(
    &vertOdom, //got rid of odom
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
    3.8,
    0,
    0,
    3,
    1,
    100,
    3,
    500,
    0
);

lemlib::ControllerSettings angularController( //TODO: tune error zones, pids
    3.2, 
    0,
    11.5, 
    3,
    1.5,
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