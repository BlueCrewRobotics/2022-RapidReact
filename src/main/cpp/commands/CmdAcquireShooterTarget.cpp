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
  AddRequirements({subDriveTrain});
}

// Called when the command is initially scheduled.
void CmdAcquireShooterTarget::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdAcquireShooterTarget::Execute() {
  double hTargetPosition;
  double hTargetAngle;

  double gain = 0.7;
  double offset = 0; // Offset in degrees

  if(m_subLimelightShooter->GetTarget()==true)
  {
    // Get the robots horizontal offset from the target center
    hTargetAngle = m_subLimelightShooter->GetHorizontalOffset();
    

    // Normalize the horizontal position to the target
    hTargetPosition = (-1*((hTargetAngle + offset)/29.8))*gain;

    // Rotate the drive train to point at the target
    // Might need to add a deadband to overcome the drain train friction when rotating use next line
    // TargetPosition = hTargetPosition + 0.1;
    m_subDriveTrain->RotateDriveTrain(-hTargetPosition);
    
  }
  else {
    if(m_subLimelightShooter->GetTarget() == false){
        m_subDriveTrain->RotateDriveTrain(0);
    }
  }
  
}

// Called once the command ends or is interrupted.
void CmdAcquireShooterTarget::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdAcquireShooterTarget::IsFinished() {
  if( m_subLimelightShooter->GetHorizontalOffset() < 0.1 && m_subLimelightShooter->GetHorizontalOffset() > -0.1)
  {
    return true;
  }
  else{
    return false;
  }
}
