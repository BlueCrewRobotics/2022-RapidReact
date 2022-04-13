/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h"

RobotContainer::RobotContainer() : m_autoAutonomous(&m_subLimelightShooter, &m_subShooter, &m_subIntake, &m_subDriveTrain,&autoTimer) {
  // Initialize all of your commands and subsystems here

  // Configure the button bindings
  ConfigureButtonBindings();

  // Set the default command for the Drive Train
  m_subDriveTrain.SetDefaultCommand(CmdDriveWithController(&m_subDriveTrain, driverController, &m_subLimelightIntake));
  //m_subClimber.SetDefaultCommand(CmdClimberUp(&m_subClimber, auxController));
  //m_subClimber.SetDefaultCommand(CmdClimberDown(&m_subClimber, auxController));
  m_subClimber.SetDefaultCommand(CmdClimberControl(&m_subClimber, auxController));


}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here

  // Setup the command to shift gears when right bumper is pressed
  driverController_button_lbump->WhenPressed(CmdShiftGear(&m_subDriveTrain));
  
  driverController_button_a->WhileHeld(frc2::ParallelCommandGroup{
    CmdTurnOnShooterLimelight(&m_subLimelightShooter), 
    CmdSetShooterAngle(&m_subShooter,&m_subLimelightShooter), 
    CmdAcquireShooterTarget(&m_subLimelightShooter,&m_subDriveTrain),
    CmdSpinShooterWheels(&m_subShooter,&m_subLimelightShooter)});

  driverController_button_a->WhenReleased(frc2::SequentialCommandGroup{
    CmdTurnOffShooterLimelight(&m_subLimelightShooter)
    //CmdResetShooterAngle(&m_subShooter), // Use this to set the angle for the shot up against the fender upper hub
    //CmdStopShooterWheels(&m_subShooter)
    });

  //driverController_button_x->WhenPressed(new CmdFeedBallToShooter(&m_subIntake)); This new command needs to be created with the Shooter Feeder
  // Way to add debouce on the buttons
  //driverController_button_b->Debounce(60_ms,frc::Debouncer::kBoth).WhileActiveContinous(new CmdSetShooterAngle(&m_subShooter));


  //********************************************************************************
  // Combine the CmdSpinIntake and CmdStopIntake into one command passing the speed!
  //********************************************************************************
  driverController_button_y->WhileHeld(frc2::SequentialCommandGroup( CmdSpinIntake(&m_subIntake), CmdMoveIntake(&m_subIntake, 5800.0), CmdIndexShooterFeeder(&m_subIntake)));
  driverController_button_y->WhenInactive(frc2::SequentialCommandGroup( CmdStopIntake(&m_subIntake),CmdMoveIntake(&m_subIntake, 0.0)));
  
  driverController_button_x->WhenPressed(CmdIndexToShooter(&m_subIntake,&m_subShooter));

  driverController_button_start->WhenPressed(CmdStopShooterWheels(&m_subShooter));
  driverController_button_select->WhenPressed(frc2::SequentialCommandGroup(CmdReverseShooterFeeder(&m_subIntake),CmdReverseIntake(&m_subIntake),CmdStopIntake(&m_subIntake)));

  //auxController_button_a->WhenPressed

  auxController_button_lbump->WhenPressed(CmdClimberGrabBar(&m_subClimber));
  auxController_button_rbump->WhenPressed(CmdClimberAngled(&m_subClimber));
  //auxController_button_rbump->WhileHeld(CmdClimberUp(&m_subClimber));
  //auxController_button_rbump->WhenReleased(CmdClimberStop(&m_subClimber));
  //auxController_button_lbump->WhileHeld(CmdClimberDown(&m_subClimber));
  //auxController_button_lbump->WhenReleased(CmdClimberStop(&m_subClimber));

  auxController_button_y->WhenPressed(CmdHubSelect(&m_subShooter, true));
  auxController_button_a->WhenPressed(CmdHubSelect(&m_subShooter, false));
  
  //auxController_button_x->WhenReleased(CmdStopIntake(&m_subIntake));
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  //return &m_autonomousCommand;
  //return &m_autoAutonomous;

}

void RobotContainer::ConfigureDrive() {
  m_subDriveTrain.DriveTrainConfigure();
  m_subDriveTrain.GetPidFromDashboard();

}

void RobotContainer::ConfigureShooter() {
  m_subShooter.ConfigureShooter();
}

void RobotContainer::ConfigureCompressor() {
  m_subPneumatics.ConfigureCompressor();
}

void RobotContainer::ConfigureIntake() {
  m_subIntake.ConfigureIntake();
}

void RobotContainer::ConfigureLimelights() {
  m_subLimelightShooter.SetLEDState(1.0);
  m_subLimelightIntake.SetLEDState(1.0);
  
}

void RobotContainer::ConfigureClimber() {
  m_subClimber.ConfigureClimber();
}

double RobotContainer::GetAuxDPadValue() {
  auxController->GetPOV();
}

void RobotContainer::ResetDriveEncoders(){
    m_subDriveTrain.ResetEncoderPositions();
}