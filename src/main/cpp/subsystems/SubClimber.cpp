/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubClimber.h"

SubClimber::SubClimber() = default;

// This method will be called once per scheduler run
void SubClimber::Periodic() {
    //frc::SmartDashboard::PutNumber("Shooter/topSpeed",mainClimber->GetSelectedSensorVelocity());
    //frc::SmartDashboard::PutNumber("Shooter/btmSpeed",btmShooterMotor->GetSelectedSensorVelocity());
    // This function will run periodically to set the servo angle
    // Use SetShooterAngle to set the angle that is used periodically


}

void SubClimber::ConfigureClimber() {

    // Configure the top shooter Falcon motor
    mainClimber->SetInverted(ctre::phoenix::motorcontrol::TalonFXInvertType::CounterClockwise);
    mainClimber->ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
    mainClimber->ConfigClosedloopRamp(0.0,0);

    mainClimber->Config_kF(0,0.0, 0);
    mainClimber->Config_kP(0,0.01, 0);
    mainClimber->Config_kI(0,0.00, 0);
    mainClimber->Config_kD(0,0.00, 0);

    mainClimber->SelectProfileSlot(0, 0);
    mainClimber->ConfigNominalOutputForward(0, 0);
    mainClimber->ConfigNominalOutputReverse(0, 0);
    mainClimber->ConfigPeakOutputForward(1, 0);
    mainClimber->ConfigPeakOutputReverse(-1, 0);

    mainClimber->ConfigStatorCurrentLimit(StatorCurrentLimitConfiguration(true,10,15,100));
    mainClimber->ConfigSupplyCurrentLimit(SupplyCurrentLimitConfiguration(true,10,15,100));

    mainClimber->SetNeutralMode(NeutralMode::Coast);




}





