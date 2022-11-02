#include<stdio.h>

int change(int &i)
{
	i = 100;
}

int main()
{
	int a = 60;
	printf("%d\n",a);
	change(a);
	printf("%d\n",a);
	return 0;
}
