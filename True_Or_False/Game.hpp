#ifndef __GAME_HPP__
#define __GAME_HPP__
#include <string>
#include <random>
#include <Windows.h>

class Game
{
private:
	int val1;
	int val2;
	int num_oper;
	int life;
	int score;
	int difficulty;
private:
	bool answer = NULL;
	bool key;
private:
	double timer;
	double minus_time;
private:
	COORD pos;
private:
	std::string str_oper;
public:
	void SetRandomValue();
	void SetOperator();
	void PrintRandomValue();
	void PrintAnswer();
	void GetKey();
	void GameOver();
	void PlayingGame();
	void SetDifficulty();
	void MadeByTXMAY();
	void PrintInfo();
};
#endif
