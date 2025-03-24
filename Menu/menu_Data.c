#include "Menu.h"

void Menu_RunMainMenu(void)
{
	static struct Option_Class Menu_StartOptionList[] = {
		{"<<<"},
		{"Games", Menu_RunGamesMenu},	   // 游戏
		{"Setting", Menu_RunSettingMenu},  // 设置
		{".."}};

	Menu_RunMenu(Menu_StartOptionList);
}


void Menu_RunGamesMenu(void)
{
	static struct Option_Class Menu_GamesOptionList[] = {
		{"<<<"},
		{"Snake", Game_Snake_Init}, // 贪吃蛇
		{".."}};

	Menu_RunMenu(Menu_GamesOptionList);
}

