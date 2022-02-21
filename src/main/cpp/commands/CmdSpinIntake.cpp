/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdSpinIntake.h"

CmdSpinIntake::CmdSpinIntake(SubIntake* subIntake) : m_subIntake(subIntake) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subIntake);
}

// Called when the command is initially scheduled.
void CmdSpinIntake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdSpinIntake::Execute() {
  // Move the intake to the home position
  m_subIntake->SpinFrontWheels(0.5);

}

// Called once the command ends or is interrupted.
void CmdSpinIntake::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdSpinIntake::IsFinished() {
  return true;
}
