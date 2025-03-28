#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MPU6050.h"
#include "inv_mpu.h"
#include "Game.h"


float Pitch,Roll,Yaw;         //������  Ĭ�ϸ���ֵһ�� ������ ƫ����
int16_t ax,ay,az,gx,gy,gz;    //���ٶ� �����ǽ��ٶ�



uint8_t MPU_Get_Gyroscope(short *gx,short *gy,short *gz);//������
uint8_t MPU_Get_Accelerome(short *ax,short *ay,short *az);//���ٶ�


int main(void)
{
	OLED_Init();
	MPU6050_Init();
	MPU6050_DMP_Init();


	while (1)
	{

		MPU6050_DMP_Get_Data(&Pitch,&Roll,&Yaw);
        Update_Arrow(Pitch,Roll);		
		
		
		
		
		OLED_Update();
	}
}
