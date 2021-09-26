#include "Game.hpp"
#include "Common.hpp"
#include <iostream>

void Game::SetDifficulty()
{
	difficulty = NORMAL;
	pos = { 35,5 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << ("���̵� ����") << std::endl;
	MadeByTXMAY();
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
			difficulty = EASY;
		}
		if (difficulty <= DIFFICULTY_MIN)
		{
			difficulty = HARD;
		}
		switch (difficulty)
		{
		case EASY:
			pos = { 36,10 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << (" �� easy �� ") << std::endl;
			break;
		case NORMAL:
			pos = { 36,10 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << ("�� normal ��") << std::endl;
			break;
		case HARD:
			pos = { 36,10 };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
			std::cout << (" �� hard �� ") << std::endl;
			break;
		default:
			break;
		}
		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			play_game = true;
			system("cls");
			break;
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x0001)
		{
			play_game = false;
			system("cls");
			break;
		}
	}
	system("cls");
}
void Game::SetRandomValue()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> ran_val;
	std::uniform_int_distribution<int> ran_oper;
	switch (difficulty)
	{
	case EASY:
		ran_val.param(std::uniform_int_distribution<int>::param_type(0, 9));
		ran_oper.param(std::uniform_int_distribution<int>::param_type(1, 2));
		break;
	case NORMAL:
		ran_val.param(std::uniform_int_distribution<int>::param_type(0, 49));
		ran_oper.param(std::uniform_int_distribution<int>::param_type(1, 4));
		break;
	case HARD:
		ran_val.param(std::uniform_int_distribution<int>::param_type(0, 99));
		ran_oper.param(std::uniform_int_distribution<int>::param_type(1, 6));
		break;
	default:
		break;
	}
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
	pos = { 36,5 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << val1;
	pos = { 39,5 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << str_oper;
	pos = { 42,5 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << val2 << std::endl;
}
void Game::GetKey()
{
	timer = 3.0 - minus_time;
	while (timer >= 0)
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			key = true;
			break;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
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
	pos = { 38,10 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	if (timer <= 0)
	{
		pos = { 36,10 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		std::cout << "�ð� �ʰ�" << std::endl;
		--life;
	}
	else if (answer == key)
	{
		std::cout << "����" << std::endl;
		++score;
		if (score % 5 == 0 && score <= 25)
		{
			switch (difficulty)
			{
			case EASY:
				minus_time += 0.1;
				break;
			case NORMAL:
				minus_time += 0.2;
				break;
			case HARD:
				minus_time += 0.3;
				break;
			default:
				break;
			}
		}
	}
	else
	{
		std::cout << "����" << std::endl;
		--life;
	}
}
void Game::GameOver()
{
	system("cls");
	pos = { 36,5 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << "Game over!" << std::endl;
	pos = { 36,7 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << "Score : " << score << std::endl;
	pos = { 22,9 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << "���� �޴��� ���ư����� enter�� ��������." << std::endl;
	MadeByTXMAY();
	while (true)
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			system("cls");
			break;
		}
	}
}
void Game::PlayingGame()
{
	life = 3;
	score = 0;
	minus_time = 0;
	SetDifficulty();
	while (life > 0 && play_game == true)
	{
		MadeByTXMAY();
		PrintInfo();
		SetRandomValue();
		SetOperator();
		PrintRandomValue();
		GetKey();
		PrintAnswer();
		Sleep(1000);
		system("cls");
	}
	if (play_game == true)
		GameOver();
}
void Game::PrintInfo()
{
	pos = { 0,0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << "Score : " << score << ("\nLife : ") << life << std::endl;
}
void Game::MadeByTXMAY()
{
	pos = { 0,15 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	std::cout << ("Made by TXMAY") << std::endl;
}