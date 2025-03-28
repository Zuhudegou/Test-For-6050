#ifndef __SNAKE_H
#define __SNAKE_H

#include "OLED.h"

extern const int OLED_WIDTH;
extern const int OLED_HEIGHT;
extern const int SNAKE_SIZE;
extern const int MAP_WIDTH;
extern const int MAP_HEIGHT; 




typedef struct
{
	int x,y;
	
}SnakePart;

typedef struct
{
	SnakePart *body;
	int length;
	int direction; //0-上 1-右 2-下 3-左
	
}Snake;



//初始化蛇
void Snake_Init(Snake *snake);
//更新蛇的位置基于MPU6050
void Snake_UpdateDirection(Snake *snake,float pitch, float roll);
//蛇移动函数
void Snake_Move(Snake *snake);
//蛇长大的逻辑
void Snake_Grow(Snake *snake);
//蛇吃到食物函数
int Snake_EatFood(Snake *snake,int foodX,int foodY);
//绘制蛇函数
void Snake_Draw(Snake *snake);
	







#endif

