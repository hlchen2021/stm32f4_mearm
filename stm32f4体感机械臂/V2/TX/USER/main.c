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

unsigned char TxAddr[]={0xaa,0xbb,0xcc,0xdd,0xee};//���͵�ַ
unsigned char TXData[17]={0};
extern unsigned char TranFlag;										//ͨ���ж���ʵ�ֶ�ʱ��������

int main(void)
 {
	float servo[4];																//���ڽ�ADֵת���ɶ�Ӧ�ĽǶ���Ϣ
	float storage[4];															//���ڴ洢��Ҫת������Ҫ��ʾ����
	u16 adcx;
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
	 
	while(mpu_dmp_init())
 	{OLED12864_Format1(10,20,0,mpu_dmp_init());}
	OLED12864_DisStr(0,10,0,"link1:");
	OLED12864_DisStr(0,20,0,"Link2:");
	OLED12864_DisStr(0,30,0,"base:");
	OLED12864_DisStr(0,40,0,"claw:");
		
	while(1)
	{
		adcx=Get_Adc_Average(ADC_Channel_0,1);			
		
		if(mpu_dmp_get_data(&pitch,&roll,&yaw)==0)
		{ 
			temp=MPU_Get_Temperature();								//�õ��¶�ֵ
			MPU_Get_Accelerometer(&aacx,&aacy,&aacz);	//�õ����ٶȴ���������
			MPU_Get_Gyroscope(&gyrox,&gyroy,&gyroz);	//�õ�����������
		}
		
		servo[0]=pitch;
		servo[1]=roll;
		servo[2]=yaw;
		servo[3]=adcx*0.019;          							//�õ�claw�ĽǶ�ֵ
		floatturn(servo,TXData,storage);  					//��servo��float���͵�����ת����unsigned char���͵����ݴ���TXData��
		
		OLED12864_Format4(40,10,0,storage[0]);			//��ʾ������pitch����
		OLED12864_Format4(40,20,0,storage[1]);			//��ʾ������roll ����
		OLED12864_Format4(40,30,0,storage[2]);			//��ʾ������yaw  ����
		OLED12864_Format4(40,40,0,storage[3]);			//��ʾ������claw ����
		
		if(TranFlag)																//���ݷ���
			{
				nRF24L01_TxDat(TXData,17);
				TranFlag=0;			
			}
	}
}



 



