#include "my.h"

static void fun1(void)
{
	printf("invoked callbackfun!\n");
}

int main()
{
	atexit(fun1);
	FILE *fp;
	char buf[] = "buffer data!";
	if((fp = fopen("test.txt", "w+"))==NULL)
	{
		perror("create file failed!");
		exit(-1);
	}
	if(fputs(buf, fp)==EOF)
	{
		perror("fputs file failed!");
		exit(-1);
	}
	printf("hello     ");
	exit(0);
}
