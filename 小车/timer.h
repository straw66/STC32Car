#ifndef	__TIMER_H
#define	__TIMER_H 

#include <STC32G.H> 

#define  uint32   unsigned long
#define  uint16   unsigned int  
#define  uint8    unsigned char  


extern uint8 PWM_Count ;  
extern uint16 Time_Count;  

void Timer0Init(void);
void Timer4Init(void);



#endif 
