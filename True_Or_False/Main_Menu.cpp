#include "Main_Menu.hpp"
#include "Common.hpp"
#include <iostream>

void MainMenu::Setscreen()
{
	system("mode con cols=87 lines=17 | title True Or False");
}
void MainMenu::PrintMainMenu()
{
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(ConsoleHandle, &ConsoleCursor);
	SetPosition(0, 4);
	std::cout << ("#####                    ###        ###               #####           #    ###     ### ") << std::endl;
	std::cout << ("  #     # ###   #  #    #   #      #   #   # ###      #        ##     #   #       #   #") << std::endl;
	std::cout << ("  #     ##      #  #    #####      #   #   ##         #####   #  #    #    ###    #####") << std::endl;
	std::cout << ("  #     #       #  #    #          #   #   #          #       #  #    #       #   #    ") << std::endl;
	std::cout << ("  #     #        ## #    ###        ###    #          #        ## #   #    ###     ### ") << std::endl;
	SetPosition(38, 10);
	std::cout << ("게임시작\n") << std::endl;
	SetPosition(38, 12);
	std::cout << ("게임방법\n") << std::endl;
	SetPosition(40, 14);
	std::cout << ("옵션") << std::endl;
	MadeByTXMAY();
}
void MainMenu::MainMenuConsole(COORD pos, int cur)
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
void MainMenu::HowToPlay()
{
	SetPosition(0, 5);
	std::cout << "                        게임이 시작되면 화면에 수식이 나타납니다.                      " << std::endl;
	std::cout << "           수식을 보고 그 식이 참인지 거짓인지를 맞춰주세요.(← : 참, → : 거짓)         " << std::endl;
	std::cout << "                    라이프는 3개이며, 3초내에 정답을 맞춰야 합니다.                    " << std::endl;
	std::cout << "    정답을 맞출수록 제한 시간이 짧아집니다(easy : -0.1, normal : -0.2, hard : -0.3).   " << std::endl;
	MadeByTXMAY();
	while (true)
	{
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
		{
			system("cls");
			break;
		}
	}
}
void MainMenu::SetMainMenu()
{
	menu = 1;

	while (true)
	{
		if (GetAsyncKeyState(VK_UP) & 0x0001)
		{
			cursor = 0;
			MainMenuConsole(pos, cursor);
			--menu;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		{
			cursor = 0;
			MainMenuConsole(pos, cursor);
			++menu;
		}
		if (menu >= MENU_MAX)
		{
			cursor = 0;
			MainMenuConsole(pos, cursor);
			menu = 1;
		}
		if (menu <= MENU_MIN)
		{
			cursor = 0;
			MainMenuConsole(pos, cursor);
			menu = 3;
		}
		switch (menu)
		{
		case 1:
			pos = { 36,10 };
			cursor = 1;
			MainMenuConsole(pos, cursor);
			break;
		case 2:
			pos = { 36,12 };
			cursor = 1;
			MainMenuConsole(pos, cursor);
			break;
		case 3:
			pos = { 38,14 };
			cursor = 1;
			MainMenuConsole(pos, cursor);
			break;
		default:
			break;
		}
		if (menu == 1 && (GetAsyncKeyState(VK_RETURN) & 0x0001))
		{
			system("cls");
			break;
		}
		if (menu == 2 && (GetAsyncKeyState(VK_RETURN) & 0x0001))
		{
			system("cls");
			HowToPlay();
			PrintMainMenu();
		}
	}
}
void MainMenu::PlayingMainMenu()
{
	Setscreen();
	PrintMainMenu();
	SetMainMenu();
}