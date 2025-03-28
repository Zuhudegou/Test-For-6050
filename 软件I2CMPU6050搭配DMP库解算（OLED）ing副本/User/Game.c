#include "stm32f10x.h"                  // Device header
#include "Game.h"
#include "OLED.h"
#include <stdlib.h>

 const int OLED_WIDTH = 128;
 const int OLED_HEIGHT = 64;
 const int SNAKE_SIZE = 4;
 const int MAP_WIDTH = (OLED_WIDTH / SNAKE_SIZE);
 const int MAP_HEIGHT = (OLED_HEIGHT / SNAKE_SIZE);









//初始化蛇
void Game_Init(Game *game)
{
	game->snake.body = (SnakePart *)malloc(sizeof(SnakePart) * MAP_WIDTH * MAP_HEIGHT);	
	game->snake.body[0].x = MAP_WIDTH /2;
	game->snake.body[0].y = MAP_WIDTH /2;//将蛇的位置初始化在中间的位置
	game->snake.length = 1;
	game->snake.direction = 1;//初始向右
	
	game->food.x = rand()% MAP_WIDTH;
	game->food.y = rand()% MAP_HEIGHT;
	
	game->targetLength = 10;
	game->gameTime = 0;
	game->gameRunning = 1;

}

void Game_Update(Game *game)
{
	
	
	
	
}










//箭头调试
void Update_Arrow(float pitch , float roll)
{
	OLED_Clear();
	
	OLED_ShowSignedNum(1,20,pitch,2,OLED_8X16);
	OLED_ShowSignedNum(1,40,roll,2,OLED_8X16);

	if(pitch>10)
	{
		OLED_ShowImage(75,50,15,15,ArrowDown);
	}
	else if(pitch<-10)
	{
		OLED_ShowImage(75,20,15,15,ArrowUp);
	}
	
	if(roll>10)
	{
		OLED_ShowImage(60,35,15,15,ArrowLeft);
	}
	else if(roll<-10)
	{
		OLED_ShowImage(90,35,15,15,ArrowRight);
	}
		
	
}


