/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdStopIntake.h"

CmdStopIntake::CmdStopIntake(SubIntake* subIntake) : m_subIntake(subIntake) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subIntake);
}

// Called when the command is initially scheduled.
void CmdStopIntake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdStopIntake::Execute() {
  // Move the intake to the home position
  m_subIntake->SpinFrontWheels(0);

}

// Called once the command ends or is interrupted.
void CmdStopIntake::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdStopIntake::IsFinished() {
  return true;
}
