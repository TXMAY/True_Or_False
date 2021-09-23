#include "Main_Menu.h"
#include <iostream>

void MainMenu::Setscreen()
{
	system("mode con cols=87 lines=16 | title True Or False");
}

void MainMenu::PrintMainMenu()
{
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(ConsoleHandle, &ConsoleCursor);
	pos = { 0,4 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << ("#####                    ###        ###               #####           #    ###     ### ") << std::endl;
	std::cout << ("  #     # ###   #  #    #   #      #   #   # ###      #        ##     #   #       #   #") << std::endl;
	std::cout << ("  #     ##      #  #    #####      #   #   ##         #####   #  #    #    ###    #####") << std::endl;
	std::cout << ("  #     #       #  #    #          #   #   #          #       #  #    #       #   #    ") << std::endl;
	std::cout << ("  #     #        ## #    ###        ###    #          #        ## #   #    ###     ### ") << std::endl;
	pos = { 36,10 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << ("  게임시작\n") << std::endl;
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
void MainMenu::HowToPlay()
{
	std::cout << "게임이 시작되면 화면에 수식이 나타납니다." << std::endl;
	std::cout << "수식을 보고 그 식이 참인지 거짓인지를 맞춰주세요.(← : 참, → : 거짓)" << std::endl;
	std::cout << "라이프는 3개이며, 3초내에 정답을 맞춰야 합니다." << std::endl;
	std::cout << "정답을 맞출수록 제한 시간이 짧아집니다." << std::endl;
	std::cout << "메인 메뉴로 돌아가시려면 esc키를 눌러주세요" << std::endl;
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
		if (GetAsyncKeyState(VK_UP)&0x0001)
		{
			select = 0;
			PrintConsole(menu_pos, select);
			--menu;
		}
		if (GetAsyncKeyState(VK_DOWN)&0x0001)
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
		if (menu == 2 && (GetAsyncKeyState(VK_RETURN) & 0x8000))
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
