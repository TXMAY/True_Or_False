#include "System.h"
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
void System::PrintRandomValue()
{
	std::cout << val1 << " " << str_oper << " " << val2 << std::endl;
}
void System::GetKey()
{
	timer = 3.0;
	while (timer >= 0)
	{
		if (GetAsyncKeyState(VK_LEFT))
		{
			key = true;
			break;
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			key = false;
			break;
		}
		Sleep(100);
		timer -= 0.1;
	}
};
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
void System::GameOver()
{
	system("cls");
	std::cout << "Game over!\nScore : " << score << std::endl;
}
void System::PlayingGame()
{
	life = 3;
	score = 0;
	while (life > 0)
	{
		SetRandomValue();
		SetOperator();
		PrintRandomValue();
		GetKey();
		PrintAnswer();
		Sleep(1000);
		system("cls");
	}
	GameOver();
}