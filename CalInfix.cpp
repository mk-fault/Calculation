#include "Function.h"
float CalInfix(char c[])
{
	char symstack[MaxSize];
	float digstack[MaxSize];
	int symtop = -1;
	int digtop = -1;
	int i = 0;
	float val1, val2;
	while (c[i] != '\0')
	{
		if (c[i] >= '0' && c[i] <= '9')
		{
			digstack[++digtop] = c[i++] - '0';
		}
		else if (c[i] == '+' || c[i] == '-' || c[i] == '*' || c[i] == '/')
		{
			if (symtop == -1 || GetPriority(c[i]) > GetPriority(symstack[symtop]) || symstack[symtop] == '(')
			{
				symstack[++symtop] = c[i++];
			}
			else
			{
				val2 = digstack[digtop--];
				val1 = digstack[digtop--];
				digstack[++digtop] = Calculate(val1, symstack[symtop--], val2);
				
			}
		}
		else if (c[i] == '(')
			symstack[++symtop] = c[i++];
		else if (c[i] == ')')
		{
			while (symstack[symtop] != '(')
			{
				val2 = digstack[digtop--];
				val1 = digstack[digtop--];
				digstack[++digtop] = Calculate(val1, symstack[symtop--], val2);
			}
			symstack[symtop--];
			++i;
		}
	}
	while (symtop != -1)
	{
		val2 = digstack[digtop--];
		val1 = digstack[digtop--];
		digstack[++digtop] = Calculate(val1, symstack[symtop--], val2);
	}
	return digstack[digtop];
}