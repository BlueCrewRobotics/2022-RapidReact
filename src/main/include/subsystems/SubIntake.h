/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "BC_VictorSPX.h"
#include "Constants.h"

class SubIntake : public frc2::SubsystemBase {
 public:
  SubIntake();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  
  // Configure all the motors of the intake
  void ConfigureIntake();
  // Spin the front wheels
  void SpinFrontWheels(double speed);
  // Spin the shooter feeder motor
  void SpinShooterFeeder(double speed);
  // Move intake to position
  void MoveIntakeToPosition(double position);
  // Index the shooter feeder
  void IndexShooterFeeder(double position);
  // Get the position of the indexer
  double GetIndexerPosition();



 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  VictorSPX* frontSpinner = new VictorSPX(INTAKE_SPINNER_ADDR);
  TalonSRX* positionIntake = new TalonSRX(INTAKE_POSITIONER_ADDR);
  TalonSRX* shooterFeeder = new TalonSRX(INTAKE_SHOOTER_FEEDER_ADDR);

  double m_indexPosition;


};
