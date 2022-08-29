#include "exti.h"

void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��1���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��2���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;				//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��3���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;				//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��4���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;				//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��5���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;				//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 5;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��6���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM6_DAC_IRQn;				//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
		
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��7���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;				//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 7;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
		
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//��ʱ��8���ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = TIM8_UP_TIM13_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
		
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//�������ȼ��ַ��� 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			//ָ����IRQ�ж� 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//��ռ���ȼ��� 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			//��Ӧ���ȼ���
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);
}
/*******************************************************************************
���ƣ�void TIM1_IRQHandler(void)
���ܣ���ʱ��1���жϷ�����
��ڲ�������
���ڲ�������
˵������
***********************************************************************************/
// unsigned short Timer1Counter;//��ʱ��1��ִ�м�����
// extern unsigned char Beep;//����Ч���ı���
// extern unsigned short SoundCounter;//��������ʱ������

// void TIM1_UP_IRQHandler(void)
// {
// 	Timer1Counter++;
// 	TIM_ClearITPendingBit(TIM1, TIM_IT_Update);					//����жϱ�־
// 	
// 	BuzzerOut();
// 	
// 	
// 	if(Timer1Counter == 100) //100*10ms=1s
// 	{
// 		LED2Reverse();
// 		Timer1Counter=0;
// 	}
// }
/*******************************************************************************
���ƣ�void TIM2_IRQHandler(void)
���ܣ���ʱ��2���жϷ�����
��ڲ�������
���ڲ�������
˵������
************************************************************************************/

//unsigned short Timer2Counter=0;
//unsigned char TranFlag=0;
//extern unsigned char TXData[17];
//void TIM2_IRQHandler(void)
//{
//	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);					//����жϱ�־
//	Timer2Counter++;
//// 	switch(GetKeyStatus())
//// 	{
//// 		case 1: Beep=5;break;
//// 		case 2: Beep=6;break;
//// 		case 3: Beep=3;break;
//// 		case 4: Beep=4;break;
//// 		default:break;
//// 	}
//	if(Timer2Counter==1)
//	{
//		Timer2Counter=0;
//		TranFlag=1;
//	}		
//}











