#ifndef	__SR04_H
#define	__SR04_H 

#include <STC32G.H> 
#include "timer.h"  

typedef enum 
{
	sleep,	     //睡眠
	startingup,	//开机状态    	
}mstate; 


extern unsigned int S; 
//extern uint8 Car_State_number ;
//extern uint8 Car_State2_number ; 小车状态值

extern bit  flag ; 
void SR04_Init_Port(void);
void Calculation_Data(void);
void Count_Number_DATA(void);
//void Car_Run_State(void);
//void Adjust_Pwm_data(void);

#endif 
