#ifndef __FOOD_H
#define __FOOD_H

#include "OLED.h"
#include <stdlib.h>

extern const int OLED_WIDTH;
extern const int OLED_HEIGHT;
extern const int SNAKE_SIZE;
extern const int MAP_WIDTH;
extern const int MAP_HEIGHT; 

typedef struct
{
	int x,y;
	
}Food;

void Food_Init(Food *food);
void Food_Draw(Food *food);







#endif


