#include <STC32G.H>
#include "intrins.h"
#include "delay.h"  
#include "motor.h" 
#include "timer.h"    
#include "uart1.h" 
#include "sr04.h" 
#include "hw.h" 
#include "LED.h" 


void xunji(void);

void main(void)
{
    
   WTST = 0;  //设置程序指令延时参数，赋值为0可将CPU执行指令的速度设置为最快
   EAXFR = 1; //扩展寄存器(XFR)访问使能
   CKCON = 0; //提高访问XRAM速度
	 
	 Motor_Init_Port(); //电机初始化

	 Timer4Init(); //定时器初始化,计数时间使用
	
	 Uart1_Init(); //串口初始化 
  
	 HW_Init_Port(); //红外端口
	
	 LED_Init_Port(); //LED显示
     
     SR04_Init_Port(); // 超声波IO初始化
  while (1)
	{ 	
        
        
        if(Time_Count>=5) //100ms更新一次超声波距离
			{				
				 Count_Number_DATA(); //测量距离
								
				 Time_Count=0; //重新计时
	    }  
			
		if(S>=10) //直走
		{ 
                        xunji();
		}			
//		else if(S<20&&S>=10)
//					{ 
//						Car_State_number=2;//后退
//						delay_ms(100);
//						
//					}			
		else if(S<10&&S>=3)
					{
						 Car_State_number=7;//后退
						 
						 
					}else{

           Car_State_number=7;//后退

					}
		  
    }
}
    

void xunji(void)
{
    //情况一：黑线在正中间，都没有识别到，直走
    if(Get_HW_ML==0&&Get_HW_MR==0)
    {
        Car_State_number=1; //慢速直走 
    }
    //情况二：中间两个识别到黑线，直走
    if(Get_HW_ML==1&&Get_HW_MR==1)
    {   				
        while(1) //防止由于拐弯过大，要纠正回来
        {  
            Car_State_number=1; //慢速直走 
            if(Get_HW_MR==0||Get_HW_ML==0)
            {  
                break; //跳出循环
            } 
        }	
    }
    //情况三：左中侧检测到，稍微左转后直走
    if(Get_HW_ML==1&&Get_HW_MR==0)// 慢左转
    {   							
        while(1) //防止由于拐弯过大，要纠正回来
        {  
               Car_State_number=4; 					
            if(Get_HW_ML==0||Get_HW_MR==1)
            {  
                break; //跳出循环
            } 
        }	
    }
    
    //情况四：右中侧检测到，稍微右转后直走
    if(Get_HW_ML==0&&Get_HW_MR==1)//慢右转
    {   							
        while(1) //防止由于拐弯过大，要纠正回来
        {  
               Car_State_number=6; //慢右转
            if(Get_HW_MR==0||Get_HW_ML==1)
            {  
                break; //跳出循环
            } 
        }	
    }
			

}