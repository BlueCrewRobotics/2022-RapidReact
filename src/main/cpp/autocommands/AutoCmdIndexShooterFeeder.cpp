/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdIndexShooterFeeder.h"
#include <iostream>

AutoCmdIndexShooterFeeder::AutoCmdIndexShooterFeeder(SubIntake* subIntake) : m_subIntake(subIntake){
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subIntake);
}

// Called when the command is initially scheduled.
void AutoCmdIndexShooterFeeder::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoCmdIndexShooterFeeder::Execute() {
  double position = m_subIntake->GetIndexerPosition();

  std::cout << "Ball Sensor=" << m_subIntake->GetBallSensor() << " Ball Count=" << m_subIntake->GetBallCount() << " Error=" << m_subIntake->IsIndexerAtPosition(600)<< std::endl;

  if(m_subIntake->GetBallSensor()==false && m_subIntake->GetBallCount() == 1 && m_subIntake->IsIndexerAtPosition(500) == true) {
      position = position + 1000;
      m_subIntake->IndexShooterFeeder(position);
      m_subIntake->SetBallCount(2);
      std::cout << "BC 1 Intake=  " << m_subIntake->GetBallCount() << std::endl;
  }
  else {
        if(m_subIntake->GetBallSensor()==false && m_subIntake->GetBallCount() == 0 && m_subIntake->IsIndexerAtPosition(500) == true ) {
            position = position + 14000;
            m_subIntake->IndexShooterFeeder(position);
            m_subIntake->SetBallCount(1);  
            std::cout << "BC 2 Intake=  " << m_subIntake->GetBallCount() << std::endl;
        }
  }

}

// Called once the command ends or is interrupted.
void AutoCmdIndexShooterFeeder::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdIndexShooterFeeder::IsFinished() {
  
  if(m_subIntake->GetBallSensor()==true){
    return false;
  }
  else{
    return true;
  }
  

}
