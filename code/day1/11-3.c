#include "my.h"
int main()
{
	pid_t r;
	
	if(pipe(pipefd) < 0)
	{
		printf("pid = %d, ppid = %d", getpid(), getppid());
		
	}
	r = fork();
	if(r<0)
	{
		
	}
	else if(r==0)
	{
		
	}
	else
	{
		
		return 0;
	}
}
