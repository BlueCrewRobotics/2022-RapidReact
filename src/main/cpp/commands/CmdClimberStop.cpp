/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClimberStop.h"

CmdClimberStop::CmdClimberStop(SubClimber *SubClimber) : m_subClimber(SubClimber)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(SubClimber);
}

// Called when the command is initially scheduled.
void CmdClimberStop::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClimberStop::Execute()
{
  // Move Climber to set position
  m_subClimber->MoveClimber(0);
}

// Called once the command ends or is interrupted.
void CmdClimberStop::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClimberStop::IsFinished()
{
  return true;
}
