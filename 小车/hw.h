#ifndef	__HW_H
#define	__HW_H 

#include <STC32G.H> 
#include "timer.h"   



#define  Get_HW_ML  P33 

#define  Get_HW_MR  P06



extern uint8 Car_State_number ;

void HW_Init_Port(void);
void Adjust_Pwm_data(void); 
void Get_HW_State(void);




#endif 
