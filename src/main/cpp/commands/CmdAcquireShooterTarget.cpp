/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdAcquireShooterTarget.h"

CmdAcquireShooterTarget::CmdAcquireShooterTarget(SubLimelightShooter* subLimelightShooter, SubDriveTrain* subDriveTrain) 
  : m_subLimelightShooter(subLimelightShooter), m_subDriveTrain(subDriveTrain) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({subLimelightShooter,subDriveTrain});
}

// Called when the command is initially scheduled.
void CmdAcquireShooterTarget::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdAcquireShooterTarget::Execute() {
  double hTargetPosition;
  double vTargetPosition;

  double gain = 0.65;
  double offset = 0;

  if(m_subLimelightShooter->GetTarget()==true)
  {
    // Get the robots horizontal offset from the target center
    double hTargetAngle = m_subLimelightShooter->GetHorizontalOffset();
    double vTargetAngle = m_subLimelightShooter->GetVerticalOffset();
    double hDistanceToTarget = m_subLimelightShooter->GetDistanceToTarget();

    // Normalize the horizontal position to the target
    hTargetPosition = (-1*(hTargetAngle/29.8))*gain;
    // Normalize the vertical position to the target
    vTargetPosition = (-1*(hTargetAngle/24.85))*gain;

    // Rotate the drive train to point at the target
    // Might need to add a deadband to overcome the drain train friction when rotatingh use next line
    // TargetPosition = hTargetPosition + 0.1;
    m_subDriveTrain->RotateDriveTrain(hTargetPosition);
    // Change the shooter servos to point at the target



  }
  
}

// Called once the command ends or is interrupted.
void CmdAcquireShooterTarget::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdAcquireShooterTarget::IsFinished() {
  if( m_subLimelightShooter->GetHorizontalOffset() < 0.1 && m_subLimelightShooter->GetVerticalOffset() < 0.1)
  {
    return true;
  }
  else{
    return false;
  }
}
