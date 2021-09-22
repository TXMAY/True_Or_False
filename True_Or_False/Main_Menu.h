#ifndef __MAIN_MENU_HPP__
#define __MAIN_MENU_HPP__
#include <Windows.h>

class MainMenu
{
private:
	int menu;
	int select;
private:
	COORD pos;
	COORD menu_pos;
public:
	void Setscreen();
	void PrintMainMenu();
	void SetMainMenu();
	void PlayingMainMenu();
	void PrintConsole(COORD pos, int cur);
};
#endif