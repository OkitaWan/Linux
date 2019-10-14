#include "lib.h"
void show(int *a, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("a[%d] = %d\n", i, a[i]);
	
}

void urand(int *a, int n) // 生成随机数
{
	int i;
	srand((int)time(0));
	for(i=0; i<n; i++)
	{
		a[i] = 1+(int)(100.0*rand()/(RAND_MAX+1.0));
	}
}
