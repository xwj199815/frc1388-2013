// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "OI.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutonGroup.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/Climb.h"
#include "Commands/DriveStraight.h"
#include "Commands/DriveTurn.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/RunDefaultVoltage.h"
#include "Commands/RunShooter.h"
#include "Commands/Shoot.h"
#include "Commands/StopShooter.h"
#include "Commands/TriggerCommand.h"
#include "Commands/VoltageDecrease.h"
#include "Commands/VoltageIncrease.h"
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
OI::OI() {
	// Process operator interface input here.
        // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	opStick = new Joystick(3);
	
	shooterRun = new JoystickButton(opStick, 11);
	shooterRun->WhenPressed(new RunShooter());
	shooterStop = new JoystickButton(opStick, 10);
	shooterStop->WhenPressed(new StopShooter());
	decreaseVoltage = new JoystickButton(opStick, 7);
	decreaseVoltage->WhenPressed(new VoltageDecrease());
	increaseVoltage = new JoystickButton(opStick, 6);
	increaseVoltage->WhenPressed(new VoltageIncrease());
	leftStick = new Joystick(1);
	
	shootNowLeft = new JoystickButton(leftStick, 1);
	shootNowLeft->WhenPressed(new TriggerCommand());
	rightStick = new Joystick(2);
	
	shootNow = new JoystickButton(rightStick, 1);
	shootNow->WhenPressed(new TriggerCommand());
     
        // SmartDashboard Buttons
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
}
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
Joystick* OI::getOpStick() {
	return opStick;
}
Joystick* OI::getLeftStick() {
	return leftStick;
}
Joystick* OI::getRightStick() {
	return rightStick;
}
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
double OI::returnRightYAxis()
{
	double yAxis = rightStick->kYAxis;
	return yAxis;
}
bool OI::returnRightTrigger()
{
	return rightStick->GetTrigger();
}
bool OI::returnLeftTrigger()
{
	return leftStick->GetTrigger();
}
float OI::returnRightXAxis()
{
	return rightStick->GetAxis(Joystick::kXAxis);
}
bool OI::returnTopButton()
{
	return opStick->GetRawButton(3);
}
bool OI::returnBotButton()
{
	return opStick->GetRawButton(2);	
}
