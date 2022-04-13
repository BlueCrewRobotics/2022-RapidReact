/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClimberAngled.h"

CmdClimberAngled::CmdClimberAngled(SubClimber* subsystem)  : m_subClimber(subsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  //AddRequirements(subsystem);
}

// Called when the command is initially scheduled.
void CmdClimberAngled::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClimberAngled::Execute() {
  m_subClimber->SetClimberAngled();

}

// Called once the command ends or is interrupted.
void CmdClimberAngled::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClimberAngled::IsFinished() {
  return true;
}
