#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "SPI_OLED.h"
#include "nRF24L01.h"
#include "exti.h"
#include "receieveturn.h"
#include "pwm.h"

unsigned char RxAddr[]={0xaa,0xbb,0xcc,0xdd,0xee};//���͵�ַ
unsigned char RXData[17]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
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
			nRF24L01_RxDat(RXData,17);
			WaitingRX();
		}
		
		turn_charinto_float(RXData,mpudata);
		
		OLED12864_Format4(40,10,0,mpudata[0]);			//��ʾ������pitch����
		OLED12864_Format4(40,20,0,mpudata[1]);			//��ʾ������roll ����
		OLED12864_Format4(40,30,0,mpudata[2]);			//��ʾ������yaw  ����
		OLED12864_Format4(40,40,0,mpudata[3]);			//��ʾ������claw ����
		
		Servo1_SetAngle(mpudata[0]);
		Servo2_SetAngle(mpudata[1]);
		Servo3_SetAngle(mpudata[2]);
		Servo4_SetAngle(mpudata[3]);
	}
}



 



