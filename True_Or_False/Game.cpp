#include "Game.h"
#include <iostream>

void Game::SetRandomValue()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> ran_val(0, 9);
	std::uniform_int_distribution<int> ran_oper(1, 6);
	val1 = ran_val(gen);
	val2 = ran_val(gen);
	num_oper = ran_oper(gen);
}
void Game::SetOperator()
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
void Game::PrintRandomValue()
{
	std::cout << val1 << " " << str_oper << " " << val2 <<std::endl;
}
void Game::GetKey()
{
	timer = 3.0 - minus_time;
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
void Game::PrintAnswer()
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
		if (score % 5 == 0 && score <= 25)
		{
			switch (difficulty)
			{
			case 1:
				minus_time += 0.1;
				break;
			case 2:
				minus_time += 0.2;
				break;
			case 3:
				minus_time += 0.3;
				break;
			default:
				break;
			}
		}
	}
	else
	{
		std::cout << "오답" << std::endl;
		--life;
	}
}
void Game::GameOver()
{
	system("cls");
	std::cout << "Game over!\nScore : " << score << std::endl;
}
void Game::SetDifficulty()
{
	difficulty = 2;
	std::cout << ("난이도 선택") << std::endl;
	while (true)
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			--difficulty;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			++difficulty;
		}
		if (difficulty >= DIFFICULTY_MAX)
		{
			difficulty = 1;
		}
		if (difficulty <= DIFFICULTY_MIN)
		{
			difficulty = 3;
		}
		switch (difficulty)
		{
		case 1:
			pos = { 5,4 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << ("◀ easy ▶") << std::endl;
			break;
		case 2:
			pos = { 2,4 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << ("◀ normal ▶") << std::endl;
			break;
		case 3:
			pos = { 5,4 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << ("◀ hard ▶") << std::endl;
			break;
		default:
			break;
		}
		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			break;
		}
	}
	system("cls");
}
void Game::PlayingGame()
{
	life = 3;
	score = 0;
	minus_time = 0;
	SetDifficulty();
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