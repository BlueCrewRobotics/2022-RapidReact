/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdSpinShooterWheels.h"
#include <iostream>

CmdSpinShooterWheels::CmdSpinShooterWheels(SubShooter* subShooter, SubLimelightShooter* subLimelightShooter) : m_subShooter(subShooter), m_subLimelightShooter(subLimelightShooter) {
  // Use addRequirements() here to declare subsystem dependencies.
  //AddRequirements({subShooter});
}

// Called when the command is initially scheduled.
void CmdSpinShooterWheels::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CmdSpinShooterWheels::Execute() {
    // Velocity of shooter wheels in counts/100ms
    double topShooterSpeed;  //20731
    double btmShooterSpeed; 
    // Offset for slowing wheels when shooting
    double topShooterOffset = 4000;
    double btmShooterOffset = 4000;

  if(m_subShooter->GetHub() == true) {

    // Velocity of shooter wheels in counts/100ms
    topShooterSpeed = 13152.52;  //20731
    btmShooterSpeed = 13152.52; 
    // Offset for slowing wheels when shooting
    topShooterOffset = 4000;
    btmShooterOffset = 4000;

    if(m_subLimelightShooter->GetTarget()==true){
      std::cout << "High Hub Selected " << std::endl;
      // Get the distance to the target in ft
      double hDistanceToTarget = m_subLimelightShooter->GetDistanceToTarget()+2;
      std::cout << "Distance= " << hDistanceToTarget << std::endl;
      // Apply correlation equation of target distance to wheel speed
      topShooterSpeed = 15.73*hDistanceToTarget*hDistanceToTarget-115.29*hDistanceToTarget+13152.52;
      btmShooterSpeed = 15.73*hDistanceToTarget*hDistanceToTarget-115.29*hDistanceToTarget+13152.52;
      // Just shoot the ball to bottom hub target
      topShooterSpeed = topShooterSpeed + topShooterOffset;
      btmShooterSpeed = btmShooterSpeed + btmShooterOffset;
      // Enable
      //std::cout << "Shooter Speed top: " << topShooterSpeed << " btm: " << btmShooterSpeed << std::endl;
      std::cout << "Camera Angle= " << m_subLimelightShooter->GetCameraMountAngle(10) << std::endl;
      
    }
    else {
      // Just shoot the ball to bottom hub target
      //topShooterSpeed = topShooterSpeed + topShooterOffset;
      //btmShooterSpeed = btmShooterSpeed + btmShooterOffset;

    }

  } 
  else {
    if(m_subShooter->GetHub() == false){
      topShooterSpeed = 8000;
      btmShooterSpeed = 8000;
      std::cout << "Low Hub Selected " << std::endl;
    }

}

  // m_subShooter->SpinUpWheels(topShooterSpeed,btmShooterSpeed);
  m_subShooter->SetShooterWheelSpeed(topShooterSpeed,btmShooterSpeed);

}

// Called once the command ends or is interrupted.
void CmdSpinShooterWheels::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdSpinShooterWheels::IsFinished() {
/*  if(m_subShooter->WheelsAtSpeed(1000) == true ){
    return true;
  }
  else{
  
    return false;
  }*/
  return true;
}
