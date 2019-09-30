#include "uhead.h"



struct arg operater(int *a, int n)
{
	struct arg my_number;
	my_number.sum = 0;
	my_number.ave = 0.0;
	int i;
	for(i=0; i<n; i++)
		my_number.sum = my_number.sum + a[i];
	my_number.ave = ((float)my_number.sum)/n;
	return my_number;
}
