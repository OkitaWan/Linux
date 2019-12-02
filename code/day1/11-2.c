#include "my.h"
int count = 0;
int main()
{
	pid_t p1, p2, p3;
	p1 = fork();
	int s1, s2,  s3, r1, r2, r3;
	if(p1 < 0)
	{
		perror("fork1 Failed.\n")
	}
}
