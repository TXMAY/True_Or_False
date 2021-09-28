#include "Game.hpp"
#include "Common.hpp"
#include <iostream>

void Game::SetDifficulty()
{
	difficulty = NORMAL;
	SetPosition(35, 5);
	std::cout << ("난이도 선택") << std::endl;
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
			SetPosition(36, 10);
			std::cout << (" ◀ easy ▶ ") << std::endl;
			break;
		case NORMAL:
			SetPosition(36, 10);
			std::cout << ("◀ normal ▶") << std::endl;
			break;
		case HARD:
			SetPosition(36, 10);
			std::cout << (" ◀ hard ▶ ") << std::endl;
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
	SetPosition(36, 5);
	std::cout << val1;
	SetPosition(39, 5);
	std::cout << str_oper;
	SetPosition(42, 5);
	std::cout << val2 << std::endl;
}
void Game::GetKey()
{
	timer = 3.0 - minus_time;
	while (timer >= 0)
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			key = true;
			break;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
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
	SetPosition(38, 10);
	if (timer <= 0)
	{
		SetPosition(36, 10);
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
		std::cout << "오답" << std::endl;
		--life;
	}
}
void Game::GameOver()
{
	system("cls");
	SetPosition(36, 5);
	std::cout << "Game over!" << std::endl;
	SetPosition(36, 7);
	std::cout << "Score : " << score << std::endl;
	SetPosition(22, 9);
	std::cout << "메인 메뉴로 돌아가려면 enter를 누르세요." << std::endl;
	MadeByTXMAY();
	while (true)
	{
		if (GetAsyncKeyState(VK_RETURN) & 0x8000)
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
	SetPosition(0, 0);
	std::cout << "Score : " << score << ("\nLife : ") << life << std::endl;
}