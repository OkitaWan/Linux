#include "/home/rlk/week5/exam1/lib/lib.h"
int main()
{	
	int a[UNUMBER];
	urand(a, UNUMBER);
	printf("max=%d  \n", max(a, UNUMBER));
	printf("sum=%d  \n", sum(a, UNUMBER));
	return 0;
}
