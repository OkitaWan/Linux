#include<stdlib.h>
#include<stdio.h>
int main()
{
	int i;
	printf("\nbefore calling!\n");
	sleep(10);
	i = system("./test2");
	printf("\nafter calling!\n");
	printf("return value=%d\n", i);
	return 0;
}
