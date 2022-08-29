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

unsigned char TxAddr[]={0x0a,0xbc,0xad,0xce,0x2a};//���͵�ַ
unsigned char TXData[13]={0};
extern unsigned char TranFlag;										//ͨ���ж���ʵ�ֶ�ʱ��������

int main(void)
 {
	uint16_t AD0, AD1, AD2;												//���ڴ洢ADCֵ
	float servo[3];																//���ڽ�ADֵת���ɶ�Ӧ�ĽǶ���Ϣ
	float storage[3];															//���ڴ洢��Ҫת������Ҫ��ʾ����
	unsigned char KeyNum2;												//�洢������Ϣ
	float pitch,roll,yaw; 												//ŷ����
	short aacx,aacy,aacz;													//���ٶȴ�����ԭʼ����
	short gyrox,gyroy,gyroz;											//������ԭʼ����
	short temp;																		//�¶�	   
	
	NVIC_Configuration();
	delay_init(168);		  												//��ʼ����ʱ����
	LED_Init();		        												//��ʼ��LED�˿�
	OLED12864_Init();     												//��ʼ��OLED
	OLED12864_TurnBias(0x7f);											//OLED��������
	OLED12864_DisStr(0,0,0,"TXData:");
	MPU_Init();																		//��ʼ��MPU6050
	nRF24L01_Setup(TxAddr);												//nrfģ���ʼ��
	TimerConfiguration();
	Adc_Init();
	Key_Init();
	 
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
				temp=MPU_Get_Temperature();								//�õ��¶�ֵ
				MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
				MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
			}
			servo[0]=pitch;
			servo[1]=roll;
			servo[2]=yaw;
			floatturn1(servo,TXData,storage);  					//��servo��float���͵�����ת����unsigned char���͵����ݴ���TXData��	
			OLED12864_Format4(40,10,0,storage[0]);			//��ʾ������pitch����
			OLED12864_Format4(40,20,0,storage[1]);			//��ʾ������roll ����
			OLED12864_Format4(40,30,0,storage[2]);			//��ʾ������yaw  ����
			TXData[0]=Key_GetNum1();
		}
		if(KeyNum2 == 'd')
		{		
			AD0 = Get_Adc_Average(ADC_Channel_0, 1);		//ADC��ȡ��λ��value
			AD1 = Get_Adc_Average(ADC_Channel_1, 1);
			AD2 = Get_Adc_Average(ADC_Channel_2, 1);
			
			servo[0] = (float)AD0/4096*180;
			servo[1] = (float)AD1/4096*180;  
			servo[2] = (float)AD2/4096*180;

			OLED12864_Format4(40,10,0,storage[0]);
			OLED12864_Format4(40,20,0,storage[1]);
			OLED12864_Format4(40,30,0,storage[2]);
			
			floatturn2(servo,TXData,storage);  //��servo��float���͵�����ת����unsigned char���͵����ݴ���TXData��
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



 



