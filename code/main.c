#include "uhead.h"
int main()
{
	int a[UNUMBER];
	struct arg t;
	urand(a, UNUMBER);
	show(a, UNUMBER);
	t = operater(a, UNUMBER);
	printf("\n********\n sum=%d, ave=%f\n", t.sum, t.ave);
	syssort(a, UNUMBER, 4, compare1, bsort);
	syssort(a, UNUMBER, 4, compare1, qsort);
	writedata(a, UNUMBER);
	return 0;
}
