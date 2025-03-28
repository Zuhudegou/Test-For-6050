#include "stm32f10x.h"                  // Device header
#include "Snake.h"
#include <stdlib.h>


void Snake_Init(Snake *snake)
{
	snake->body = (SnakePart *)malloc(sizeof(SnakePart) * MAP_WIDTH * MAP_HEIGHT);	
	snake->body[0].x = MAP_WIDTH /2;
	snake->body[0].y = MAP_WIDTH /2;//���ߵ�λ�ó�ʼ�����м��λ��
	snake->length = 1;
	snake->direction = 1;//��ʼ����
	
}

void Snake_UpdateDirection(Snake *snake,float pitch, float roll)
{
	if(pitch > 10)snake->direction = 2; //�����Ǵ���10�� ����
	else if(pitch < -10)snake->direction = 0; //������С��10�� ����
	if(roll >10)snake->direction = 3; //����Ǵ���10�� ����
	else if(roll < -10)snake->direction = 1;//�����С��10�� ����
}

//���ƶ�����
void Snake_Move(Snake *snake)
{
	int NewX = snake->body[0].x;
	int NewY = snake->body[0].y;
	
	switch(snake->direction)
	{
		
		case 0: NewY--;break;
		case 1: NewX++;break;
		case 2: NewY++;break;
		case 3: NewX--;break;
	}
	
	//����Ƿ�����ǽ��
	if(NewX < 0 || NewX >= MAP_WIDTH || NewY < 0 || NewY >= MAP_HEIGHT)
    {
	  return;
    }
	
	//����Ƿ���������
	for(int i = 1;i<snake->length;i++)
	{
		if(snake->body[i].x ==NewX && snake->body[i].x == NewY)
		{
			return;
		}
		
	}
	
	//�����ߵ�λ��
	for(int i = snake->length -1;i>0;i--)
	{
		snake->body[i].x = snake->body[i-1].x;
		snake->body[i].y = snake->body[i-1].y;
	}
	snake->body[0].x = NewX;
	snake->body[0].y = NewY;
}

void Snake_Grow(Snake *snake)
{
	SnakePart newPart = {snake->body[snake->length -1].x,snake->body[snake->length - 1].y};
	snake->body[snake->length] = newPart;
	snake->length++;
}

int Snake_EatFood(Snake *snake,int foodX,int foodY)
{
	if(snake->body[0].x == foodX && snake->body[0].y == foodY)
	{
		Snake_Grow(snake);
	    return 1; //�Ե�����1
	}
	return 0;//û�Ե�����0
}

void Snake_Draw(Snake *snake)
{
	for(int i = 0;i<snake->length;i++)
	{
		for(int x= 0;x<SNAKE_SIZE;x++)
		{
			for(int y = 0;y<SNAKE_SIZE;y++)
			{
				OLED_DrawPoint(snake->body[i].x * SNAKE_SIZE +x,snake->body[i].y * SNAKE_SIZE +y);
			}
		}
	}
}
	
	
	
