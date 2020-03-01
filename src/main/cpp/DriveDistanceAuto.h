#ifndef DriveDistanceAuto_H
#define DriveDistanceAuto_H

#include "../AutoBase.h"

class DriveDistanceAuto: public AutoBase
{
private:
	double m_distance;
	double m_offset;
	double m_rightSpeed;
	double m_leftSpeed;
public:
	DriveDistanceAuto(double rightSpeed, double leftSpeed, double distance) : AutoBase("DriveDistanceAuto"){
		Requires(driveTrain.get());
		m_rightSpeed = rightSpeed;
		m_leftSpeed = leftSpeed;
		m_distance = distance;
		m_offset = 0;
	}
	void Initialize(){
		m_offset = driveTrain->GetEncoderPos();
		driveTrain->TankRaw(-m_rightSpeed,-m_leftSpeed);
	}
	void Execute(){}
	bool IsFinished(){
		SmartDashboard::PutNumber("Offset Encoder Pos", driveTrain->GetEncoderPos() - m_offset);
		if (m_distance > 0) {
			return driveTrain->GetEncoderPos() > m_distance + m_offset;
		} else {
			return driveTrain->GetEncoderPos() < m_distance + m_offset;
		}
	}
	void End(){
		driveTrain->SetToVoltageMode();
		driveTrain->StopMotors();
	}
	void Interrupted(){
		End();
	}
};

#endif
