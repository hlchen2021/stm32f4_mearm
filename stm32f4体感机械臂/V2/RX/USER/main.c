#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "SPI_OLED.h"
#include "nRF24L01.h"
#include "exti.h"
#include "receieveturn.h"
#include "pwm.h"

unsigned char RxAddr[]={0xaa,0xbb,0xcc,0xdd,0xee};//发送地址
unsigned char RXData[17]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char TranFlag;
float mpudata[4]={0};     											//用于存储mpu6050数据
int main(void)
 {
	NVIC_Configuration();
	delay_init(168);		  												//初始化延时函数
	LED_Init();		        												//初始化LED端口
	OLED12864_Init();     												//初始化OLED
	OLED12864_TurnBias(0x7f);											//OLED亮度设置
	nRF24L01_Setup(RxAddr);												//nrf模块初始化
	SetRxMode();																	//配置无线通信模块为接收
	WaitingRX();																	//开启接收
	TIM3_PWM_Init(20000-1,84-1);

	OLED12864_DisStr(0,0,0,"RXData:");
	OLED12864_DisStr(0,10,0,"link1:");
	OLED12864_DisStr(0,20,0,"Link2:");
	OLED12864_DisStr(0,30,0,"base:");
	OLED12864_DisStr(0,40,0,"claw:");
		
	while(1)
	{
	if(GetIRQStatus()==2)		//判断是否有数据到来
		{
			ClearIRQ();						//清除中断
			nRF24L01_RxDat(RXData,17);
			WaitingRX();
		}
		
		turn_charinto_float(RXData,mpudata);
		
		OLED12864_Format4(40,10,0,mpudata[0]);			//显示陀螺仪pitch数据
		OLED12864_Format4(40,20,0,mpudata[1]);			//显示陀螺仪roll 数据
		OLED12864_Format4(40,30,0,mpudata[2]);			//显示陀螺仪yaw  数据
		OLED12864_Format4(40,40,0,mpudata[3]);			//显示陀螺仪claw 数据
		
		Servo1_SetAngle(mpudata[0]);
		Servo2_SetAngle(mpudata[1]);
		Servo3_SetAngle(mpudata[2]);
		Servo4_SetAngle(mpudata[3]);
	}
}



 



