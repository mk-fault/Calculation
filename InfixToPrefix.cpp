#include "Function.h"
void InfixToPrefix(char c[],int lens,char outstack[],int& outtop)
{
	char stack[MaxSize];
	int top = -1;
	int i = lens -1;
	while (i >= 0)
	{
		if ('0' <= c[i] && c[i] <= '9')
		{
			outstack[++outtop] = c[i];
			--i;
		}
		else if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/')
		{
			if (top == -1 || GetPriority(c[i]) >= GetPriority(stack[top]) || stack[top] == ')')
			{
				stack[++top] = c[i];
				--i;
			}
			else
				outstack[++outtop] = stack[top--];
		}
		else if (c[i] == ')')
		{
			stack[++top] = ')';
			--i;
		}
		else if (c[i] == '(')
		{
			while (stack[top] != ')')
			{
				outstack[++outtop] = stack[top--];
			}
			--top;
			--i;
		}
	}
	while (top != -1)
	{
		outstack[++outtop] = stack[top--];
	}
}