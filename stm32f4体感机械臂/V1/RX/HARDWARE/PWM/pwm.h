#ifndef _TIMER_H
#define _TIMER_H
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//STM32F4????ģ??-?⺯???汾
//?Ա????̣?http://mcudev.taobao.com								  
////////////////////////////////////////////////////////////////////////////////// 	

void TIM3_PWM_Init(u32 arr,u32 psc);
void TIM5_PWM_Init(u32 arr,u32 psc);
void Servo1_SetAngle(float Angle);
void Servo2_SetAngle(float Angle);
void Servo3_SetAngle(float Angle);
void Servo4_SetAngle(float Angle);
#endif
