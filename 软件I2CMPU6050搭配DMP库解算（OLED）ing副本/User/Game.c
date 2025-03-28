#include "stm32f10x.h"                  // Device header
#include "Game.h"
#include "OLED.h"
#include <stdlib.h>
#include "mpu6050.h"

 const int OLED_WIDTH = 128;
 const int OLED_HEIGHT = 64;
 const int SNAKE_SIZE = 4;
 const int MAP_WIDTH = (OLED_WIDTH / SNAKE_SIZE);
 const int MAP_HEIGHT = (OLED_HEIGHT / SNAKE_SIZE);









//初始化蛇
void Game_Init(Game *game)
{
    Snake_Init(&game->snake);
	Food_Init(&game->food);
	
	game->targetLength = 10;
	game->gameTime = 0;
	game->gameRunning = 1;

}

void Game_Update(Game *game,float pitch,float roll)
{
	Snake_UpdateDirection(&game->snake,pitch,roll);
	Snake_Move(&game->snake);
	if(Snake_EatFood(&game->snake,game->food.x,game->food.y))
	{
		Food_Init(&game->food);
		game->gameTime++;
	}
	
	if(game->snake.length >= game->targetLength)
	{
		game->gameRunning = 0;
	}
	
}

void Game_Draw(Game *game)
{
	OLED_Clear();
	Snake_Draw(&game->snake);
	Food_Draw(&game->food);
	
	char buffer[32];
	sprintf(buffer,"Length:%d%d",game->snake.length,game->targetLength);
	OLED_ShowString(1,1,buffer,OLED_6X8);
	sprintf(buffer,"Time: %d s",game->gameTime);
	OLED_ShowString(0,1,buffer,OLED_6X8);
}

void Game_Reset(Game *game)
{
	game->gameRunning = 1;
	free(game->snake.body);
	Game_Init(game);
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


