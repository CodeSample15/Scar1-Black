#include "robot.h"
#include "EZ-Template/api.hpp"
#include "api.h"

ez::Drive chassis = ez::Drive(
    {LEFT_MOTOR_1_PORT, LEFT_MOTOR_2_PORT, LEFT_MOTOR_3_PORT, LEFT_MOTOR_4_PORT},
    {-RIGHT_MOTOR_1_PORT, -RIGHT_MOTOR_2_PORT, -RIGHT_MOTOR_3_PORT, -RIGHT_MOTOR_4_PORT},
    INERTIAL_PORT,
    ROBOT_WHEEL_DIAM,
    ROBOT_DRIVE_CART,
    ROBOT_GEAR_RATIO
);

pros::Controller master = pros::Controller(pros::E_CONTROLLER_MASTER);