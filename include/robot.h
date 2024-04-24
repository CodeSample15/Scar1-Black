// define robot ports here
#pragma once

#include "api.h"
#include "EZ-Template/api.hpp"
#include "pros/motors.hpp"

#define RIGHT_MOTOR_1_PORT 1
#define RIGHT_MOTOR_2_PORT 2
#define RIGHT_MOTOR_3_PORT 3
#define RIGHT_MOTOR_4_PORT -4

#define LEFT_MOTOR_1_PORT 7
#define LEFT_MOTOR_2_PORT -8
#define LEFT_MOTOR_3_PORT -9
#define LEFT_MOTOR_4_PORT -10

#define INERTIAL_PORT 6

#define INTAKE_1_PORT 11
#define INTAKE_2_PORT 20

extern pros::Controller master;

extern ez::Drive chassis;

extern pros::Motor Intake1Motor;
extern pros::Motor Intake2Motor;
extern pros::MotorGroup Intake;

extern pros::Imu imu;