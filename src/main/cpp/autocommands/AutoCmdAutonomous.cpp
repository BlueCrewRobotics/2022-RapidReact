// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "autocommands/AutoCmdAutonomous.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
AutoCmdAutonomous::AutoCmdAutonomous(SubLimelightShooter* subLimelightShooter,  SubShooter* subShooter, SubIntake* subIntake, SubDriveTrain* subDriveTrain, frc::Timer* timer) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(
    // Turn on the shooter limelight
    CmdTurnOnShooterLimelight(subLimelightShooter),
    // Set the shooter angle this will be upclose shooting to the upper hub
    CmdSetShooterAngle(subShooter,subLimelightShooter),
    // Spin up Shooter wheels
    AutoCmdSpinShooterWheels(subShooter, subLimelightShooter),
    // Start timer
    AutoCmdTimer(timer,1),
        // Shoot the ball
    CmdIndexToShooter(subIntake,subShooter),
    // Start timer
    AutoCmdTimer(timer,2),
    // Turn off shooter limelight
    CmdTurnOffShooterLimelight(subLimelightShooter),
    // Stop the shoooter wheels
    //CmdStopShooterWheels(subShooter),
    // Turn on intake limelight. Proably don't need to turn on the limelight for the ball color
    //CmdMoveIntake(subIntake, 5800.0),
    // Spin the intake
    //CmdSpinIntake(subIntake),
    // Drive toward ball until ball is picked up
    AutoCmdDrive(subDriveTrain,50,50,timer),
    // Index the shooter
    //CmdIndexShooterFeeder(subIntake),
    // Set the shooter angle this will be upclose shooting to the upper hub
    //CmdSetShooterAngle(subShooter,subLimelightShooter),
    // Spin up Shooter wheels
    //AutoCmdSpinShooterWheels(subShooter, subLimelightShooter),
    // Retract intake
    //CmdMoveIntake(subIntake, 0.0),
    // Stop the intake
    //CmdStopIntake(subIntake),
    // Acquire target
    //CmdAcquireShooterTarget(subLimelightShooter,subDriveTrain),
    // Turn on shooter limelight
    //CmdTurnOnShooterLimelight(subLimelightShooter),
    // Start timer
    //AutoCmdTimer(timer,1),
    // Shoot the ball
    //CmdIndexToShooter(subIntake,subShooter),
    // Start timer
    //AutoCmdTimer(timer,2),
    // Turn off shooter limelight
    //CmdTurnOffShooterLimelight(subLimelightShooter),
    // Extend intake
    //CmdMoveIntake(subIntake, 5600.0),
    // Spin the intake
    //CmdSpinIntake(subIntake),
    // Retract intake
    //CmdMoveIntake(subIntake, 0.0),
    // Stop the intake
    //CmdStopIntake(subIntake),
    // Backup up the robot
    //AutoCmdDrive(subDriveTrain,-10,-10),
     // Turn on the shooter limelight
    //CmdTurnOnShooterLimelight(subLimelightShooter),
    // Set the shooter angle this will be upclose shooting to the upper hub
    //CmdSetShooterAngle(subShooter,subLimelightShooter),
    // Spin up Shooter wheels
    //CmdSpinShooterWheels(subShooter, subLimelightShooter),
    // Shoot the ball
    //CmdIndexToShooter(subIntake,subShooter),
    // Turn off shooter limelight
    //CmdTurnOffShooterLimelight(subLimelightShooter),
    // Stop the shoooter wheels
    //CmdStopShooterWheels(subShooter),
    // Turn to face another alliance ball

    
    // Turn the shooter to face the hub

    // Turn on shooter limelight

    // Acquire the target

    // Shoot the ball

    // Stop the shoooter wheels
    CmdStopShooterWheels(subShooter)
    
  );
}
