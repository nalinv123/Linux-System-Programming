#include <stdio.h>

int add(int no1, int no2)
{
	int iAns = no1 + no2;
	return iAns;
}

int main(int argc, char *argv[])
{
	int  x = 0, y = 0, iRet = 0;

	printf("Enter two number : ");
	scanf("%d%d",&x,&y);
	
	iRet = add(x, y);
	printf("Addition : %d\n", iRet);

	return 0;
}
