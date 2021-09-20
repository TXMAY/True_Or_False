#ifndef __SYSTEM_HPP__
#define __SYSTEM_HPP__
#include <string>
#include <random>

class System
{
private:
	int val1;
	int val2;
	int num_oper;
	int life;
	int score;
private:
	bool answer = NULL;
	bool key;
private:
	double timer;
private:
	std::string str_oper;
public:
	void SetRandomValue();
	void SetOperator();
	void PrintRandomValue();
	void PrintAnswer();
	void GetKey();
	void GameOver();
	void Start();
};
#endif
