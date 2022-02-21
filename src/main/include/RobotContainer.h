/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/Command.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Joystick.h>
#include <frc2/command/button/JoystickButton.h>
#include <frc2/command/SequentialCommandGroup.h>
#include <frc2/command/ParallelCommandGroup.h>

// Command includes
#include "commands/ExampleCommand.h"
#include "commands/CmdDriveWithController.h"
#include "commands/CmdShiftGear.h"
#include "commands/CmdSpinShooterWheels.h"
#include "commands/CmdStopShooterWheels.h"
#include "commands/CmdSetShooterAngle.h"
#include "commands/CmdResetShooterAngle.h"
#include "commands/CmdIntakeToHomePosition.h"
#include "commands/CmdExtendIntake.h"
#include "commands/CmdTurnOnShooterLimelight.h"
#include "commands/CmdTurnOffShooterLimelight.h"
#include "commands/CmdAcquireShooterTarget.h" //This might have to be seperated into 2 commands AcquireTarget and AimToTarget
#include "commands/CmdSpinIntake.h"
#include "commands/CmdStopIntake.h"


// Subsystem includes
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubPneumatics.h"
#include "subsystems/SubShooter.h"
#include "subsystems/SubLimelightShooter.h"
#include "subsystems/SubLimelightIntake.h"
#include "subsystems/SubIntake.h"

#include "Constants.h"



/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

  // Configure the drive train run this function in RobotInit()
  void ConfigureDrive();
  // Configure the compressor run this function in RobotInit()
  void ConfigureCompressor();
  // Configure the shooter run this function in RobotInit()
  void ConfigureShooter();

  // Run the autonomous code this should run in AutonomousPeriodic()
  void BlueCrewAutonomous();


 private:
  // The robot's subsystems and commands are defined here...
  ExampleSubsystem m_subsystem;
  ExampleCommand m_autonomousCommand;

  
  // The robot's subsystems
  SubDriveTrain m_subDriveTrain;
  SubPneumatics m_subPneumatics;
  SubShooter m_subShooter;
  SubLimelightShooter m_subLimelightShooter;
  SubLimelightIntake m_subLimelightIntake;
  SubIntake m_subIntake;
  
  // Setup driver controller
  frc::Joystick *driverController = new frc::Joystick(DRIVER_CONTROLLER);

  // LEFT TRIGGER // Drive Backwards use driverController->GetRawAxis(AXIS_L_TRIG)
  // RIGHT TRIGGER // Drive Forwards use driverController->GetRawAxis(AXIS_R_TRIG)
  // LEFT STICK LEFT // Turn Left driverController->GetRawAxis(AXIS_LX)
  // LEFT STICK RIGHT // Turn Right driverController->GetRawAxis(AXIS_LX)
  
  frc2::JoystickButton *driverController_button_a = new frc2::JoystickButton(driverController, BUTTON_A); // Not Used
  frc2::JoystickButton *driverController_button_b = new frc2::JoystickButton(driverController, BUTTON_B); // Low gear mode
  frc2::JoystickButton *driverController_button_x = new frc2::JoystickButton(driverController, BUTTON_X); // Not Used
  frc2::JoystickButton *driverController_button_y = new frc2::JoystickButton(driverController, BUTTON_Y); // Intake ball
  frc2::JoystickButton *driverController_button_lbump = new frc2::JoystickButton(driverController, BUTTON_L_BUMP); // Not Used
  frc2::JoystickButton *driverController_button_rbump = new frc2::JoystickButton(driverController, BUTTON_R_BUMP); // Used in gear shifting
  frc2::JoystickButton *driverController_button_select = new frc2::JoystickButton(driverController, BUTTON_SELECT); // Not Used 
  frc2::JoystickButton *driverController_button_start = new frc2::JoystickButton(driverController, BUTTON_START); // Not Used
  frc2::JoystickButton *driverController_button_l3 = new frc2::JoystickButton(driverController, BUTTON_L3); // Not Used
  frc2::JoystickButton *driverController_button_r3 = new frc2::JoystickButton(driverController, BUTTON_R3); // Not Used

  // Setup auxilary controller   
  frc::Joystick *auxController = new frc::Joystick(AUX_CONTROLLER);

  frc2::JoystickButton *auxController_button_a = new frc2::JoystickButton(auxController, BUTTON_A);  
  frc2::JoystickButton *auxController_button_b = new frc2::JoystickButton(auxController, BUTTON_B); 
  frc2::JoystickButton *auxController_button_x = new frc2::JoystickButton(auxController, BUTTON_X); 
  frc2::JoystickButton *auxController_button_y = new frc2::JoystickButton(auxController, BUTTON_Y); 
  frc2::JoystickButton *auxController_button_lbump = new frc2::JoystickButton(auxController, BUTTON_L_BUMP); 
  frc2::JoystickButton *auxController_button_rbump = new frc2::JoystickButton(auxController, BUTTON_R_BUMP); 
  frc2::JoystickButton *auxController_button_select = new frc2::JoystickButton(auxController, BUTTON_SELECT); 
  frc2::JoystickButton *auxController_button_start = new frc2::JoystickButton(auxController, BUTTON_START); 
  frc2::JoystickButton *auxController_button_l3 = new frc2::JoystickButton(auxController, BUTTON_L3); 
  frc2::JoystickButton *auxController_button_r3 = new frc2::JoystickButton(auxController, BUTTON_R3);   

  // Autonomous buttons
  frc2::Trigger* autoDrive = new frc2::Trigger();
  frc2::Trigger* autoShoot = new frc2::Trigger();


  void ConfigureButtonBindings();
};
