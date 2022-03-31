/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdDrive.h"
#include <iostream>

AutoCmdDrive::AutoCmdDrive(SubDriveTrain* subDriveTrain, double leftrotations, double rightrotations) 
  : m_subDriveTrain(subDriveTrain), m_leftRotations(leftrotations), m_rightRotations(rightrotations) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subDriveTrain});
}

// Called when the command is initially scheduled.
void AutoCmdDrive::Initialize() {
  m_leftFinished = m_leftRotations*2048 + m_subDriveTrain->GetLeftEncoderValue();
  m_rightFinished = m_rightRotations*2048 + m_subDriveTrain->GetRightEncoderValue();


}

// Called repeatedly when this Command is scheduled to run
void AutoCmdDrive::Execute() {
  m_subDriveTrain->AutonomousDriving(m_leftRotations,m_rightRotations);
  std::cout << "L= " << m_leftFinished << " Act= " << m_subDriveTrain->GetLeftEncoderValue() << std::endl;
  std::cout << "R= " << m_rightFinished << " Act= " << m_subDriveTrain->GetRightEncoderValue() << std::endl;

}

// Called once the command ends or is interrupted.
void AutoCmdDrive::End(bool interrupted) {}

// Returns true when the command should end.
bool AutoCmdDrive::IsFinished() {
if(abs((m_rightFinished - m_subDriveTrain->GetRightEncoderValue())) > (250) || (m_leftFinished - m_subDriveTrain->GetLeftEncoderValue()) > (250)){

  return true;

}
 else{
  
 return false;
}

}