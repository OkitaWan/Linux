#include "my.h"
void sigroutine(int signo)
{
	switch(signo)
	{
		case 1:
			printf("recive SIGHUP\n");
			break;
		case 2:
			printf("recive SIGINT\n");
			break;
		case 3:
			printf("recive SIGQUIT\n");
			break;
	}
}
int main()
{
	for(int i=1; i<=3; i++)
	{
		signal(i, sigroutine);
	}
	//signal(1, sigroutine);
	//signal(2, sigroutine);
	//signal(3, sigroutine);
	printf("test process.\n pid=%d\n", getpid());
	while(1);
	return 0;
}
