/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClimberUp.h"

CmdClimberUp::CmdClimberUp(SubClimber *SubClimber) : m_subClimber(SubClimber)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(SubClimber);
}

// Called when the command is initially scheduled.
void CmdClimberUp::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClimberUp::Execute()
{
  // Move Climber to set position
  m_subClimber->MoveClimber(0.9);
}

// Called once the command ends or is interrupted.
void CmdClimberUp::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClimberUp::IsFinished()
{
  return true;
}
