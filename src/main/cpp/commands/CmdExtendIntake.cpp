/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdExtendIntake.h"

CmdExtendIntake::CmdExtendIntake(SubIntake *subIntake) : m_subIntake(subIntake)
{
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subIntake);
}

// Called when the command is initially scheduled.
void CmdExtendIntake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdExtendIntake::Execute()
{
  // Move the intake to the home position
  m_subIntake->MoveIntakeToPosition(200);
}

// Called once the command ends or is interrupted.
void CmdExtendIntake::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdExtendIntake::IsFinished()
{
  return true;
}
