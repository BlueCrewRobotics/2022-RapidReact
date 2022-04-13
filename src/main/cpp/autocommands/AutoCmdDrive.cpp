/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdDrive.h"
#include <iostream>

AutoCmdDrive::AutoCmdDrive(SubDriveTrain* subDriveTrain, double leftrotations, double rightrotations, frc::Timer* timer) 
  : m_subDriveTrain(subDriveTrain), m_leftRotations(leftrotations), m_rightRotations(rightrotations), m_timer(timer) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subDriveTrain});
}

// Called when the command is initially scheduled.
void AutoCmdDrive::Initialize() {
  m_timer->Reset();
  m_leftFinished = m_leftRotations*2048 + m_subDriveTrain->GetLeftEncoderValue();
  m_rightFinished = m_rightRotations*2048 + m_subDriveTrain->GetRightEncoderValue();


}

// Called repeatedly when this Command is scheduled to run
void AutoCmdDrive::Execute() {
  m_timer->Start();
  m_subDriveTrain->AutonomousDriving(m_leftRotations,m_rightRotations);
 // std::cout << "L= " << m_leftFinished << " Err= " << m_subDriveTrain->GetLeftErrorValue() << std::endl;
 // std::cout << "R= " << m_rightFinished << " Err= " << m_subDriveTrain->GetRightErrorValue() << std::endl;

}

// Called once the command ends or is interrupted.
void AutoCmdDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdDrive::IsFinished() {
  if(m_timer->HasElapsed((units::time::second_t)4)==true) {
    return true;
  }
  else {
    return false;
  }
}