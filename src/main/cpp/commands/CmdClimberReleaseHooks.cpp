/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClimberReleaseHooks.h"

CmdClimberReleaseHooks::CmdClimberReleaseHooks(SubClimber* subsystem)  : m_subClimber(subsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  //AddRequirements(subsystem);
}

// Called when the command is initially scheduled.
void CmdClimberReleaseHooks::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClimberReleaseHooks::Execute() {
  m_subClimber->SetHookPosition();
}

// Called once the command ends or is interrupted.
void CmdClimberReleaseHooks::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClimberReleaseHooks::IsFinished() {
  return true;
}
