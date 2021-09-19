#include <iostream>
#include <random>
#include <string>
#include <conio.h>
#include "windows.h"
#include <time.h>

int val1;
int val2;
int num_oper;
std::string str_oper;
bool answer = NULL;
bool key;
int life;
int score;

void SetRandomValue()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> ran_val(0, 9);
	std::uniform_int_distribution<int> ran_oper(1, 6);
	val1 = ran_val(gen);
	val2 = ran_val(gen);
	num_oper = ran_oper(gen);
}
void SetOperator()
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
void PrintRandomValue()
{
	std::cout << val1 << " " << str_oper << " " << val2 << std::endl;
}

void PrintAnswer()
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
	if (answer == key)
	{
		std::cout << "����" << std::endl;
		++score;
	}
	else
	{
		std::cout << "����" << std::endl;
		--life;
	}
}


void GetKey()
{
	while (TRUE)
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
	}
}
void GameOver()
{
	system("cls");
	std::cout << "Game over!\nScore : " << score << std::endl;
}

int main()
{
	life = 3;
	while (true)
	{
		SetRandomValue();
		SetOperator();
		PrintRandomValue();
		GetKey();
		PrintAnswer();
		if (life <= 0)
			break;
		Sleep(1000);
		system("cls");
	}
	GameOver();
}

