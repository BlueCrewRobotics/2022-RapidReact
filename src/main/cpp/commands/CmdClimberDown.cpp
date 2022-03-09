/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClimberDown.h"

CmdClimberDown::CmdClimberDown(SubClimber* subClimber) : m_subClimber(subClimber) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subClimber);
}

// Called when the command is initially scheduled.
void CmdClimberDown::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClimberDown::Execute() {
  // Move the Climber to the home position
  m_subClimber->MoveClimberToPosition(0);

}

// Called once the command ends or is interrupted.
void CmdClimberDown::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClimberDown::IsFinished() {
  return true;
}
