#include "uhead.h"

int usum(int *a, int n)
{
	int s=0, i;
	for(i=0; i<n; i++)
		s=s+a[i];
	return s;
}

void urand(int *a, int n) // 生成随机数并写入文件
{
	FILE *fp;
	int i;
	int h;
	srand((int)time(0));
	for(i=0; i<n; i++)
	{
		a[i] = 1+(int)(100.0*rand()/(RAND_MAX+1.0));
	}
	fp = fopen("rand.txt", "w"); // 打开文件
	for(i=0; i<n; i++)
	{
		fprintf(fp, "%d\n", a[i]);
	}
	fclose(fp);
}

void writedata(int *a, int n)	// 将排序好的数据放入新的文件中
{
	FILE *fp;
	int i, b[n];
	fp = fopen("sort.txt", "w");
	for(i=0; i<n; i++)
	{
		b[i] = a[i];
	}
	for(i=0; i<n; i++)
	{
		fprintf(fp, "%d\n", b[i]);
	}
	fclose(fp);
	printf("排序后数组已经写入文件中\n");
}

void show(int *a, int n)
{
	int i;
	for(i=0; i<n; i++)
		printf("a[%d] = %d\n", i, a[i]);
	
}
