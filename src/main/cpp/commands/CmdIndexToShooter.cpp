/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdIndexToShooter.h"
#include <iostream>

CmdIndexToShooter::CmdIndexToShooter(SubIntake* subIntake,SubShooter* subShooter) : m_subIntake(subIntake),m_subShooter(subShooter){
  // Use addRequirements() here to declare subsystem dependencies.
  //AddRequirements(subIntake);
}

// Called when the command is initially scheduled.
void CmdIndexToShooter::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdIndexToShooter::Execute() {
  double position = m_subIntake->GetIndexerPosition();
  if(m_subShooter->WheelsAtSpeed(1000)==true){
    position = position + 13000;
    m_subIntake->IndexShooterFeeder(position);
    m_subIntake->SetBallCount(m_subIntake->GetBallCount()-1);  
  }
  std::cout << "BC After Shot=  " << m_subIntake->GetBallCount() << std::endl;

  
}

// Called once the command ends or is interrupted.
void CmdIndexToShooter::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdIndexToShooter::IsFinished() {
  return true;
}
