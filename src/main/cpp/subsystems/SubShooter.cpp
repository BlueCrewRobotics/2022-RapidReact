/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubShooter.h"

SubShooter::SubShooter() = default;

// This method will be called once per scheduler run
void SubShooter::Periodic() {
    //frc::SmartDashboard::PutNumber("Shooter/topSpeed",topShooterMotor->GetSelectedSensorVelocity());
    //frc::SmartDashboard::PutNumber("Shooter/btmSpeed",btmShooterMotor->GetSelectedSensorVelocity());
    // This function will run periodically to set the servo angle
    // Use SetShooterAngle to set the angle that is used periodically
    SetPeriodicServoAngle();

}

void SubShooter::ConfigureShooter() {

    // Configure the top shooter Falcon motor
    topShooterMotor->SetInverted(ctre::phoenix::motorcontrol::TalonFXInvertType::CounterClockwise);
    topShooterMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
    topShooterMotor->ConfigClosedloopRamp(0.0,0);

    topShooterMotor->Config_kF(0,0.0465, 0);
    topShooterMotor->Config_kP(0,0.1, 0);
    topShooterMotor->Config_kI(0,0.00, 0);
    topShooterMotor->Config_kD(0,0.00, 0);

    topShooterMotor->SelectProfileSlot(0, 0);
    topShooterMotor->ConfigNominalOutputForward(0, 0);
    topShooterMotor->ConfigNominalOutputReverse(0, 0);
    topShooterMotor->ConfigPeakOutputForward(1, 0);
    topShooterMotor->ConfigPeakOutputReverse(-1, 0);

    topShooterMotor->ConfigStatorCurrentLimit(StatorCurrentLimitConfiguration(true,10,15,100));
    topShooterMotor->ConfigSupplyCurrentLimit(SupplyCurrentLimitConfiguration(true,10,15,100));

    topShooterMotor->SetNeutralMode(NeutralMode::Coast);

    // Configure the bottom shooter Falcon motor
    btmShooterMotor->SetInverted(ctre::phoenix::motorcontrol::TalonFXInvertType::Clockwise);
    btmShooterMotor->ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor);
    btmShooterMotor->ConfigClosedloopRamp(0.0,0);

    btmShooterMotor->Config_kF(0,0.0465, 0);
    btmShooterMotor->Config_kP(0,0.1, 0);
    btmShooterMotor->Config_kI(0,0.00, 0);
    btmShooterMotor->Config_kD(0,0.00, 0); 

    btmShooterMotor->SelectProfileSlot(0, 0);
    btmShooterMotor->ConfigNominalOutputForward(0, 0);
    btmShooterMotor->ConfigNominalOutputReverse(0, 0);
    btmShooterMotor->ConfigPeakOutputForward(1, 0);
    btmShooterMotor->ConfigPeakOutputReverse(-1, 0);

    btmShooterMotor->ConfigStatorCurrentLimit(StatorCurrentLimitConfiguration(true,10,15,100));
    btmShooterMotor->ConfigSupplyCurrentLimit(SupplyCurrentLimitConfiguration(true,10,15,100));

    btmShooterMotor->SetNeutralMode(NeutralMode::Coast);

    // Configure the pulse width modulation (PWM) for the linear actuators
    rightServo->SetBounds(2.0,0.01,1.5,0.01,1.0);
    leftServo->SetBounds(2.0,0.01,1.5,0.01,1.0);


}

void SubShooter::SpinUpWheels(double topSpeed, double btmSpeed) {
    topShooterMotor->Set(ControlMode::Velocity, topSpeed);
    btmShooterMotor->Set(ControlMode::Velocity, btmSpeed);

}

void SubShooter::SetShooterAngle(double angle) {
    m_servoAngle = angle;
}

bool SubShooter::WheelsAtSpeed(double deadband) {
    int top = topShooterMotor->GetClosedLoopTarget() - topShooterMotor->GetSelectedSensorVelocity();
    int bot = btmShooterMotor->GetClosedLoopTarget() - btmShooterMotor->GetSelectedSensorVelocity();

    if((abs(top) < deadband ) && (abs(bot) < deadband)){
        return true;
    }
    return false;

}

void SubShooter::SetPeriodicServoAngle() {
    rightServo->SetPosition(m_servoAngle);
    leftServo->SetPosition(m_servoAngle);
}