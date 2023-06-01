#include "hw.h"  
#include "motor.h" 

uint8 Car_State_number = 0; //С��״ֵ̬
//========================================================================
// ����: void Motor_Init_Port(void)
// ����: ��ʼ������˿�
// ����: 
// ����: none.
// �汾: VER1.0
// ����: 2022-9-24
// ��ע: 
//======================================================================== 
void HW_Init_Port(void)
{
	
		P0M0 = 0x00;        
  	P0M0 = 0x00;	//0100 0000 P0.6��������

	
		P4M0 = 0x00;        
  	P4M1 = 0x00;	//1000 0000 P4.7��������
	
	
		P3M0 = 0x00;        
  	P3M0 = 0x00;	 //0000 1100 P3.2/3.3��������

	Get_HW_MR=1;
	Get_HW_ML=1;
	//Get_HW_R=1;
	//Get_HW_L=1 ;
					
				
}
//========================================================================
// ����: void Calculation_Data(void)
// ����: ����״̬��ֵȥ����PWM����
// ����:
// ����: Count_State_number  1  ǰ��    
// ����: Count_State_number  2  ��ת   
// ����: Count_State_number  3  ��ת  
// �汾: VER1.0
// ����: 2022-9-24
// ��ע: 
//========================================================================  
void Adjust_Pwm_data(void)
{
		switch(Car_State_number)
		{
			case 1:  Car_Forword(7);break;
			case 2:  Car_Back(10);;break;
			
			case 3:  Car_Turn_Left(50);break;
			case 4:  Car_Turn_Left(13);break;
			
			case 5:  Car_Turn_Right(50);break; 
			case 6:  Car_Turn_Right(13);break; 
		
			case 7:  Car_Stop();break;
			
			
			default :Car_Stop(); break;
		}	
}



































