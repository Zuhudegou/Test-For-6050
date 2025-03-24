#include "stm32f10x.h" // Device header
#include "Delay.h"
#include "Timer.h"
#include "Encoder.h"
#include "Key.h"
#include "OLED.h"
#include "Menu.h"

int Power_Off(void); // 关机

int main(void)
{
	Timer_Init();
	OLED_Init();
	Encoder_Init();
	Key_Init();
	
	while (1)
	{
		Menu_RunMainMenu();

		Power_Off();
	}
}

int Power_Off(void) 
{
	OLED_Clear();
	OLED_Update();
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, ENABLE); 
	PWR_WakeUpPinCmd(ENABLE);

	PWR_EnterSTOPMode(PWR_Regulator_ON, PWR_STOPEntry_WFI); 
	SystemInit();

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR, DISABLE);
	PWR_WakeUpPinCmd(DISABLE);

	Key_Reset_All();
	Key_Reset_All();

	return 1;
}

