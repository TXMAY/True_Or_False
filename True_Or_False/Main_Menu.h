#ifndef __MAIN_MENU_HPP__
#define __MAIN_MENU_HPP__
#include <Windows.h>

#define MENU_MAX 4
#define MENU_MIN 0

class MainMenu
{
private:
	int menu;
	int cursor;
private:
	COORD pos;
private:
	HANDLE ConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
private:
	CONSOLE_CURSOR_INFO ConsoleCursor;
public:
	void Setscreen();
	void PrintMainMenu();
	void SetMainMenu();
	void HowToPlay();
	void PlayingMainMenu();
	void MainMenuConsole(COORD pos, int cur);
};
#endif