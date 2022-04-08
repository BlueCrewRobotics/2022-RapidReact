/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdSetShooterAngle.h"
#include <iostream>

CmdSetShooterAngle::CmdSetShooterAngle(SubShooter* subShooter, SubLimelightShooter* subLimelightShooter) : m_subShooter(subShooter), m_subLimelightShooter(subLimelightShooter) {
  // Use addRequirements() here to declare subsystem dependencies.
  //AddRequirements(subShooter);
}

// Called when the command is initially scheduled.
void CmdSetShooterAngle::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdSetShooterAngle::Execute() {
  //Set the angle of the shooter

  double hDistanceToTarget;
  double angle;
  double angleNormalized;  // Normalized for servo control

 
    hDistanceToTarget = m_subLimelightShooter->GetDistanceToTarget();
    hDistanceToTarget = hDistanceToTarget + 2;
    
  // Change the shooter servos to point at the target
  angle = -0.10 * hDistanceToTarget + 1.21;
  //angleNormalized = angle / 89.73;
  m_subShooter->SetShooterAngle(angle);
  std::cout << "Servo Angle= " << angle << std::endl;
  std::cout << "SA-Distance= " << hDistanceToTarget << std::endl;

}

// Called once the command ends or is interrupted.
void CmdSetShooterAngle::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdSetShooterAngle::IsFinished() {
  return true;
}
