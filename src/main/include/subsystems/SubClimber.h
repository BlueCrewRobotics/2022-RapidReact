/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "BC_FalconFX.h"
#include <frc/smartdashboard/SmartDashboard.h>

class SubClimber : public frc2::SubsystemBase {
 public:
  SubClimber();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  // Configure the falcon motors for the climber
  void ConfigureClimber();
 


 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  TalonFX* mainClimber = new TalonFX(CLIMBER_MAIN_ADDR);
  
  
};
