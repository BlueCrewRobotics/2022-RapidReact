/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdSetShooterAngle.h"

CmdSetShooterAngle::CmdSetShooterAngle(SubShooter* subShooter) : m_subShooter(subShooter) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subShooter);
}

// Called when the command is initially scheduled.
void CmdSetShooterAngle::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdSetShooterAngle::Execute() {
  //Set the angle of the shooter
  m_subShooter->SetShooterAngle(0.5);

}

// Called once the command ends or is interrupted.
void CmdSetShooterAngle::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdSetShooterAngle::IsFinished() {
  return true;
}
