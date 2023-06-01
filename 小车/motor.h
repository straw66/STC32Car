#ifndef	__MOTOR_H
#define	__MOTOR_H 

#include <STC32G.H> 
#include "timer.h" 

void Motor_Init_Port(void); 
void Car_Forword(uint8 pwm_perent); 
void Car_Back(uint8 pwm_perent);
void Car_Turn_Left(uint8 pwm_perent);
void Car_Turn_Right(uint8 pwm_perent);
void Car_Turn_Right1(uint8 pwm_perent);
void Car_Stop(void);

#endif 
