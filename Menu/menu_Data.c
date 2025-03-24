#include "Menu.h"

void Menu_RunMainMenu(void)
{
	static struct Option_Class Menu_StartOptionList[] = {
		{"<<<"},
		{"Games", Menu_RunGamesMenu},	   // 游戏
		{"Setting", Menu_RunSettingMenu},  // 设置
		{"Information", Menu_Information}, // 信息
		{".."}};

	Menu_RunMenu(Menu_StartOptionList);
}


void Menu_RunGamesMenu(void)
{
	static struct Option_Class Menu_GamesOptionList[] = {
		{"<<<"},
		{"Snake", Game_Snake_Init}, // 贪吃蛇
		//	{"Snake II", Game_Snake_Init},	//贪吃蛇2
		//	{"Snake III", Game_Snake_Init},	//贪吃蛇3
		//	{"Snake IV", Game_Snake_Init},	//贪吃蛇4
		//	{"Snake V", Game_Snake_Init},	//贪吃蛇5
		//	{"Snake VI", Game_Snake_Init},	//贪吃蛇6
		//	{"Snake VII", Game_Snake_Init},	//贪吃蛇7
		//	{"Snake VIII", Game_Snake_Init},//贪吃蛇8
		//	{"Snake IX", Game_Snake_Init},	//贪吃蛇9
		//{"Snake X", Game_Snake_Init},		 // 贪吃蛇10
		{".."}};

	Menu_RunMenu(Menu_GamesOptionList);
}

void Menu_Information(void)
{
	while (1)
	{
		OLED_Clear();

		OLED_Update();
		if (Menu_EnterEvent())
		{
			return;
		}
		if (Menu_BackEvent())
		{
			return;
		}
	}
}

/**********************************************************/
