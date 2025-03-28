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
	int targetLength; //Ŀ�곤��
	int gameTime; //��Ϸʱ��
	int gameRunning;//��Ϸ����״̬
	
}Game;








#endif

