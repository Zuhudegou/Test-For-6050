#ifndef __GAME_H
#define __GAME_H
#include "Food.h"
#include "Snake.h"

extern const int OLED_WIDTH;
extern const int OLED_HEIGHT;
extern const int SNAKE_SIZE;
extern const int MAP_WIDTH;
extern const int MAP_HEIGHT; 


void Update_Arrow(float pitch , float roll);





typedef struct
{
	Snake snake;
	Food food;
	int targetLength; //目标长度
	int gameTime; //游戏时间
	int gameRunning;//游戏运行状态
	
}Game;








#endif

