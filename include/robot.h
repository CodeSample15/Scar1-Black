#pragma once

#define ROBOT_WHEEL_DIAM 3.25
#define ROBOT_DRIVE_CART 200
#define ROBOT_GEAR_RATIO 1.6667

#define RIGHT_MOTOR_1_PORT 1
#define RIGHT_MOTOR_2_PORT 2
#define RIGHT_MOTOR_3_PORT 3
#define RIGHT_MOTOR_4_PORT 4

#define INERTIAL_PORT 5
#define STATIC_INERTIAL_PORT 17 //named static because it never get's reset once the bot starts running

#define INTAKE_PORT 6

#define LEFT_MOTOR_1_PORT 7
#define LEFT_MOTOR_2_PORT 8
#define LEFT_MOTOR_3_PORT 9
#define LEFT_MOTOR_4_PORT 10

#define CLIMB_MOTOR_PORT 20

#define LEFT_SLAPPER_MOTOR_PORT 18
#define LEFT_SLAPPER_SENSOR 10 //PLACEHOLDER: CHANGE

#define FRONT_WINGS_PORT 'C'

#define LEFT_BACK_WINGS_PORT 'B'
#define RIGHT_BACK_WINGS_PORT 'A'

#include "main.h"
#include "EZ-Template/api.hpp"

extern ez::Drive chassis;
extern pros::Controller master;