#include "Arduino.h"
#include "MotorShieldR3.h"

MotorShieldR3::MotorShieldR3()
{
	//Channel A left
	pinMode(12, OUTPUT);
	PinIN1 = 12;
	pinMode(9, OUTPUT);
	PinIN2 = 9;
	pinMode(3, OUTPUT);
	_pinPwmA = 3;
	//Channel B Right
	pinMode(13, OUTPUT);
	PinIN3 = 13;
	pinMode(8, OUTPUT);
	PinIN4 = 8;
	pinMode(11, OUTPUT);
	_pinPwmB = 11;
}


//-----------------Motores izquierdo y derecho independientes-----------------------

void MotorShieldR3::Forward_2W(int pwmA, int pwmB){
	_pwmA = pwmA;
	_pwmB = pwmB;
	digitalWrite(PinIN1,HIGH);
	digitalWrite(PinIN2,LOW);
	analogWrite(_pinPwmA,_pwmA);
	digitalWrite(PinIN3,HIGH);
	digitalWrite(PinIN4,LOW);
	analogWrite(_pinPwmB,_pwmB);
}
void MotorShieldR3::Back_2W(int pwmA, int pwmB){
	_pwmA = pwmA;
	_pwmB = pwmB;
	digitalWrite(PinIN1,LOW);
	digitalWrite(PinIN2,HIGH);
	analogWrite(_pinPwmA,_pwmA);
	digitalWrite(PinIN3,LOW);
	digitalWrite(PinIN4,HIGH);
	analogWrite(_pinPwmB,_pwmB);
}
void MotorShieldR3::RotateLeft_2W(int pwmA, int pwmB){
	_pwmA = pwmA;
	_pwmB = pwmB;
	digitalWrite(PinIN1,LOW);
	digitalWrite(PinIN2,HIGH);
	analogWrite(_pinPwmA,_pwmA);
	digitalWrite(PinIN3,HIGH);
	digitalWrite(PinIN4,LOW);
	analogWrite(_pinPwmB,_pwmB);
}
void MotorShieldR3::RotateRight_2W(int pwmA, int pwmB){
	_pwmA = pwmA;
	_pwmB = pwmB;
	digitalWrite(PinIN1,HIGH);
	digitalWrite(PinIN2,LOW);
	analogWrite(_pinPwmA,_pwmA);
	digitalWrite(PinIN3,LOW);
	digitalWrite(PinIN4,HIGH);
	analogWrite(_pinPwmB,_pwmB);
}
void MotorShieldR3::ForwardLeft_2W(int pwmA, int pwmB){
	_pwmA = pwmA;
    digitalWrite(PinIN1,HIGH);
	digitalWrite(PinIN2,LOW);
	digitalWrite(_pinPwmA,_pwmA);
	digitalWrite(PinIN3,HIGH);
	digitalWrite(PinIN4,LOW);
	analogWrite(_pinPwmB,HIGH);
}
void MotorShieldR3::ForwardRight_2W(int pwmA, int pwmB){
	_pwmB = pwmB;
	digitalWrite(PinIN1,HIGH);
	digitalWrite(PinIN2,LOW);
	digitalWrite(_pinPwmA,HIGH);
	digitalWrite(PinIN3,HIGH);
	digitalWrite(PinIN4,LOW);
	analogWrite(_pinPwmB,_pwmB);
}
void MotorShieldR3::BackLeft_2W(int pwmA, int pwmB){
	_pwmA = pwmA;
	digitalWrite(PinIN1,LOW);
	digitalWrite(PinIN2,HIGH);
	digitalWrite(_pinPwmA,_pwmA);
	digitalWrite(PinIN3,LOW);
	digitalWrite(PinIN4,HIGH);
	analogWrite(_pinPwmB,HIGH);
}
void MotorShieldR3::BackRight_2W(int pwmA, int pwmB){
	_pwmB = pwmB;
	digitalWrite(PinIN1,LOW);
	digitalWrite(PinIN2,HIGH);
	digitalWrite(_pinPwmA,HIGH);
	digitalWrite(PinIN3,LOW);
	digitalWrite(PinIN4,HIGH);
	analogWrite(_pinPwmB,_pwmB);
}
void MotorShieldR3::Stopped_2W(){
	_pwmA = 0;
	_pwmB = 0;
	digitalWrite(PinIN1,LOW);
	digitalWrite(PinIN2,LOW);
	analogWrite(_pinPwmA,_pwmA);
	digitalWrite(PinIN3,LOW);
	digitalWrite(PinIN4,LOW);
	analogWrite(_pinPwmB,_pwmB);
}
void MotorShieldR3::SetSpeed_2W(int pwmA, int pwmB){
	_pwmA = pwmA;
	_pwmB = pwmB;
	analogWrite(_pinPwmA,_pwmA);
	analogWrite(_pinPwmB,_pwmB);
}
void MotorShieldR3::SetSpeedLeft_2W(int pwmA){
	_pwmA = pwmA;
	analogWrite(_pinPwmA,_pwmA);
}
void MotorShieldR3::SetSpeedRight_2W(int pwmB){
	_pwmB = pwmB;
	analogWrite(_pinPwmB,_pwmB);
}
