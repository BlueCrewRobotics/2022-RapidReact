/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/

#include "subsystems/BC_FalconFX.h"

BC_FalconFX::BC_FalconFX(int device) {
    BC_FalconFX::ptr_falconFX = new TalonFX(device);
}

void BC_FalconFX::Set(double speed) {
  		
	speed = speed*m_dMaxSpeed;
	ptr_falconFX->Set(m_ControlMode, speed);
	m_dSpeed = speed;
}

void BC_FalconFX::Disable() {
  ptr_falconFX->SetNeutralMode(NeutralMode::Coast);
}

void BC_FalconFX::StopMotor() {
  ptr_falconFX->SetNeutralMode(NeutralMode::Brake);
}

double BC_FalconFX::Get() const {
	return m_dSpeed;

}

void BC_FalconFX::SetInverted(bool invert) {
	if(invert == true)
	{
		ptr_falconFX->SetInverted(TalonFXInvertType::Clockwise);
	}
	else{
		ptr_falconFX->SetInverted(TalonFXInvertType::CounterClockwise);
	}
}

bool BC_FalconFX::GetInverted() const {
	return ptr_falconFX->GetInverted();

}

void BC_FalconFX::SetControlMode(ctre::phoenix::motorcontrol::ControlMode mode) {
	m_ControlMode = mode;

}

void BC_FalconFX::SetConfig_kF(int profileSlot, double value) {
	ptr_falconFX->Config_kF(profileSlot, value, 0);
}

void BC_FalconFX::SetConfig_kP(int profileSlot, double value) {
	ptr_falconFX->Config_kP(profileSlot, value, 0);
}

void BC_FalconFX::SetConfig_kI(int profileSlot, double value) {
	ptr_falconFX->Config_kI(profileSlot, value, 0);
}

void BC_FalconFX::SetConfig_kD(int profileSlot, double value) {
	ptr_falconFX->Config_kD(profileSlot, value, 0);
}

void BC_FalconFX::ClearStickyFault() {
	ptr_falconFX->ClearStickyFaults();
}

void BC_FalconFX::SetFollower(TalonFX* motor) {
	ptr_falconFX->Follow(*motor);
	ptr_falconFX->SetInverted(TalonFXInvertType::FollowMaster);

}

TalonFX* BC_FalconFX::GetMotorController() {
	return ptr_falconFX;
}

void BC_FalconFX::SetSelectedFeedbackSensor(FeedbackDevice device) {
	ptr_falconFX->ConfigSelectedFeedbackSensor(device);

}

void BC_FalconFX::SetStatorCurrentLimit(bool enable, double limit, double trigger, double triggerTime) {
	ptr_falconFX->ConfigStatorCurrentLimit(StatorCurrentLimitConfiguration(enable,limit,trigger,triggerTime));

}

void BC_FalconFX::SetSupplyCurrentLimit(bool enable, double limit, double trigger, double triggerTime) {
	ptr_falconFX->ConfigSupplyCurrentLimit(SupplyCurrentLimitConfiguration(enable,limit,trigger,triggerTime));
	
}

