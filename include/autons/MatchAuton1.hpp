#pragma once

#include "main.h"
#include "autons/MatchAuton1.hpp"
#include "pros/rtos.hpp"
#include "robot.h"

#define DRIVE_SPEED 90
#define TURN_SPEED 90

inline void matchAuton1() 
{
    chassis.pid_targets_reset(); // Resets PID targets to 0
    chassis.drive_imu_reset(); // Reset gyro position to 0
    chassis.drive_sensor_reset(); // Reset drive sensors to 0
    chassis.drive_brake_set(MOTOR_BRAKE_HOLD);

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