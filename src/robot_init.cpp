#include "robot.hpp"

// Chassis constructor
ez::Drive chassis (
  // Left Chassis Ports (negative port will reverse it!)
  //   the first port is used as the sensor
  {7, -8, -9, -10}

  // Right Chassis Ports (negative port will reverse it!)
  //   the first port is used as the sensor
  ,{1, 2, 3, -4}

  // IMU Port
  ,6

  // Wheel Diameter (Remember, 4" wheels without screw holes are actually 4.125!)
  ,3.25

  // Cartridge RPM
  ,600

  // External Gear Ratio (MUST BE DECIMAL) This is WHEEL GEAR / MOTOR GEAR
  ,0.75
);

pros::Motor Intake1Motor = pros::Motor(11);
pros::Motor Intake2Motor = pros::Motor(20, true);
pros::MotorGroup Intake({Intake1Motor, Intake2Motor});