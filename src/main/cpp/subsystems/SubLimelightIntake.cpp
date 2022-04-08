/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
/*                       Blue Crew Robotics #6153                             */
/*                           Rapid React 2022                                 */
/*-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=*/
// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubLimelightIntake.h"

SubLimelightIntake::SubLimelightIntake() = default;

// This method will be called once per scheduler run
void SubLimelightIntake::Periodic() {
  SetCameraMode(1);
}

/**
 * Get whether or not limelight has a target
 */
bool SubLimelightIntake::GetTarget() {
  if(tblLimelightShooter->GetNumber("tv",0.0) < 1.0){
    return false;
  }
  return true;
  
}

  /**
     Get horizontal Offset from Crosshair to target
   */
  double SubLimelightIntake::GetHorizontalOffset(){
    return tblLimelightShooter->GetNumber("tx",0.0);

  }
  
  /**
     Get the distance from the target
     
     d = (h2-h1) / tan(a1+a2)

     d = distance from camera to target on horizontal plane
     h1 = the height of the camera from the ground
     h2 = the height of the center of the target
     a1 = the angle of the camera with respect to ground
     a2 = the angle of the target with respect to the camera ( limelight will give this angle "ty" from network tables)

    */
  double SubLimelightIntake::GetDistanceToTarget(){
    double d = 0.0; // feet
    double h1 = (26.5/12); // feet
    double h2 = (98.25/12); // feet
    double a1 = 13.46; // degrees
    double a2 = tblLimelightShooter->GetNumber("ty",0.0);    
    
    d = (h2-h1) / (tan((a1 + a2)*3.1416/180));

    return d;

  }
 
   /**
      Get the skew of the target
    */
  double SubLimelightIntake::GetSkew(){
    return tblLimelightShooter->GetNumber("ts",0.0);

  }
  
  /**
     Get the camera mounting angle
     
     d = (h2-h1) / tan(a1+a2)

     d = distance from camera to target on horizontal plane meaured with tape measure
     h1 = the height of the camera from the ground
     h2 = the height of the center of the target
     a1 = the angle of the camera with respect to ground
     a2 = the angle of the target with respect to the camera ( limelight will give this angle "ty" from network tables)

   */
  double SubLimelightIntake::GetCameraMountAngle(double distance){
    double d = distance;
    double h1 = (26.5/12); // inches
    double h2 = (98.25/12); // inches
    double a1 = 0.0; // degrees
    double a2 = tblLimelightShooter->GetNumber("ty",0.0);
    
    a1 = (atan((h2-h1)/d)-(a2*3.1416/180))*180/3.1416;

    
    
    return a1;

  }

  /**
     Set the Limelight LED state.
        
    0 - Use the LED Mode set in the current pipeline
    1 - Force LEDS off
    2 - Force LEDs to blink
    3 - Force LEDs on
   
    @param mode the mode to set for the LEDs
   */
  void SubLimelightIntake::SetLEDState(int mode){
    tblLimelightShooter->PutNumber("ledMode",mode);

  }

  /** Set the Limelight camera mode.
    
    0 - Use Vision processing
    1 - Use Limeligt as Driver Camera (Increases exposure, disables vision processing)
   
    @param mode the mode to set for the Camera
  */
  void SubLimelightIntake::SetCameraMode(int mode){
    tblLimelightShooter->PutNumber("camMode",mode);

  }
  
  /** Select the vision pipline to use for targeting.
    
    0 - 9 Vision pipeline to use
    
    @param pipeline the pipeline to select for the vision targeting
  */
  void SubLimelightIntake::SelectPipeline(int pipeline){
    tblLimelightShooter->PutNumber("pipeline",pipeline);

  }

  /** Select limelight's streaming mode.
    
    0 - Standard Side-by-Side stream if a webcam is attached to limelight.
    1 - PiP Main - The secondary camera stream is placed in the lower-right corner of the primary camera stream
    2 - PiP Secondary - The primary camera stream is placed in the lower-right corner of the secondary camera stream
    
    @param mode the streaming mode selected
  */
  void SubLimelightIntake::SelectStreamMode(int mode){
    tblLimelightShooter->PutNumber("stream",mode);

  }

  /** Select limelight's snapshot mode.
    
    0 - Stop taking snapshots.
    1 - Take two snapshots per second
    
    @param mode the streaming mode selected
  */
  void SubLimelightIntake::SelectSnapshotMode(int mode){
    tblLimelightShooter->PutNumber("snapshot",mode);

  }

  /** Get the Limelight distance value
   * Returns the stored distance
   */
  double SubLimelightIntake::GetLimelightDistance(){
    return m_distance;

  }

  /** Set the Limelight distance value
   * 
   * @param distance the distance to the target
   */
  void SubLimelightIntake::SetLimelightDistance(double distance){
    m_distance = distance;

  }
