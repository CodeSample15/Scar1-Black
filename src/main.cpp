#define TESTING_AUTON false //PLEASE PLEASE PLEASE PLEASE ALWAYS SET TO FALSE OUTSIDE OF THE LAB, GONNA LOOK SO STUPID IF YOU DONT

#include "main.h"
#include "robot.h"
#include "jank-lib/AutonSelector.h"

//autons
#include "autons/MatchAuton1.hpp"

#include "okapi/api.hpp"

using namespace pros;

bool selectingAuton = false;
JAutonSelector selector;

void select_auton_thread() {
	if(selectingAuton)
		return; //no duplicate threads please

	selectingAuton = true;
	bool updateScreen = true;

	master.clear();
	delay(60);

	//Allow the user to select an auton
	while(selectingAuton) {
		if(updateScreen) {
			selector.display_autons(); //update screen
			updateScreen = false;
		}

		if(master.get_digital_new_press(E_CONTROLLER_DIGITAL_UP)) {
			selector.iterate();
			updateScreen = true;
		}

		delay(10);
  	}
}

void initialize() {
	delay(500);

	//add all of the autons here
	//selector.add("AWP")
	//selector.add("Kill all", "humans")
	//selector.add("Launch", "Warheads")

	//pid stuff
	chassis.pid_heading_constants_set(4, 1, 20);
	chassis.pid_drive_constants_set(3.8, 0, 20);
	chassis.pid_turn_constants_set(2.5, 0, 20);
	chassis.pid_swing_constants_set(5, 0, 30);

	chassis.pid_turn_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
	chassis.pid_swing_exit_condition_set(300_ms, 3_deg, 500_ms, 7_deg, 750_ms, 750_ms);
	chassis.pid_drive_exit_condition_set(300_ms, 1_in, 500_ms, 3_in, 750_ms, 750_ms);

	chassis.slew_drive_constants_set(10_in, 50);

	chassis.initialize();

	ez::as::initialize();
}

void disabled() {}


void competition_initialize() {
	if(!selectingAuton) {
		chassis.pid_targets_reset(); // Resets PID targets to 0
		chassis.drive_imu_reset(); // Reset gyro position to 0
		chassis.drive_sensor_reset(); // Reset drive sensors to 0
		chassis.drive_brake_set(MOTOR_BRAKE_HOLD);

		Task t(select_auton_thread);
	}
}


void autonomous() {
	selectingAuton = false;

	switch(selector.getSelected()) 
	{
		case 0:
			//run auton
			break;
	}
}

void opcontrol() {

	if(TESTING_AUTON) {
		chassis.drive_imu_calibrate();
		matchAuton1();
	}

	chassis.drive_brake_set(E_MOTOR_BRAKE_COAST);

	while(!selectingAuton) {
		chassis.opcontrol_arcade_standard(ez::SPLIT);

		//intake
		if(master.get_digital(E_CONTROLLER_DIGITAL_R1))
			Intake.move(-100);
		else if(master.get_digital(E_CONTROLLER_DIGITAL_R2))
			Intake.move(100);
		else
			Intake.brake();

		delay(ez::util::DELAY_TIME);
	}
}
