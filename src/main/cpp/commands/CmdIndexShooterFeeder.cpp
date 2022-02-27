/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdIndexShooterFeeder.h"

CmdIndexShooterFeeder::CmdIndexShooterFeeder(SubIntake* subIntake) : m_subIntake(subIntake){
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subIntake);
}

// Called when the command is initially scheduled.
void CmdIndexShooterFeeder::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdIndexShooterFeeder::Execute() {
  if(m_subIntake->GetBallSensor()==false){
    double position = m_subIntake->GetIndexerPosition();
      if(m_subIntake->GetBallCount() == 0) {
        position = position + 13000;
        m_subIntake->IndexShooterFeeder(position);
        m_subIntake->SetBallCount(1);  
      }
  }

}

// Called once the command ends or is interrupted.
void CmdIndexShooterFeeder::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdIndexShooterFeeder::IsFinished() {
  
  return true;
}