/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdTurnOffShooterLimelight.h"

CmdTurnOffShooterLimelight::CmdTurnOffShooterLimelight(SubLimelightShooter* subsystem) : m_subLimelightShooter(subsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subsystem);
}

// Called when the command is initially scheduled.
void CmdTurnOffShooterLimelight::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdTurnOffShooterLimelight::Execute() {
  m_subLimelightShooter->SetLEDState(1);
}

// Called once the command ends or is interrupted.
void CmdTurnOffShooterLimelight::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdTurnOffShooterLimelight::IsFinished() {
  return true;
}
