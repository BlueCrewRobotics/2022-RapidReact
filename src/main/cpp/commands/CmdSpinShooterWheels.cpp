// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdSpinShooterWheels.h"

CmdSpinShooterWheels::CmdSpinShooterWheels(SubShooter* subShooter) : m_subShooter(subShooter) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subShooter);
}

// Called when the command is initially scheduled.
void CmdSpinShooterWheels::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdSpinShooterWheels::Execute() {
  // Velocity of shooter wheels in counts/100ms
  double topShooterSpeed = 5000;
  double btmShooterSpeed = 5000;
  // Offset for slowing wheels when shooting
  double topShooterOffset = 5000;
  double btmShooterOffset = 5000;

  // Get the distance to the target in ft

  // Apply correlation equation of target distance to wheel speed
  
  // Just shoot the ball to bottom hub target
  topShooterSpeed = topShooterSpeed + topShooterOffset;
  btmShooterSpeed = btmShooterSpeed + btmShooterOffset;

  m_subShooter->SpinUpWheels(topShooterSpeed,btmShooterSpeed);

}

// Called once the command ends or is interrupted.
void CmdSpinShooterWheels::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdSpinShooterWheels::IsFinished() {
  return true;
}
