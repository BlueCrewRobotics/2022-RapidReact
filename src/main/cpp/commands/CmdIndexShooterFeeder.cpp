/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdIndexShooterFeeder.h"
#include <iostream>

CmdIndexShooterFeeder::CmdIndexShooterFeeder(SubIntake* subIntake) : m_subIntake(subIntake){
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subIntake);
}

// Called when the command is initially scheduled.
void CmdIndexShooterFeeder::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdIndexShooterFeeder::Execute() {
  double position = m_subIntake->GetIndexerPosition();

  if(m_subIntake->GetBallSensor()==false && m_subIntake->GetBallCount() == 0 && m_subIntake->IsIndexerAtPosition(600) == true ) {
      position = position + 13000;
      m_subIntake->IndexShooterFeeder(position);
      m_subIntake->SetBallCount(m_subIntake->GetBallCount()+1);
      //std::cout << "BC 1 Intake=  " << m_subIntake->GetBallCount() << std::endl;
  }

  if(m_subIntake->GetBallSensor()==false && m_subIntake->GetBallCount() == 1 && m_subIntake->IsIndexerAtPosition(600) == true ) {
      position = position + 1000;
      m_subIntake->IndexShooterFeeder(position);
      m_subIntake->SetBallCount(m_subIntake->GetBallCount()+1);  
      //std::cout << "BC 2 Intake=  " << m_subIntake->GetBallCount() << std::endl;
    }
}

// Called once the command ends or is interrupted.
void CmdIndexShooterFeeder::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdIndexShooterFeeder::IsFinished() {
  
  if(m_subIntake->GetBallSensor()==true) {
    return true;
  }
  if(m_subIntake->GetBallSensor()==false) {
    return false;
  }
}
