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
#include "BC_TalonSRX.h"
#include "Constants.h"
#include <frc/DigitalInput.h>
#include "common/BC_Blinkin.h"

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
  // Reverse Shooter Feeder
  void ReverseShooterFeeder(double position);
  // Get the position of the indexer
  double GetIndexerPosition();
  // Get break sensor
  bool GetBallSensor();
  // Get the ball count
  int GetBallCount();
  //Gets the staus of the beam; true=broken
  bool GetBeamStatus();
  // Set the ball count
  void SetBallCount(int ballCount);
  //Sets the status of the beam; true=broken
  void SetBeamStatus(bool broken);
  // Is indexer at position
  bool IsIndexerAtPosition(double deadband);
  //Set blinkin light colors
  void SetBlinkinColor(double color);
  

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  //VictorSPX* frontSpinner = new VictorSPX(INTAKE_SPINNER_ADDR);
  // If using Falcon uncomment below line and comment out above line
  TalonFX* frontSpinner = new TalonFX(INTAKE_SPINNER_ADDR);

  TalonSRX* positionIntake = new TalonSRX(INTAKE_POSITIONER_ADDR);
  TalonSRX* shooterFeeder = new TalonSRX(INTAKE_SHOOTER_FEEDER_ADDR);

  double m_indexPosition;
  int m_ballCount = 1;
  bool m_beamHasBroken = false;
  
  // Sets up break sensors
  frc::DigitalInput* m_ballDetector = new frc::DigitalInput(0);
  BC_Blinkin* m_ledBlinkin = new BC_Blinkin(2);


};
