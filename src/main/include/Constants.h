/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
// Falcon, Talon and Victor CAN Bus addressing
constexpr int MOTOR_LEFT_MASTER = 1;
constexpr int MOTOR_RIGHT_MASTER = 2;
constexpr int MOTOR_LEFT_FOLLOWER = 3;
constexpr int MOTOR_RIGHT_FOLLOWER = 4;

// Continuous current limit for Talons in amps
constexpr int CONTINUOUS_CURRENT_LIMIT = 20;
// Peak current limit for the Talons in amps
constexpr int PEAK_CURRENT_LIMIT = 30;
// Peak current duration for Talons in ms
constexpr int DURATION_CURRENT_LIMIT = 500;

// Ramp Times for drive starting and stopping
constexpr double DRIVE_RAMP_TIME = 0.05;

// Maximum velocity in units/100ms
constexpr int VELOCITY_MAX = 19000;
constexpr int VELOCITY_SP_MAX_HG = 19000;  // Maximum velocity in actual high gear
constexpr int VELOCITY_SP_MAX_LG = 19000;  // Maximum velocity in actual low gear
constexpr int VELOCITY_SP_MAX_LL = 5000;   // Maximum velocity in low low virtual gear


// PID constants PID[0] Used for low speed right side
constexpr double RIGHT_KF_0 = 0.0274; // 0.07; // 0.13;  // Kf = ((percent of output used for control)*1023) / (max encoder units)/100ms
constexpr double RIGHT_KP_0 = 0.16;// 0.286;  // Kp = ((percent of output used for control)*1023) / Error
constexpr double RIGHT_KI_0 = 0.0;
constexpr double RIGHT_KD_0 = 0.0;

// PID constants PID[0] Used for low speed right side
constexpr double LEFT_KF_0 = 0.0274; // 0.0465; //0.13; // Kf = ((percent of output used for control)*1023) / (max encoder units)/100ms
constexpr double LEFT_KP_0 = 0.14;// 0.123; // Kp = ((percent of output used for control)*1023) / Error
constexpr double LEFT_KI_0 = 0.0;
constexpr double LEFT_KD_0 = 0;

// PID constants PID[1] uesd for high speed left side
constexpr double RIGHT_KF_1 = 0.13; 
constexpr double RIGHT_KP_1 = 0.0;
constexpr double RIGHT_KI_1 = 0;
constexpr double RIGHT_KD_1 = 0;

// PID constants PID[1] uesd for high speed left side
constexpr double LEFT_KF_1 = 0.13;
constexpr double LEFT_KP_1 = 0.0;
constexpr double LEFT_KI_1 = 0;
constexpr double LEFT_KD_1 = 0;

// Controllers
constexpr int DRIVER_CONTROLLER = 0;
constexpr int AUX_CONTROLLER = 1;

/*
   Game controller button and joystick addressing.
   Access in code by including RobotMap.h and using BUTTON_A
   */
constexpr int BUTTON_A = 1;
constexpr int BUTTON_B = 2;
constexpr int BUTTON_X = 3;
constexpr int BUTTON_Y = 4;
constexpr int BUTTON_L_BUMP = 5;
constexpr int BUTTON_R_BUMP = 6; // Drive gear sifting
constexpr int BUTTON_SELECT = 7;
constexpr int BUTTON_START = 8;
constexpr int BUTTON_L3 = 9;
constexpr int BUTTON_R3 = 10;

constexpr int AXIS_LX = 0; // Steer left/right
constexpr int AXIS_LY = 1;
constexpr int AXIS_L_TRIG = 2; // Forward driving
constexpr int AXIS_R_TRIG = 3; // Reverse driving
constexpr int AXIS_RX = 4;
constexpr int AXIS_RY = 5;

// PCM Module CAN ID
constexpr int PCM_0 = 9;

// Solenoid Mappings for Shifter PCM
constexpr int PCM_0_GEARSHIFT = 0;  // Drive train gear shifter
constexpr int PCM_0_MOTOR_COOLING = 1; // Drive train motor cooling
constexpr int PCM_2_CLIMBER_STRAIGHT = 2;
constexpr int PCM_3_CLIMBER_ANGLED = 3;
constexpr int PCM_4_CLIMBER_HOOK = 4;
// Shooter Configuration
constexpr int SHOOTER_TOP_ADDR = 13;
constexpr int SHOOTER_BTM_ADDR = 14;
constexpr int SHOOTER_RIGHT_PWM_ADDR = 0;
constexpr int SHOOTER_LEFT_PWN_ADDR = 1;

// Intake Configuration
constexpr int INTAKE_SPINNER_ADDR = 15;
constexpr int INTAKE_SHOOTER_FEEDER_ADDR = 16;
constexpr int INTAKE_POSITIONER_ADDR = 17;

// Climber Configuration
constexpr int CLIMBER_MAIN_ADDR = 18;
constexpr int CLIMBER_SECONDARY_ADDR = 19;