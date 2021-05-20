#include"Function.h"
float CalSufix(char WaitCal[])
{
	int i = 0;
	float stack[MaxSize];
	int top = -1;
	float val1, val2;
	while (WaitCal[i] != '\0')
	{
		if (WaitCal[i] >= '0' && WaitCal[i] <= '9')
		{
			stack[++top] = WaitCal[i] - '0';
			++i;
		}
		else
		{
			val2 = stack[top--];
			val1 = stack[top--];
			stack[++top] = Calculate(val1, WaitCal[i], val2);
			++i;
		}
	}
	return stack[top--];
}