#include "main.h"
#include "robot.h"
#include "RemoteAutonSelector.h"

using namespace pros;

bool selectingAuton = false;
R_AutonSelector selector;

void select_auton_thread() {
	if(selectingAuton)
		return; //no duplicate threads please

	selectingAuton = true;
	
	//selector.add("AWP");

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
	
}


void disabled() {}


void competition_initialize() {
	if(!selectingAuton) {
		//calibrate here

		Task t(select_auton_thread);
	}
}


void autonomous() {
	selectingAuton = false;

	switch(selector.getSelected()) {
		case 0:
			//run auton
			break;
	}
}


void opcontrol() {
	chassis.drive_brake_set(pros::E_MOTOR_BRAKE_COAST);

	while(!selectingAuton) {
		//run drive code
		chassis.opcontrol_arcade_standard(ez::SPLIT);

		delay(ez::util::DELAY_TIME);
	}
}