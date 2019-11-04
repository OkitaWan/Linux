#include "my.h"
int main()
{
	int ret;
	printf("caller1:pid=%d, ppid=%d\n", getpid(), getppid());
	ret = system("/home/rlk/linuxprogram/week9/code/day1/test1");
	printf("after calling!\n");
	sleep(100);
	return 0;
}
