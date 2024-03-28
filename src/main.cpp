#include "main.h"
#include "robot.h"
#include "AutonSelector.h"

#include <iostream> //for debugging

using namespace pros;

AutonSelector selector;
bool selectingAuton = false;

void select_auton_thread() 
{
	if(selectingAuton)
		return; //no duplicate threads please

	selectingAuton = true;

	//add the autons to the selector
	selector.add("AWP");


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

void initialize() {}

void disabled() {}

void competition_initialize() 
{
	if(!selectingAuton) {
		//calibrate

		//start auton selection thread
		Task t(select_auton_thread);
	}
}

void autonomous() {
	selectingAuton = false;

	switch(selector.getSelected()) {
		case 0:
			//run auton
			break;

		default:
			std::cout << "Auton not found" << std::endl;
			break;
	}
}

void opcontrol() {
	while(!selectingAuton) {
		delay(10);
	}
}
