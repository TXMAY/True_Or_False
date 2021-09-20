#include "System.h"
#include <Windows.h>

void System::Start()
{
	life = 3;
	score = 0;
	while (true)
	{
		SetRandomValue();
		SetOperator();
		PrintRandomValue();
		GetKey();
		PrintAnswer();
		if (life <= 0)
		{
			Sleep(1000);
			break;
		}
		Sleep(1000);
		system("cls");
	}
	GameOver();
}