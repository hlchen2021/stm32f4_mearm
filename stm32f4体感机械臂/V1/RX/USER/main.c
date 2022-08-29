#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "SPI_OLED.h"
#include "nRF24L01.h"
#include "exti.h"
#include "receieveturn.h"
#include "pwm.h"

unsigned char RxAddr[]={0x0a,0xbc,0xad,0xce,0x2a};//���͵�ַ
unsigned char RXData[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char TranFlag;
float mpudata[4]={0};     											//���ڴ洢mpu6050����
int main(void)
 {
	NVIC_Configuration();
	delay_init(168);		  												//��ʼ����ʱ����
	LED_Init();		        												//��ʼ��LED�˿�
	OLED12864_Init();     												//��ʼ��OLED
	OLED12864_TurnBias(0x7f);											//OLED��������
	nRF24L01_Setup(RxAddr);												//nrfģ���ʼ��
	SetRxMode();																	//��������ͨ��ģ��Ϊ����
	WaitingRX();																	//��������
	TIM3_PWM_Init(20000-1,84-1);

	OLED12864_DisStr(0,0,0,"RXData:");
	OLED12864_DisStr(0,10,0,"link1:");
	OLED12864_DisStr(0,20,0,"Link2:");
	OLED12864_DisStr(0,30,0,"base:");
	OLED12864_DisStr(0,40,0,"claw:");
		
	while(1)
	{
		if(GetIRQStatus()==2)		//�ж��Ƿ������ݵ���
			{
				ClearIRQ();						//����ж�
				nRF24L01_RxDat(RXData,13);
				WaitingRX();
			}
			
			turn_charinto_float(RXData,mpudata);
			OLED12864_Format4(40,10,0,mpudata[0]);
			OLED12864_Format4(40,20,0,mpudata[1]);
			OLED12864_Format4(40,30,0,mpudata[2]);
			
			Servo1_SetAngle(mpudata[2]);
			Servo2_SetAngle(mpudata[0]);
			Servo3_SetAngle(mpudata[1]);
			
			if(RXData[0] == 'a')
			{
				Servo4_SetAngle(60);
				OLED12864_Format2(40,40,0,0);
			}
			else
			{
				Servo4_SetAngle(0);
				OLED12864_Format2(40,40,0,1);
			}	
	}
}



 



