#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "SPI_OLED.h"
#include "mpu6050.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h" 
#include "nRF24L01.h"
#include "floatturn.h"
#include "exti.h"
#include "adc.h"
#include "key.h"

unsigned char TxAddr[]={0x0a,0xbc,0xad,0xce,0x2a};//发送地址
unsigned char TXData[13]={0};
extern unsigned char TranFlag;										//通过中断来实现定时发送数据

int main(void)
 {
	uint16_t AD0, AD1, AD2;												//用于存储ADC值
	float servo[3];																//用于将AD值转换成对应的角度信息
	float storage[3];															//用于存储需要转换后需要显示的数
	unsigned char KeyNum2;												//存储按键信息
	float pitch,roll,yaw; 												//欧拉角
	short aacx,aacy,aacz;													//加速度传感器原始数据
	short gyrox,gyroy,gyroz;											//陀螺仪原始数据
	short temp;																		//温度	   
	
	NVIC_Configuration();
	delay_init(168);		  												//初始化延时函数
	LED_Init();		        												//初始化LED端口
	OLED12864_Init();     												//初始化OLED
	OLED12864_TurnBias(0x7f);											//OLED亮度设置
	OLED12864_DisStr(0,0,0,"TXData:");
	MPU_Init();																		//初始化MPU6050
	nRF24L01_Setup(TxAddr);												//nrf模块初始化
	TimerConfiguration();
	Adc_Init();
	Key_Init();
	
//	 while(1)
//	 {
//	 nRF24L01_Debug();
//	 }
	while(mpu_dmp_init())
 	{OLED12864_Format1(10,20,0,mpu_dmp_init());}
	OLED12864_DisStr(0,10,0,"link1:");
	OLED12864_DisStr(0,20,0,"Link2:");
	OLED12864_DisStr(0,30,0,"base:");
	OLED12864_DisStr(0,40,0,"claw:");
		
	while(1)
	{
		KeyNum2=Key_GetNum2();
		if(KeyNum2 == 'c')
		{
			if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
			{ 
				temp=MPU_Get_Temperature();								//得到温度值
				MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//得到加速度传感器数据
				MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//得到陀螺仪数据
			}
			servo[0]=pitch;
			servo[1]=roll;
			servo[2]=yaw;
			floatturn1(servo,TXData,storage);  					//将servo的float类型的数据转换成unsigned char类型的数据存入TXData中	
			OLED12864_Format4(40,10,0,storage[0]);			//显示陀螺仪pitch数据
			OLED12864_Format4(40,20,0,storage[1]);			//显示陀螺仪roll 数据
			OLED12864_Format4(40,30,0,storage[2]);			//显示陀螺仪yaw  数据
			TXData[0]=Key_GetNum1();
		}
		if(KeyNum2 == 'd')
		{		
			AD0 = Get_Adc_Average(ADC_Channel_0, 1);		//ADC读取电位器value
			AD1 = Get_Adc_Average(ADC_Channel_1, 1);
			AD2 = Get_Adc_Average(ADC_Channel_2, 1);
			
			servo[0] = (float)AD0/4096*180;
			servo[1] = (float)AD1/4096*180;  
			servo[2] = (float)AD2/4096*180;

			OLED12864_Format4(40,10,0,storage[0]);
			OLED12864_Format4(40,20,0,storage[1]);
			OLED12864_Format4(40,30,0,storage[2]);
			
			floatturn2(servo,TXData,storage);  //将servo的float类型的数据转换成unsigned char类型的数据存入TXData中
			TXData[0]=Key_GetNum1();
		}
		if(TXData[0] == 'a')
		{
			OLED12864_Format2(40,40,0,0);
		}
		else
			OLED12864_Format2(40,40,0,1);	
		if(TranFlag)
			{
				nRF24L01_TxDat(TXData,13);
				TranFlag=0;			
			}
	}
}



 



