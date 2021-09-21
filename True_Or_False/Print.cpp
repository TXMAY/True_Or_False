#include "System.h"
#include <iostream>
#include <Windows.h>

void System::PrintRandomValue()
{
	std::cout << val1 << " " << str_oper << " " << val2 << std::endl;
}
void System::PrintAnswer()
{
	switch (num_oper)
	{
	case 1:
		answer = val1 < val2;
		break;
	case 2:
		answer = val1 > val2;
		break;
	case 3:
		answer = val1 <= val2;
		break;
	case 4:
		answer = val1 >= val2;
		break;
	case 5:
		answer = val1 != val2;
		break;
	case 6:
		answer = val1 == val2;
		break;
	default:
		break;
	}
	if (timer <= 0)
	{
		std::cout << "시간 초과" << std::endl;
		--life;
	}
	else if (answer == key)
	{
		std::cout << "정답" << std::endl;
		++score;
	}
	else
	{
		std::cout << "오답" << std::endl;
		--life;
	}
}
void System::PrintMainMenu()
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