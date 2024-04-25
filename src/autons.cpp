#include "main.h"
#include "robot.hpp"

// These are out of 127
const int DRIVE_SPEED = 90;  
const int TURN_SPEED = 90;
const int SWING_SPEED = 90;

///
// Constants
///
void default_constants() {
  chassis.pid_heading_constants_set(3, 0, 20);
  chassis.pid_drive_constants_set(10, 0, 100);
  chassis.pid_turn_constants_set(3, 0, 20);
  chassis.pid_swing_constants_set(5, 0, 30);

  chassis.pid_turn_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_swing_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
  chassis.pid_drive_exit_condition_set(300_ms, 1_in, 500_ms, 3_in, 750_ms, 750_ms);

  chassis.slew_drive_constants_set(7_in, 80);
}

void MatchAuton1() 
{
  //run to the other side
    chassis.pid_drive_set(90_in, DRIVE_SPEED, true);
    chassis.pid_wait();

    chassis.pid_turn_set(-45_deg, TURN_SPEED, false);
    chassis.pid_wait();

    chassis.pid_drive_set(10_in, DRIVE_SPEED, true);
    chassis.pid_wait();

    //point towards middle triball
    chassis.pid_turn_relative_set(-90_deg, TURN_SPEED, false);
    chassis.pid_wait();

    //pick up dah triball
    Intake.move(-100);

    chassis.pid_drive_set(50_in, DRIVE_SPEED, true);
    chassis.pid_wait();
}