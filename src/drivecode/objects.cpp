#include "main.h"

//motor definitions
pros::Motor bottomRoller(12, pros::MotorGearset::blue);
pros::Motor topRoller(20, pros::MotorGearset::blue);

pros::MotorGroup leftMotors({-15, -13, -14}, pros::MotorGearset::blue);
pros::MotorGroup rightMotors({19, 18, 17}, pros::MotorGearset::blue);

//piston definitions
pros::ADIDigitalOut littleWill ('C'); 
pros::ADIDigitalOut descore ('A');
pros::ADIDigitalOut trapdoor ('B');
pros::ADIDigitalOut hood('D');
//pros::ADIDigitalOut colorPiston ('D');


//sensor definitions
pros::Optical colorLeft(10); //TODO: fix port
pros::Optical colorRight(3); //TODO: fix port
pros::Distance distance(1);
pros::Imu imu(16);
pros::Rotation horizRotation(4);
pros::Rotation vertRotation(2);
pros::Distance distanceSense(1); 

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
    4.6,
    0,
    0.1,
    3,
    1,
    100,
    3,
    500,
    0
);

lemlib::ControllerSettings angularController( //TODO: tune error zones, pids
    3.35, 
    0,
    26, 
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