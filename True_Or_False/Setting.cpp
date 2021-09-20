#include "System.h"

void System::SetRandomValue()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> ran_val(0, 9);
	std::uniform_int_distribution<int> ran_oper(1, 6);
	val1 = ran_val(gen);
	val2 = ran_val(gen);
	num_oper = ran_oper(gen);
}
void System::SetOperator()
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