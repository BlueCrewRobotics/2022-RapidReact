// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdAutonomous.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
AutoCmdAutonomous::AutoCmdAutonomous(SubLimelightShooter* subLimelightShooter,  SubShooter* subShooter, SubIntake* subIntake, SubDriveTrain* subDriveTrain) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    // Turn on the shooter limelight
    CmdTurnOnShooterLimelight(subLimelightShooter),
    // Set the shooter angle this will be upclose shooting to the upper hub
    CmdSetShooterAngle(subShooter,subLimelightShooter),
    // Spin up Shooter wheels
    CmdSpinShooterWheels(subShooter, subLimelightShooter),
    // Shoot the ball
    CmdIndexToShooter(subIntake),
    // Turn off shooter limelight
    CmdTurnOffShooterLimelight(subLimelightShooter),
    // Stop the shoooter wheels
    CmdStopShooterWheels(subShooter),
    // Backup up the robot
    AutoCmdDrive(subDriveTrain,1,1),
    // Turn to face another alliance ball

    // Extend intake
    // CmdMoveIntake(&m_subIntake, 200.0);
    // Spin the intake
    // CmdSpinIntake(&m_subIntake);
    // Turn on intake limelight. Proably don't need to turn on the limelight for the ball color

    // Drive toward ball until ball is picked up

    // Retract intake
    //CmdMoveIntake(&m_subIntake, 0.0);
    // Stop the intake
    // CmdStopIntake(&m_subIntake);
    // Turn the shooter to face the hub

    // Turn on shooter limelight

    // Acquire the target

    // Shoot the ball

    // Stop the shoooter wheels
    CmdStopShooterWheels(subShooter)
    
  );
}
