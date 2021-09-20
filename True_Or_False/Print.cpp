#include "System.h"
#include <iostream>

void System::PrintRandomValue()
{
	std::cout << val1 << " " << str_oper << " " << val2 << std::endl;
}
void System::PrintAnswer()
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
		std::cout << "�ð� �ʰ�" << std::endl;
		--life;
	}
	else if (answer == key)
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