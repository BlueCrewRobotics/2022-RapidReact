// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
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
#include "commands/CmdAcquireShooterTarget.h"
#include "commands/CmdSpinIntake.h"
#include "commands/CmdStopIntake.h"
#include "commands/CmdMoveIntake.h"
#include "commands/CmdIndexShooterFeeder.h"
#include "commands/CmdIndexToShooter.h"

// Autonomous commands
#include "autocommands/AutoCmdDrive.h"
#include "autocommands/AutoCmdTimer.h"
#include "autocommands/AutoCmdSpinShooterWheels.h"


// Subsystem includes
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/SubDriveTrain.h"
#include "subsystems/SubPneumatics.h"
#include "subsystems/SubShooter.h"
#include "subsystems/SubLimelightShooter.h"
#include "subsystems/SubLimelightIntake.h"
#include "subsystems/SubIntake.h"

class AutoCmdAutonomous
    : public frc2::CommandHelper<frc2::SequentialCommandGroup, AutoCmdAutonomous> {
 public:
  AutoCmdAutonomous(SubLimelightShooter* subLimelightShooter, SubShooter* subShooter, SubIntake* subIntake, SubDriveTrain* subDriveTrain, frc::Timer* timer);
};
