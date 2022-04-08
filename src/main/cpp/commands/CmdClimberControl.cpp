/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdClimberControl.h"
#include <iostream>

CmdClimberControl::CmdClimberControl(SubClimber *SubClimber, frc::Joystick* auxController) : m_subClimber(SubClimber), m_auxController(auxController){
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(SubClimber);

}

// Called when the command is initially scheduled.
void CmdClimberControl::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdClimberControl::Execute()
{
  double speedUp = m_auxController->GetRawAxis(AXIS_R_TRIG);
  double speedDown = -m_auxController->GetRawAxis(AXIS_L_TRIG);

  double speed;

  if (speedDown > -0.1 || speedUp < 0.1) {
    speed = 0;
  }
  if (speedDown < -0.1 || speedUp > 0.1) {
    speed = speedUp + speedDown;
  }
 
  // Move Climber to set position
  //std::cout << "Climber Speed " << speed << std::endl;

  m_subClimber->MoveClimber(speed);
}

// Called once the command ends or is interrupted.
void CmdClimberControl::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdClimberControl::IsFinished()
{
  return false;
}
