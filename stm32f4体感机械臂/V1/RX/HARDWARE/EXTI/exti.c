#include "exti.h"

void NVIC_Configuration(void)
{
	NVIC_InitTypeDef NVIC_InitStructure; 
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//定时器1优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = TIM1_UP_TIM10_IRQn;			//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//定时器2优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;				//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//定时器3优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;				//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//定时器4优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;				//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//定时器5优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;				//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 5;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//定时器6优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = TIM6_DAC_IRQn;				//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 6;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
		
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//定时器7优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = TIM7_IRQn;				//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 7;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
		
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);				//定时器8优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = TIM8_UP_TIM13_IRQn;			//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//串口优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;			//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//串口优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;			//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//串口优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;			//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//串口优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = UART4_IRQn;			//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
		
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//串口优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI1_IRQn;			//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//串口优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI0_IRQn;			//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//串口优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;			//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//串口优先级分分组 
	NVIC_InitStructure.NVIC_IRQChannel = EXTI15_10_IRQn;			//指定的IRQ中断 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;	//抢占优先级别 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;			//响应优先级别
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);
}
/*******************************************************************************
名称：void TIM1_IRQHandler(void)
功能：定时器1的中断服务函数
入口参数：无
出口参数：无
说明：无
***********************************************************************************/
// unsigned short Timer1Counter;//定时器1的执行计数器
// extern unsigned char Beep;//音响效果的变量
// extern unsigned short SoundCounter;//蜂鸣器定时计数器

// void TIM1_UP_IRQHandler(void)
// {
// 	Timer1Counter++;
// 	TIM_ClearITPendingBit(TIM1, TIM_IT_Update);					//清除中断标志
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
名称：void TIM2_IRQHandler(void)
功能：定时器2的中断服务函数
入口参数：无
出口参数：无
说明：无
************************************************************************************/

//unsigned short Timer2Counter=0;
//unsigned char TranFlag=0;
//extern unsigned char TXData[17];
//void TIM2_IRQHandler(void)
//{
//	TIM_ClearITPendingBit(TIM2, TIM_IT_Update);					//清除中断标志
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











