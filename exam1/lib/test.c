#include "lib.c"
int main()
{	
	int a[UNUMBER];
	urand(a, UNUMBER);
	printf("max=%d", max(a, UNUMBER));
	printf("sum=%d", sum(a, UNUMBER));
	return 0;
}
