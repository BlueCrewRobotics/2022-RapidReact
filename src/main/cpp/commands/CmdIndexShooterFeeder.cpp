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
  //beamHasBroken is not m_subIntake->GetBallSensor; it doesn't track the break sensor's current state,
  //but instead whether or not the ball has entered the robot. When the ball has been properly loaded,
  //beamHasBroken returns to false, ready for ball 2. The main purpose of beamHasBroken is to help
  //further prevent double counting
  
  /*m_subIntake->GetBeamStatus() == false && */

  std::cout << "Ball Sensor=" << m_subIntake->GetBallSensor() << " Ball Count=" << m_subIntake->GetBallCount() << " Error=" << m_subIntake->IsIndexerAtPosition(600)<< std::endl;

  if(m_subIntake->GetBallSensor()==false && m_subIntake->GetBallCount() == 1 && m_subIntake->IsIndexerAtPosition(500) == true) {
      position = position + 1000;
      m_subIntake->IndexShooterFeeder(position);
      //m_subIntake->SetBeamStatus(true);
      m_subIntake->SetBallCount(m_subIntake->GetBallCount()+1);
      //std::cout << "BC 1 Intake=  " << m_subIntake->GetBallCount() << std::endl;
  }
  else {
        if(m_subIntake->GetBallSensor()==false && m_subIntake->GetBallCount() == 0 && m_subIntake->IsIndexerAtPosition(500) == true ) {
            position = position + 14000;
            m_subIntake->IndexShooterFeeder(position);
            //m_subIntake->SetBeamStatus(true);
            m_subIntake->SetBallCount(m_subIntake->GetBallCount()+1);  
            //std::cout << "BC 2 Intake=  " << m_subIntake->GetBallCount() << std::endl;
        }
  }

  /*m_subIntake->GetBeamStatus() == false && */

/*  if(m_subIntake->GetBeamStatus()==true && m_subIntake->GetBallSensor()==true){
      m_subIntake->SetBallCount(m_subIntake->GetBallCount()+1);
      m_subIntake->SetBeamStatus(false);
  }*/
}

// Called once the command ends or is interrupted.
void CmdIndexShooterFeeder::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdIndexShooterFeeder::IsFinished() {
  
  
  return true; //m_subIntake->GetBallSensor();

}
