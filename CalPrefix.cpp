#include"Function.h"
float Calprefix(char WaitCal[],int lens)
{
	int i = lens - 1;
	float stack[MaxSize];
	int top = -1;
	float val1, val2;
	while (i >= 0)
	{
		if (WaitCal[i] >= '0' && WaitCal[i] <= '9')
		{
			stack[++top] = WaitCal[i] - '0';
		}
		else
		{
			val1 = stack[top--];
			val2 = stack[top--];
			stack[++top] = Calculate(val1, WaitCal[i], val2);
		}
		--i;
	}
	return stack[top--];
}