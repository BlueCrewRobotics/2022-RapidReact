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
#include <frc/Solenoid.h>

class SubClimber : public frc2::SubsystemBase {
 public:
  SubClimber();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  // Configure the falcon motors for the climber
  void ConfigureClimber();
  // Moves climber to position
  void MoveClimber(double output);
  // engage/release hooks
  void SetHookPosition(bool enageHooks);
  // Angle the climber
  void SetClimberAngled();
  // Make the climber straight
  void SetClimberStraight();
 


 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  TalonFX* mainClimber = new TalonFX(CLIMBER_MAIN_ADDR);
  
  frc::Solenoid* m_climberStraight = new  frc::Solenoid(PCM_0,frc::PneumaticsModuleType::CTREPCM,PCM_3_CLIMBER_STRAIGHT);
  frc::Solenoid* m_climberAngled = new frc::Solenoid(PCM_0,frc::PneumaticsModuleType::CTREPCM,PCM_4_CLIMBER_ANGLED);
  frc::Solenoid* m_climberHook = new  frc::Solenoid(PCM_0,frc::PneumaticsModuleType::CTREPCM,PCM_5_CLIMBER_HOOK);

};
