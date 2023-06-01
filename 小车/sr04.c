#include "sr04.h"    
#include "delay.h" 
#include "uart1.h"  
#include "motor.h"  
#include "timer.h" 
#include "hw.h"
sbit Trig = P1^3;
sbit Echo = P4^0;
//uint8 Car_State_number = 0; //С��״ֵ̬
//uint8 Car_State2_number = 0; //С��״ֵ̬
/*******************************************************************************
* �� �� ��         : SR04_Init_Port(); 

* ��������		   : ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void SR04_Init_Port(void)
{
		P1M0 = 0x00;        //��P2.0,P2.1,P2.2,P2.3�ڵ�������Ϊ˫�����ģʽ  0000 1111
  	P1M1 = 0x00;	
	
		P4M0 = 0x00;        //��P1.4,P1.5,P1.6,P1.7�ڵ�������Ϊ˫�����ģʽ  0000 1111
  	P4M1 = 0x00;	 
	
}
//========================================================================
// ����: void Motor_Init_Port(void)
// ����: ��ʱ������
// ����: ��ʼ������˿�
// ����: none.
// �汾: VER1.0
// ����: 2022-9-24
// ��ע: 
//======================================================================== 
 void  StartModule(void) 		         //����ģ��
  {
	  Trig=1;			                     //����һ��ģ��
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
// ����: void Count_Number_DATA(void)
// ����: ��ȡ����
// ����: 
// ����: none.
// �汾: VER1.0
// ����: 2022-9-24
// ��ע: 
//======================================================================== 
void Count_Number_DATA(void)
{
		   StartModule(); //����ģ��
	     while(!Echo);		//��RXΪ��ʱ�ȴ�
	     TR0=1;			    //��������
	     while(Echo);			//��RXΪ1�������ȴ�
	     TR0=0;				//�رռ���   
       Calculation_Data();	
}
//========================================================================
// ����: void Calculation_Data(void)
// ����: ��������
// ����:
// ����: none.
// �汾: VER1.0
// ����: 2022-9-24
// ��ע: 
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
	 S=(time*1.87)/100/2;     //�������CM  
	ET0=1;
    
   //Uart_Send_ADC_data(S);  //�����ݷ�������
	
}
//========================================================================
// ����: void Calculation_Data(void)
// ����: ����״̬��ֵȥ����PWM����
// ����:
// ����: Count_State_number  1  ǰ��   
// ����: Count_State_number  2  ����   
// ����: Count_State_number  3  ��ת   
// ����: Count_State_number  4  ��ת  
// ����: Count_State_number  5  ֹͣ 
// �汾: VER1.0
// ����: 2022-9-24
// ��ע: 
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





















