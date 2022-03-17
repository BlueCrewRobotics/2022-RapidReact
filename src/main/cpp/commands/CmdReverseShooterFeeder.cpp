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
  //AddRequirements(subIntake);
}

// Called when the command is initially scheduled.
void CmdReverseShooterFeeder::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdReverseShooterFeeder::Execute() {
  double position = m_subIntake->GetIndexerPosition();
  //beamHasBroken is not m_subIntake->GetBallSensor; it doesn't track the break sensor's current state,
  //but instead whether or not the ball has entered the robot. When the ball has been properly loaded,
  //beamHasBroken returns to false, ready for ball 2. The main purpose of beamHasBroken is to help
  //further prevent double counting
  if(m_subIntake->GetBallCount() == 1){

  
        position = position - 14000;
        m_subIntake->IndexShooterFeeder(position);
        m_subIntake->SetBallCount(m_subIntake->GetBallCount()-1);


  }
  else if(m_subIntake->GetBallCount() == 2){
    m_subIntake->SetBallCount(m_subIntake->GetBallCount()-1);
  }
/*  if(m_subIntake->GetBeamStatus()==true && m_subIntake->GetBallSensor()==true){
      m_subIntake->SetBallCount(m_subIntake->GetBallCount()+1);
      m_subIntake->SetBeamStatus(false);
  }*/
}

// Called once the command ends or is interrupted.
void CmdReverseShooterFeeder::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdReverseShooterFeeder::IsFinished() {
  return true; //m_subIntake->GetBallSensor();

}
