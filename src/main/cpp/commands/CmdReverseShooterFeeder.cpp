/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdReverseShooterFeeder.h"
#include <iostream>

CmdReverseShooterFeeder::CmdReverseShooterFeeder(SubIntake* subIntake) : m_subIntake(subIntake){
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subIntake);
}

// Called when the command is initially scheduled.
void CmdReverseShooterFeeder::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdReverseShooterFeeder::Execute() {
  double position = m_subIntake->GetIndexerPosition();
 
 
  if(m_subIntake->GetBallCount() == 1){

    position = position - 15000;
    m_subIntake->IndexShooterFeeder(position);
    m_subIntake->SetBallCount(0);
   
    std::cout << "Ball Sensor=" << m_subIntake->GetBallSensor() << " Ball Count=" << m_subIntake->GetBallCount() << " Error=" << m_subIntake->IsIndexerAtPosition(600)<< std::endl;

    

  }
  else if(m_subIntake->GetBallCount() == 2){
    m_subIntake->SetBallCount(1);
    std::cout << "Ball Sensor=" << m_subIntake->GetBallSensor() << " Ball Count=" << m_subIntake->GetBallCount() << " Error=" << m_subIntake->IsIndexerAtPosition(600)<< std::endl;

  }

}

// Called once the command ends or is interrupted.
void CmdReverseShooterFeeder::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdReverseShooterFeeder::IsFinished() {
  return true;

}
