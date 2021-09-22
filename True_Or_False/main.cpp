#include "System.h"
#include "Main_Menu.h"
#include <Windows.h>

int main()
{
	System sys;
	MainMenu mm;
	mm.PlayingMainMenu();
	sys.PlayingGame();
}