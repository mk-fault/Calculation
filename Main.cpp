#include"Function.h"
int main() 
{
	char c[] = { '1','+','(','2','*','(','8','-','3',')','+','5',')','/','4','\0' };//1+（2*(8-3)+5）/4
	char outstack[MaxSize];
	char switchstack[MaxSize];
	int outtop = -1;
	int switchtop = -1;
	InfixToSufix(c,outstack,outtop);
	std::cout << outstack<<std::endl;            //  1283-*5+4/+
	std::cout << CalSufix(outstack)<<std::endl;

	outtop = -1;
	InfixToPrefix(c,15,outstack,outtop);
	while (outtop != -1)                                   //中缀转前缀保存为栈式，数据相反
		switchstack[++switchtop] = outstack[outtop--];     //用switchstack实现数据转正
	switchstack[++switchtop] = '\0';                       //
	std::cout << switchstack <<std::endl;        //  +1/+*2-8354
	std::cout << Calprefix(switchstack, 11) << std::endl;

	std::cout << CalInfix(c);

}

