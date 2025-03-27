#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "MPU6050.h"
#include "inv_mpu.h"

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
		
		OLED_ShowSignedNum(2, 1, Pitch, 5);
		OLED_ShowSignedNum(3, 1, Roll, 5);
		OLED_ShowSignedNum(4, 1, Yaw, 5);
		OLED_ShowSignedNum(2, 8, gx, 5);
		OLED_ShowSignedNum(3, 8, gy, 5);
		OLED_ShowSignedNum(4, 8, gz, 5);
	}
}
