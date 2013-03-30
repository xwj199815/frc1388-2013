// RobotBuilder Version: 0.0.2
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in th future.
#include "Robot.h"
#include "GitVersion.h"
#include "InsightLT/Line.h"
#include "Commands/DriveWithJoystick.h"
#include "Commands/RunShooter.h"
#include "Commands/Climb.h"
#include "DriverStation.h"
#include "Commands/Shoot.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
DriveTrain* Robot::driveTrain = 0;
Feeder* Robot::feeder = 0;
Climber* Robot::climber = 0;
OI* Robot::oi = 0;
Shooter* Robot::shooter = 0;
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INITIALIZATION
/**
 * Initialize all members that need initialization.
 */
Robot::Robot():
	mDisplay(insight::FOUR_ZONES),
	disp_GitVersion(""),
	disp_BuildDate("Built on "),
	disp_BattVoltage("Bat:"),
	disp_ShootVoltage("Shoot:"),
	disp_Distance(" Dst:")
{
}
void Robot::GlobalInit()
{
}
void Robot::GlobalPeriodic()
{
	
	timesinceinit = time.Get();
	hasperiodpassed = period.HasPeriodPassed(1);
	shootvoltage = Robot::shooter->voltageOut;
	distance = Robot::driveTrain->getDistance();
	battvoltage = DriverStation::GetInstance()->GetBatteryVoltage();
	
	if((timesinceinit > 10) && (hasperiodpassed == true))
	{
		mDisplay.registerData(disp_BattVoltage, 1);
		mDisplay.registerData(disp_ShootVoltage, 3);
		mDisplay.registerData(disp_Distance, 2);
		mDisplay.registerData(disp_GitVersion, 4);
		disp_BattVoltage.setData(battvoltage);
		disp_ShootVoltage.setData(shootvoltage);
		disp_Distance.setData(distance);
	}
	// Update the SmartDashboard
	smartTimer.Start();
	smartDashboardRefresh = smartTimer.HasPeriodPassed(1);
	
	if(smartDashboardRefresh == true)
		{
		SmartDashboard::PutNumber("Distance",distance);
		SmartDashboard::PutNumber("Battery Voltage", battvoltage);
		}
	SmartDashboard::PutNumber("ShooterVoltage", shootvoltage);
	
	if(shooter->isMotorRunning() == true)
		SmartDashboard::PutBoolean("Shooter", true);
	else
		SmartDashboard::PutBoolean("Shooter", false);
}
void Robot::RobotInit() {
	GlobalInit();
	printf("Initialize the Display \n");
		mDisplay.registerData(disp_GitVersion, 1);
		mDisplay.registerData(disp_BuildDate,3);
		mDisplay.startDisplay();
		mDisplay.setZoneScrollTime(3, 1500);
		disp_GitVersion.setData(GIT_VERSION);
		disp_BuildDate.setData(BUILD_DATE);
	printf("Done initializing \n");
	printf("Timer reset \n");
	time.Reset();
	time.Start();
	period.Reset();
	period.Start();
	RobotMap::init();
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	driveTrain = new DriveTrain();
	feeder = new Feeder();
	climber = new Climber();
	shooter = new Shooter();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
	// This MUST be here. If the OI creates Commands (which it very likely
	// will), constructing it during the construction of CommandBase (from
	// which commands extend), subsystems are not guaranteed to be
	// yet. Thus, their requires() statements may grab null pointers. Bad
	// news. Don't move it.
	oi = new OI();
	lw = LiveWindow::GetInstance();
//	printf("From Robot.cpp driveTrain is:%x\n",Robot::driveTrain);
	// instantiate the command used for the autonomous period
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	autonomousCommand = new AutonomousCommand();
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=AUTONOMOUS
	
	// Print version information		
	string gitVersion = GIT_VERSION;		
	if (strlen(GIT_TAG)) {		
		gitVersion += " (";		
		gitVersion += GIT_TAG;
		gitVersion += ")";
		
		// Update display in the InsightLT
		disp_GitVersion.setData(gitVersion);
  }
	// Display on NetConsole:		
	printf("\nSW version: %s\n", gitVersion.c_str());
	printf("Built on %s %s\n\n", BUILD_DATE, BUILD_TIME);
	
	// Display on SmartDashboard:		
	SmartDashboard::PutString("Software Version: ", gitVersion);
  }
	
void Robot::DisabledInit(){
	GlobalInit();
	SmartDashboard::PutBoolean("Shooter", false);
	
}
void Robot::DisabledPeriodic(){
	GlobalPeriodic();
}
void Robot::AutonomousInit() {
	GlobalInit();
	if (autonomousCommand != NULL)
		autonomousCommand->Start();
}
	
void Robot::AutonomousPeriodic() {
	GlobalPeriodic();
	Scheduler::GetInstance()->Run();
}
	
void Robot::TeleopInit() {
	GlobalInit();
	
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to 
	// continue until interrupted by another command, remove
	// this line or comment it out.
	autonomousCommand->Cancel();
	(new RunShooter())->Start();
	(new Shoot())->Start();
	//SmartDashboard::PutNumber("shooteradded", )
	
}
void Robot::TeleopPeriodic() {
	GlobalPeriodic();
	if (autonomousCommand != NULL)
		Scheduler::GetInstance()->Run();
}
void Robot::TestInit(){
	GlobalInit();
}
void Robot::TestPeriodic() {
	GlobalPeriodic();
	lw->Run();
	
}
START_ROBOT_CLASS(Robot);
