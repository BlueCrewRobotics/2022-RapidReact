/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdHubSelect.h"

CmdHubSelect::CmdHubSelect(SubShooter *SubShooter, bool select) : m_subShooter(SubShooter), m_select(SubShooter)
{
  // Use addRequirements() here to declare subsystem dependencies.
  //AddRequirements(SubShooter);
}

// Called when the command is initially scheduled.
void CmdHubSelect::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdHubSelect::Execute()
{
  m_subShooter->SelectHub(m_select);
}

// Called once the command ends or is interrupted.
void CmdHubSelect::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdHubSelect::IsFinished()
{
  return true;
}
