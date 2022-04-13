/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/CmdReverseIntake.h"
#include "subsystems/SubIntake.h"

CmdReverseIntake::CmdReverseIntake(SubIntake* subIntake) : m_subIntake(subIntake) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(subIntake);
}

// Called when the command is initially scheduled.
void CmdReverseIntake::Initialize() {
  m_timer.Reset();
  m_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void CmdReverseIntake::Execute() {
  //Spins intake unless we have two cargo
  //if(m_subIntake->GetBallCount()<2){
      m_subIntake->SpinFrontWheels(-0.9);
  //}
}

// Called once the command ends or is interrupted.
void CmdReverseIntake::End(bool interrupted) {}

// Returns true when the command should end.
bool CmdReverseIntake::IsFinished() {

  if(m_timer.HasPeriodPassed((units::time::second_t)1)==true) {
    return true;
  }
  else {
    return false;
  }
}
