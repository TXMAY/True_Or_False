#include "System.h"
#include <Windows.h>
#include <iostream>

void System::SetRandomValue()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> ran_val(0, 9);
	std::uniform_int_distribution<int> ran_oper(1, 6);
	val1 = ran_val(gen);
	val2 = ran_val(gen);
	num_oper = ran_oper(gen);
}
void System::SetOperator()
{
	switch (num_oper)
	{
	case 1:
		str_oper = "<";
		break;
	case 2:
		str_oper = ">";
		break;
	case 3:
		str_oper = "<=";
		break;
	case 4:
		str_oper = ">=";
		break;
	case 5:
		str_oper = "!=";
		break;
	case 6:
		str_oper = "==";
		break;
	default:
		break;
	}
}
void System::Setscreen()
{
	system("mode con cols=87 lines=16 | title True Or False");
}
void System::SetMainMenu()
{
	menu = 1;

	while (true)
	{
		if (GetAsyncKeyState(VK_UP)&0x8001)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menu_pos);
			std::cout << (" ");
			--menu;
		}
		if (GetAsyncKeyState(VK_DOWN)&0x8001)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menu_pos);
			std::cout << (" ");
			++menu;
		}
		if (menu >= 4)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menu_pos);
			std::cout << (" ");
			menu = 1;
		}
		if (menu <= 0)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menu_pos);
			std::cout << (" ");
			menu = 3;
		}
		switch (menu)
		{
		case 1:
			menu_pos = { 36,10 };
			break;
		case 2:
			menu_pos = { 36,12 };
			break;
		case 3:
			menu_pos = { 38,14 };
			break;
		default:
			break;
		}
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menu_pos);
		std::cout << ("¢º");
		Sleep(100);
	}
}