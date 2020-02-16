/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Joystick.h>
#include <frc/PWMVictorSPX.h>
#include <frc/TimedRobot.h>
#include <frc/Timer.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/livewindow/LiveWindow.h>

#include "Drivetrain.hpp"

class Robot : public frc::TimedRobot 
{
public:
    Robot();
    void AutonomousInit() override;
    void AutonomousPeriodic() override ;
    void TeleopInit() override;
    void TeleopPeriodic() override;
    void TestPeriodic() override;

 private:
    frc::Joystick rStick { 1 },
                  lStick { 2 };
    Drivetrain drive;
    frc::LiveWindow& m_lw = *frc::LiveWindow::GetInstance();
};