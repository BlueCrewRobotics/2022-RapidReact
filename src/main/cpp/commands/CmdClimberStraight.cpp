/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClimberStraight.h"

CmdClimberStraight::CmdClimberStraight(SubClimber* subsystem)  : m_subClimber(subsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  //AddRequirements(subsystem);
}

// Called when the command is initially scheduled.
void CmdClimberStraight::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClimberStraight::Execute() {
  m_subClimber->SetClimberStraight();
  m_subClimber->SetClimberMaxPosition(177000);
}

// Called once the command ends or is interrupted.
void CmdClimberStraight::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClimberStraight::IsFinished() {
  return true;
}
