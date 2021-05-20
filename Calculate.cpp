#include"Function.h"
float Calculate(float v1, char op, float v2)
{
	switch (op)
	{
		case '+':
			return v1 + v2;
		case '-':
			return v1 - v2;
		case '*':
			return v1 * v2;
		case'/':
			if (v2 != 0)
				return v1 / v2;
			else
				return 999999;
	default:
		break;
	}
}