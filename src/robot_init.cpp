//initialize robot components here
#include "main.h"
#include "robot.h"

pros::Controller master = pros::Controller(pros::E_CONTROLLER_MASTER);

ez::Drive chassis = ez::Drive(
    {LEFT_MOTOR_1_PORT, LEFT_MOTOR_2_PORT, LEFT_MOTOR_3_PORT, LEFT_MOTOR_4_PORT},
    {RIGHT_MOTOR_1_PORT, RIGHT_MOTOR_2_PORT, RIGHT_MOTOR_3_PORT, RIGHT_MOTOR_4_PORT},
    INERTIAL_PORT,
    3.25, //wheel diam
    600, //rpm
    0.75 //gear ratio
);

pros::Motor Intake1Motor = pros::Motor(INTAKE_1_PORT);
pros::Motor Intake2Motor = pros::Motor(INTAKE_2_PORT, true);
pros::MotorGroup Intake({Intake1Motor, Intake2Motor});

pros::Imu imu = pros::Imu(INERTIAL_PORT);

