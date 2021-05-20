#include"Function.h"
int GetPriority(char c)
{
	if (c == '*' || c == '/')
		return 1;
	else
		return 0;
}