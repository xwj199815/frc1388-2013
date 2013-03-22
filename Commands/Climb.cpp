// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Climb.h"
Climb::Climb() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::climber);
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}
// Called just before this Command runs the first time
void Climb::Initialize() {
	
}
// Called repeatedly when this Command is scheduled to run
void Climb::Execute() {
	Joystick* opstick = Robot::oi->getOpStick();
	
	float opsticky = opstick->GetAxis(Joystick::kYAxis);
	float opstickx = opstick->GetAxis(Joystick::kXAxis);
	bool opTapesIn = opstick->GetRawButton(2);
	bool opTapesOut = opstick->GetRawButton(3);
	bool limitOverrideL = opstick->GetRawButton(8);
	bool limitOverrideR = opstick->GetRawButton(9);
	bool TapesEnabled = true;
	bool tapeLimitLeft = RobotMap::climberTapeLimitLeft->Get();
	bool tapeLimitRight = RobotMap::climberTapeLimitRight->Get();
	Robot::climber->TapesInOut(opstickx, opTapesIn, opTapesOut, TapesEnabled, tapeLimitLeft, tapeLimitRight, limitOverrideL, limitOverrideR);
	Robot::climber->TapesUpDown(opsticky, opTapesIn, opTapesOut, TapesEnabled);
	
	
			
	
}
// Make this return true when this Command no longer needs to run execute()
bool Climb::IsFinished() {
	return false;
}
// Called once after isFinished returns true
void Climb::End() {
	
}
// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Climb::Interrupted() {
}
