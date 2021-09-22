#include "Main_Menu.h"
#include <iostream>

void MainMenu::Setscreen()
{
	system("mode con cols=87 lines=16 | title True Or False");
}

void MainMenu::PrintMainMenu()
{
	pos = { 0,4 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << ("#####                    ###        ###               #####           #    ###     ### ") << std::endl;
	std::cout << ("  #     # ###   #  #    #   #      #   #   # ###      #        ##     #   #       #   #") << std::endl;
	std::cout << ("  #     ##      #  #    #####      #   #   ##         #####   #  #    #    ###    #####") << std::endl;
	std::cout << ("  #     #       #  #    #          #   #   #          #       #  #    #       #   #    ") << std::endl;
	std::cout << ("  #     #        ## #    ###        ###    #          #        ## #   #    ###     ### ") << std::endl;
	pos = { 36,10 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << ("▶ 게임시작\n") << std::endl;
	pos = { 36,12 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << ("  게임방법\n") << std::endl;
	pos = { 38,14 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << ("  옵션") << std::endl;
}
void MainMenu::PrintConsole(COORD pos, int cur)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	switch (cur)
	{
	case 0:
		std::cout << (" ");
		break;
	case 1:
		std::cout << ("▶");
		break;
	default:
		break;
	}
}
void MainMenu::SetMainMenu()
{
	menu = 1;

	while (true)
	{
		if (GetAsyncKeyState(VK_UP))
		{
			select = 0;
			PrintConsole(menu_pos, select);
			--menu;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			select = 0;
			PrintConsole(menu_pos, select);
			++menu;
		}
		if (menu >= 4)
		{
			select = 0;
			PrintConsole(menu_pos, select);
			menu = 1;
		}
		if (menu <= 0)
		{
			select = 0;
			PrintConsole(menu_pos, select);
			menu = 3;
		}
		switch (menu)
		{
		case 1:
			menu_pos = { 36,10 };
			select = 1;
			PrintConsole(menu_pos, select);
			break;
		case 2:
			menu_pos = { 36,12 };
			select = 1;
			PrintConsole(menu_pos, select);
			break;
		case 3:
			menu_pos = { 38,14 };
			select = 1;
			PrintConsole(menu_pos, select);
			break;
		default:
			break;
		}
		if (menu == 1 && (GetAsyncKeyState(VK_RETURN) & 0x8000))
		{
			system("cls");
			break;
		}
		Sleep(100);
	}
}
void MainMenu::PlayingMainMenu()
{
	Setscreen();
	PrintMainMenu();
	SetMainMenu();
}