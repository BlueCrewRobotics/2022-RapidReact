// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubIntake.h"

SubIntake::SubIntake() = default;

// This method will be called once per scheduler run
void SubIntake::Periodic() {}

void SubIntake::ConfigureIntake(){
    // Write code here to configure the the motors of the Intake

}

void SubIntake::SpinFrontWheels(double speed) {
    // Write code here to spin the front wheels

}

void SubIntake::SpinShooterFeeder(double speed) {
    // Write code here to spin the shooter ball feeder

}

void SubIntake::MoveToPosition(double position) {
    // Write code here to move the intake to position to intake balls etc.
    
}
