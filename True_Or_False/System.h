#ifndef __SYSTEM_HPP__
#define __SYSTEM_HPP__
#include <string>
#include <random>
#include <Windows.h>

class System
{
private:
	int val1;
	int val2;
	int num_oper;
	int life;
	int score;
	int menu;
private:
	bool answer = NULL;
	bool key;
private:
	double timer;
private:
	std::string str_oper;
private:
	COORD pos;
	COORD menu_pos;
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
private:

public:
	void SetRandomValue();
	void SetOperator();
	void PrintRandomValue();
	void PrintAnswer();
	void GetKey();
	void GameOver();
	void Start();
	void Setscreen();
	void PrintMainMenu();
	void SetMainMenu();
};
#endif
