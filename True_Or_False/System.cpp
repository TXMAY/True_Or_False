#include <iostream>
#include <Windows.h>
#include "System.h"

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
void System::GameOver()
{
	system("cls");
	std::cout << "Game over!\nScore : " << score << std::endl;
}