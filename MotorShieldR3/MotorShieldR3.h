#ifndef MotorShieldR3_h
#define MotorShieldR3_h

#include "Arduino.h"

class MotorShieldR3
{
	public:
		MotorShieldR3();
		MotorShieldR3(bool channelSelect);
		
		void Forward_2W(int pwmA, int pwmB);
		void Back_2W(int pwmA, int pwmB);
		void RotateLeft_2W(int pwmA, int pwmB);
		void RotateRight_2W(int pwmA, int pwmB);		
		void ForwardRight_2W(int pwmA, int pwmB);		
		void BackRight_2W(int pwmA, int pwmB);
		void ForwardLeft_2W(int pwmA, int pwmB);
		void BackLeft_2W(int pwmA, int pwmB); 
		void Stopped_2W();
		void SetSpeed_2W(int pwmA, int pwmB);
		void SetSpeedLeft_2W(int pwmA);
		void SetSpeedRight_2W(int pwmB);
		
	private:
		bool _channelSelect;
		int	PinIN1;
		int PinIN2;
		int _pinPwmA;
		int PinIN3;
		int PinIN4;
		int _pinPwmB;
		int _pwmA;
		int _pwmB;
};

#endif