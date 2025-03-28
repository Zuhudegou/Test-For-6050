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
	int direction; //0-�� 1-�� 2-�� 3-��
	
}Snake;



//��ʼ����
void Snake_Init(Snake *snake);
//�����ߵ�λ�û���MPU6050
void Snake_UpdateDirection(Snake *snake,float pitch, float roll);
//���ƶ�����
void Snake_Move(Snake *snake);
//�߳�����߼�
void Snake_Grow(Snake *snake);
//�߳Ե�ʳ�ﺯ��
int Snake_EatFood(Snake *snake,int foodX,int foodY);
//�����ߺ���
void Snake_Draw(Snake *snake);
	







#endif

