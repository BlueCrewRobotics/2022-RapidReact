/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdDriveWithController.h"

CmdDriveWithController::CmdDriveWithController(SubDriveTrain* driveTrain, frc::Joystick *driverController ) 
  : m_driveTrain{driveTrain}, m_driverController{driverController} {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(driveTrain);

}

// Called when the command is initially scheduled.
void CmdDriveWithController::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdDriveWithController::Execute() {

  double speed;
  if(m_driverController->GetRawAxis(AXIS_L_TRIG) > 0)
  {
    speed = -1*m_driverController->GetRawAxis(AXIS_L_TRIG);
  }
  else
  {
    speed = m_driverController->GetRawAxis(AXIS_R_TRIG);
  }

  double rotation;
  if(m_driveTrain->GetDriveTrainGear()==false) {
    rotation = m_driverController->GetRawAxis(AXIS_LX);
  }
  else {
    rotation = m_driverController->GetRawAxis(AXIS_LX)*0.8;
  }

  m_driveTrain->Drive(speed, rotation);
  m_driveTrain->SetMotorCooling(true);

}

// Called once the command ends or is interrupted.
void CmdDriveWithController::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdDriveWithController::IsFinished() {
  return false;
}
