#include "stm32f10x.h"                  // Device header
#include "Food.h"

void Food_Init(Food *food)
{
	food->x = rand()% MAP_WIDTH;
	food->y = rand()% MAP_HEIGHT;
}


void Food_Draw(Food *food)
{
	for(int i = 0;i<SNAKE_SIZE;i++)
	{
		for(int j = 0;j<SNAKE_SIZE;j++)
		{
			OLED_DrawPoint(food->x * SNAKE_SIZE + i,food->y * SNAKE_SIZE + j);
		}
	}
	
}



