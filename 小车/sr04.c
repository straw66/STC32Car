#include "sr04.h"    
#include "delay.h" 
#include "uart1.h"  
#include "motor.h"  
#include "timer.h" 
#include "hw.h"
sbit Trig = P1^3;
sbit Echo = P4^0;
//uint8 Car_State_number = 0; //小车状态值
//uint8 Car_State2_number = 0; //小车状态值
/*******************************************************************************
* 函 数 名         : SR04_Init_Port(); 

* 函数功能		   : 主函数
* 输    入         : 无
* 输    出         : 无
*******************************************************************************/
void SR04_Init_Port(void)
{
		P1M0 = 0x00;        //将P2.0,P2.1,P2.2,P2.3口单独设置为双向输出模式  0000 1111
  	P1M1 = 0x00;	
	
		P4M0 = 0x00;        //将P1.4,P1.5,P1.6,P1.7口单独设置为双向输出模式  0000 1111
  	P4M1 = 0x00;	 
	
}
//========================================================================
// 函数: void Motor_Init_Port(void)
// 描述: 延时函数。
// 参数: 初始化电机端口
// 返回: none.
// 版本: VER1.0
// 日期: 2022-9-24
// 备注: 
//======================================================================== 
 void  StartModule(void) 		         //启动模块
  {
	  Trig=1;			                     //启动一次模块
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_();
	  _nop_(); 
	  _nop_(); 
	  _nop_(); 
	  _nop_();
	  Trig=0;
  }
//========================================================================
// 函数: void Count_Number_DATA(void)
// 描述: 获取数据
// 参数: 
// 返回: none.
// 版本: VER1.0
// 日期: 2022-9-24
// 备注: 
//======================================================================== 
void Count_Number_DATA(void)
{
		   StartModule(); //启动模块
	     while(!Echo);		//当RX为零时等待
	     TR0=1;			    //开启计数
	     while(Echo);			//当RX为1计数并等待
	     TR0=0;				//关闭计数   
       Calculation_Data();	
}
//========================================================================
// 函数: void Calculation_Data(void)
// 描述: 计算数据
// 参数:
// 返回: none.
// 版本: VER1.0
// 日期: 2022-9-24
// 备注: 
//======================================================================== 
unsigned int  time=0; 
unsigned int S=0; 
bit  flag =0;
void Calculation_Data(void)
{
    ET0=0;
	 time=TH0*256+TL0;
	 TH0=0;
	 TL0=0;
	 S=(time*1.87)/100/2;     //算出来是CM  
	ET0=1;
    
   //Uart_Send_ADC_data(S);  //把数据发到串口
	
}
//========================================================================
// 函数: void Calculation_Data(void)
// 描述: 根据状态数值去进行PWM调节
// 参数:
// 返回: Count_State_number  1  前进   
// 返回: Count_State_number  2  后退   
// 返回: Count_State_number  3  左转   
// 返回: Count_State_number  4  右转  
// 返回: Count_State_number  5  停止 
// 版本: VER1.0
// 日期: 2022-9-24
// 备注: 
//========================================================================  
//void Adjust_Pwm_data(void)
//{
//		switch(Car_State_number)
//		{
//			case 1:  Car_Forword(10);break;
//			case 2:  Car_Back(10);break;
//			case 3:  Car_Turn_Left(20);break;
//			case 4:  Car_Turn_Right(20);break;
//			case 5:  Car_Stop();break;
//			default :Car_Stop(); break;
//		}	
//}





















