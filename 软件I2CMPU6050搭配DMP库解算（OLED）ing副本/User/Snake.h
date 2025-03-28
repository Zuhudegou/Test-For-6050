#ifndef __SNAKE_H
#define __SNAKE_H

#include "OLED.h"




typedef struct
{
	int x,y;
	
}SnakePart;

typedef struct
{
	SnakePart *body;
	int length;
	int direction; //0-�� 1-�� 2-�� 3-��
	
}Snake;








#endif

