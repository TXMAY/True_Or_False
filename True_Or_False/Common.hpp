#ifndef __COMMON_HPP__
#define __COMMON_HPP__
#include <Windows.h>
#include <iostream>

static int ran_val_max;
static int ran_oper_max;

static bool play_game;

static COORD pos;

const static int EASY = 1;
const static int NORMAL = 2;
const static int HARD = 3;

const static int DIFFICULTY_MAX = 4;
const static int DIFFICULTY_MIN = 0;

static void SetPosition(short x, short y)
{
	pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
static void MadeByTXMAY()
{
	SetPosition(0, 15);
	std::cout << (" Made by TXMAY") << std::endl;
}
#endif