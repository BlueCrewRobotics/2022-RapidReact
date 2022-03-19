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
#include <frc/Servo.h>
#include <frc/Solenoid.h>
#include <frc/smartdashboard/SmartDashboard.h>

class SubShooter : public frc2::SubsystemBase {
 public:
  SubShooter();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
  // Configure the falcon motors for the shooter
  void ConfigureShooter();
  // Spins up the wheels on the shooter in velocity closed loop.
  // Parameters to pass the function, are in velocity counts/100ms
  void SpinUpWheels(double topSpeed, double btmSpeed);
  // Set the shooter angle between 0-1.0
  void SetShooterAngle(double angle);
  // Checks to see if the wheels on the shooter are up to speed.
  // Returns true if wheels are up to speed or false if not at speed.
  // Parameter deadband is used to see if the speed is within the deadband
  bool WheelsAtSpeed(double deadband);
  // Update the servo angle to be used
  void SetPeriodicServoAngle();
  // Run the wheel speed periodically
  void SetPeriodicWheelSpeed();
  // Set the the wheel speed parameter'
  void SetShooterWheelSpeed(double topSpeed, double botSpeed);
  // Select the lower hub or upper hub to shoot at
  void SetMotorCooling(bool cool);

  void SelectHub(bool select);
  // Get the selected hub that we are shooting at
  bool GetHub();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  TalonFX* topShooterMotor = new TalonFX(SHOOTER_TOP_ADDR);
  TalonFX* btmShooterMotor = new TalonFX(SHOOTER_BTM_ADDR);

  frc::Servo* rightServo = new frc::Servo(SHOOTER_RIGHT_PWM_ADDR);
  frc::Servo* leftServo = new frc::Servo(SHOOTER_LEFT_PWN_ADDR);

  frc::Solenoid* m_motorCooling = new frc::Solenoid(PCM_0,frc::PneumaticsModuleType::CTREPCM,PCM_0_MOTOR_COOLING);

  double m_servoAngle = 0.8;
  bool m_hubSelection = 1; // Low is 0 High is 1
  double m_topShooterWheelSpeed = 0;
  double m_btmShooterWheelSpeed = 0;
};
