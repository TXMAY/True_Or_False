#include "Game.h"
#include "Main_Menu.h"
#include <Windows.h>

int main()
{
	Game sys;
	MainMenu mm;
	mm.PlayingMainMenu();
	sys.PlayingGame();
}