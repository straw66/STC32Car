#include "hw.h"  
#include "motor.h" 

uint8 Car_State_number = 0; //小车状态值
//========================================================================
// 函数: void Motor_Init_Port(void)
// 描述: 初始化红外端口
// 参数: 
// 返回: none.
// 版本: VER1.0
// 日期: 2022-9-24
// 备注: 
//======================================================================== 
void HW_Init_Port(void)
{
	
		P0M0 = 0x00;        
  	P0M0 = 0x00;	//0100 0000 P0.6高阻输入

	
		P4M0 = 0x00;        
  	P4M1 = 0x00;	//1000 0000 P4.7高阻输入
	
	
		P3M0 = 0x00;        
  	P3M0 = 0x00;	 //0000 1100 P3.2/3.3高阻输入

	Get_HW_MR=1;
	Get_HW_ML=1;
	//Get_HW_R=1;
	//Get_HW_L=1 ;
					
				
}
//========================================================================
// 函数: void Calculation_Data(void)
// 描述: 根据状态数值去进行PWM调节
// 参数:
// 返回: Count_State_number  1  前进    
// 返回: Count_State_number  2  左转   
// 返回: Count_State_number  3  右转  
// 版本: VER1.0
// 日期: 2022-9-24
// 备注: 
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



































