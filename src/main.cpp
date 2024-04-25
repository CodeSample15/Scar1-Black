#include "main.h"
#include "autons.hpp"
#include "robot.hpp"

void initialize() {
  // Print our branding over your terminal :D
  ez::ez_template_print();
  
  pros::delay(500); // Stop the user from doing anything while legacy ports configure

  // Configure your chassis controls
  chassis.opcontrol_curve_buttons_toggle(true); // Enables modifying the controller curve with buttons on the joysticks
  chassis.opcontrol_drive_activebrake_set(0); // Sets the active brake kP. We recommend 2.
  chassis.opcontrol_curve_default_set(0, 0); // Defaults for curve. If using tank, only the first parameter is used. (Comment this line out if you have an SD card!)  
  default_constants(); // Set the drive to your own constants from autons.cpp!

  // Autonomous Selector using LLEMU
  ez::as::auton_selector.autons_add({
    Auton("Match Auton", MatchAuton1),
  });

  // Initialize chassis and auton selector
  chassis.initialize();
  ez::as::initialize();
  master.rumble(".");
}


void disabled() {
  // . . .
}

void competition_initialize() {
  // . . .
}


void autonomous() {
  chassis.pid_targets_reset(); // Resets PID targets to 0
  chassis.drive_imu_reset(); // Reset gyro position to 0
  chassis.drive_sensor_reset(); // Reset drive sensors to 0
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD); // Set motors to hold.  This helps autonomous consistency

  ez::as::auton_selector.selected_auton_call(); // Calls selected auton from autonomous selector
}

void opcontrol() {
  // This is preference to what you like to drive on
  chassis.drive_brake_set(MOTOR_BRAKE_COAST);
  
  while (true) {
    chassis.opcontrol_tank(); // Tank control

    pros::delay(ez::util::DELAY_TIME); // This is used for timer calculations!  Keep this ez::util::DELAY_TIME
  }
}
