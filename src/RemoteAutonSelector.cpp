/*
  Author: Luke Crimi
  File: R_AutonSelector.cpp
  Date Created: 1/30/2022
  
  Use this class to easily select autons in the preauton function
*/

#include <vector>
#include <cstring>
#include "RemoteAutonSelector.h"
#include "robot.h"

R_AutonSelector::R_AutonSelector() 
{
  R_AutonSelector::selected = 0;
  R_AutonSelector::numberOfAutons = 0;
}

R_AutonSelector::R_AutonSelector(int start)
{
  R_AutonSelector::selected = start;
  R_AutonSelector::numberOfAutons = 0;
}

R_AutonSelector::~R_AutonSelector() 
{
  //clear vectors
  R_AutonSelector::autons.clear();
  R_AutonSelector::descriptions.clear();
}

//return the selected auton
int R_AutonSelector::getSelected() 
{
  return R_AutonSelector::selected;
}

void R_AutonSelector::add(std::string name, std::string description, std::string description2)
{
  R_AutonSelector::numberOfAutons++;

  R_AutonSelector::autons.push_back(name);

  std::vector<std::string> stringVector;
  stringVector.push_back(description);
  stringVector.push_back(description2);
  R_AutonSelector::descriptions.push_back(stringVector);
}

//change the current selected auton and give haptic feedback to the driver
void R_AutonSelector::iterate() 
{
  R_AutonSelector::selected++;

  if(R_AutonSelector::selected >= R_AutonSelector::numberOfAutons)
    R_AutonSelector::selected = 0;

  master.rumble(".");
}

//display the current auton on the remote screen
void R_AutonSelector::display_autons() 
{
  master.clear();
  pros::delay(50);
  master.clear();
  pros::delay(50);

  master.print(0, 0, "%s", R_AutonSelector::autons[R_AutonSelector::selected].c_str());
  pros::delay(50);
  master.print(1, 0, "%s", R_AutonSelector::descriptions[R_AutonSelector::selected][0].c_str());
  pros::delay(50);
  master.print(2, 0, "%s", R_AutonSelector::descriptions[R_AutonSelector::selected][1].c_str());
  pros::delay(50);
}