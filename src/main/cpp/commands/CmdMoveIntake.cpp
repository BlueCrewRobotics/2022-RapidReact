/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdMoveIntake.h"

CmdMoveIntake::CmdMoveIntake(SubIntake* subIntake, double position) : m_subIntake(subIntake){
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subIntake);
  m_position = position;
}

// Called when the command is initially scheduled.
void CmdMoveIntake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdMoveIntake::Execute() {
  // Move the intake to the home position
  m_subIntake->MoveIntakeToPosition(m_position);


}

// Called once the command ends or is interrupted.
void CmdMoveIntake::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdMoveIntake::IsFinished() {
  return true;
}
