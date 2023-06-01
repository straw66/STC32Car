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
    
   WTST = 0;  //���ó���ָ����ʱ��������ֵΪ0�ɽ�CPUִ��ָ����ٶ�����Ϊ���
   EAXFR = 1; //��չ�Ĵ���(XFR)����ʹ��
   CKCON = 0; //��߷���XRAM�ٶ�
	 
	 Motor_Init_Port(); //�����ʼ��

	 Timer4Init(); //��ʱ����ʼ��,����ʱ��ʹ��
	
	 Uart1_Init(); //���ڳ�ʼ�� 
  
	 HW_Init_Port(); //����˿�
	
	 LED_Init_Port(); //LED��ʾ
     
     SR04_Init_Port(); // ������IO��ʼ��
  while (1)
	{ 	
        
        
        if(Time_Count>=5) //100ms����һ�γ���������
			{				
				 Count_Number_DATA(); //��������
								
				 Time_Count=0; //���¼�ʱ
	    }  
			
		if(S>=10) //ֱ��
		{ 
                        xunji();
		}			
//		else if(S<20&&S>=10)
//					{ 
//						Car_State_number=2;//����
//						delay_ms(100);
//						
//					}			
		else if(S<10&&S>=3)
					{
						 Car_State_number=7;//����
						 
						 
					}else{

           Car_State_number=7;//����

					}
		  
    }
}
    

void xunji(void)
{
    //���һ�����������м䣬��û��ʶ�𵽣�ֱ��
    if(Get_HW_ML==0&&Get_HW_MR==0)
    {
        Car_State_number=1; //����ֱ�� 
    }
    //��������м�����ʶ�𵽺��ߣ�ֱ��
    if(Get_HW_ML==1&&Get_HW_MR==1)
    {   				
        while(1) //��ֹ���ڹ������Ҫ��������
        {  
            Car_State_number=1; //����ֱ�� 
            if(Get_HW_MR==0||Get_HW_ML==0)
            {  
                break; //����ѭ��
            } 
        }	
    }
    //����������в��⵽����΢��ת��ֱ��
    if(Get_HW_ML==1&&Get_HW_MR==0)// ����ת
    {   							
        while(1) //��ֹ���ڹ������Ҫ��������
        {  
               Car_State_number=4; 					
            if(Get_HW_ML==0||Get_HW_MR==1)
            {  
                break; //����ѭ��
            } 
        }	
    }
    
    //����ģ����в��⵽����΢��ת��ֱ��
    if(Get_HW_ML==0&&Get_HW_MR==1)//����ת
    {   							
        while(1) //��ֹ���ڹ������Ҫ��������
        {  
               Car_State_number=6; //����ת
            if(Get_HW_MR==0||Get_HW_ML==1)
            {  
                break; //����ѭ��
            } 
        }	
    }
			

}