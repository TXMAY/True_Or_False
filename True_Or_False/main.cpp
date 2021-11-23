#include "Game.hpp"
#include "Main_Menu.hpp"
#include <Windows.h>

int main()
{
	Game game;
	MainMenu mm;
	while (true)
	{
		mm.PlayingMainMenu();
		game.PlayingGame();
		Sleep(50);
	}
}