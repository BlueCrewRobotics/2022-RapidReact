/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdStopShooterWheels.h"

CmdStopShooterWheels::CmdStopShooterWheels(SubShooter* subShooter) : m_subShooter(subShooter) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subShooter);
}

// Called when the command is initially scheduled.
void CmdStopShooterWheels::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdStopShooterWheels::Execute() {
  // Send 0 speed to the shooter wheels
  m_subShooter->SetShooterWheelSpeed(0,0);

}

// Called once the command ends or is interrupted.
void CmdStopShooterWheels::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdStopShooterWheels::IsFinished() {
  return true;
}
