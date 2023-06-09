#include "timer.h"   
 #include "hw.h"  
#include "motor.h" 
#include "sr04.h"
/*--------------------------------------------------------------*/
/* --- -----------------实验内容 -------------------------------*/
/* --- 1-了解STC-ISP工具生产延时函数方法 -----------------------*/
/* --- 2-掌握子函数的创建与调用---------------------------------*/
/* --- 实验平台：未来电子STC32核心板----------------------------*/
/* --- 视频学习：https://space.bilibili.com/494969171 ----------*/
/* --- QQ交流群：702805632 -------------------------------------*/
/* --- 参考资料：STC32实验室参考例程 ---------------------------*/
/*--------------------------------------------------------------*/ 

uint16 Time_Count = 0; 
uint8 Time_Count_pwm = 0; 
uint8 PWM_Count = 40; //占空比

void Timer0Init(void)
{
//	AUXR |= 0x80;                   //定时器0为1T模式
//	TMOD &= 0xF8;                   //定时器0设置为定时方式，工作模式为16位自动重装模式
//	TMOD &= 0xF7;                   //定时器0门控位GATE设置为0 
	TMOD=0x21; //设T0为方式1，GATE=1；
  SCON=0x50;  
	
	TL0 = 0x00;                     //1T模式下初始装载值       
	TH0 = 0x00;                     //1T模式下初始装载值  
	TF0 = 0;                        //清除T0中断溢出标志位
	ET0 = 1;                        //使能定时器0的溢出中断允许位
	TR0 = 1;                        //定时器0开始计时 
  EA = 1;           //使能总中断
}

/***********************************************************
功能描述：定时器4初始化  1MS
入口参数：无
返回值：无
************************************************************/
void Timer4Init(void)
{
	T4T3M &= 0xBF;                  //定时器4设置为定时方式
	T4T3M |= 0x20;                  //设置定时器4为1T模式
	T4L = 0x90;                     //1T模式下初始装载值 
	T4H = 0xE8;                     //1T模式下初始装载值 
	IE2  |=  (1<<6);	              //使能定时器4中断
	T4T3M |= 0x80;                  //打开定时器4
} 

void timer0_int (void) interrupt 1
{
	

}

/***********************************************************
功能描述：定时器4中断服务程序
入口参数：无
返回值：无       250us进入1次中断 
************************************************************/
void timer4_int (void) interrupt 20
{
	  if(++Time_Count>=4000) //最长计时间 1s
		{
       Time_Count=0;
		}	 
  	 if(++Time_Count_pwm>100)
	 {
		  Time_Count_pwm=0;
	 } 
	 if(Time_Count_pwm>=PWM_Count)//PWM调速
	 {
		  Car_Stop(); //置为低电平	 
		 
	 }else{		 
		 
      Adjust_Pwm_data();//调节PWM
        
	 } 
} 

/*********************************END FILE********************************************/	




































