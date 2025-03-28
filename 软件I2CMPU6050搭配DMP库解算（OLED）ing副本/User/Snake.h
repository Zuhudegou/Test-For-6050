#ifndef __SNAKE_H
#define __SNAKE_H


typedef struct
{
	int x,y;
	
}SnakePart;

typedef struct
{
	SnakePart *body;
	int length;
	int direction; //0-ио 1-ср 2-об 3-вС
	
}Snake;








#endif

