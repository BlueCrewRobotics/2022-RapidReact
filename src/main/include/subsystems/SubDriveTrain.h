// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "BC_FalconFX.h"
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "Constants.h"

class SubDriveTrain : public frc2::SubsystemBase {
 public:
  SubDriveTrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

  void Drive(double speed, double rotation);
  void DriveTrainConfigure();
  void ClearStickFaults();
  void SetFollower(TalonFX* motor);


 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  BC_FalconFX* leftDriveMotor = new BC_FalconFX(MOTOR_LEFT_MASTER);
  BC_FalconFX* rightDriveMotor = new BC_FalconFX(MOTOR_RIGHT_MASTER);

  BC_FalconFX* leftFollowMotor = new BC_FalconFX(MOTOR_LEFT_FOLLOWER);
  BC_FalconFX* rightFollowMotor = new BC_FalconFX(MOTOR_RIGHT_FOLLOWER);

  frc::DifferentialDrive* driveTrain = new frc::DifferentialDrive(*leftDriveMotor, *rightDriveMotor);

};
