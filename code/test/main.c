#include "lib.h"
#include <stdlib.h>
#include <dlfcn.h>
#include <stdio.h>
int main()
{	
	int a[UNUMBER];
	void *handle;
	void (*f1)(), (*f2)();
	int  (*f3)(), (*f4)();
	char* error;

	handle = dlopen("/home/rlk/linuxprogram/week6/code/dynamiclib/libdynamic.so", RTLD_LAZY);
	if(!handle)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);	
	}

	f1=dlsym(handle, "urand");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);	
	}

	f2=dlsym(handle, "show");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);	
	}

	f3=dlsym(handle, "max");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);	
	}

	f4=dlsym(handle, "sum");
	if((error=dlerror())!=NULL)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);	
	}

	f1(a, UNUMBER);
	f2(a, UNUMBER);
	printf("max=%d  \n", f3(a, UNUMBER));
	printf("sum=%d  \n", f4(a, UNUMBER));
	if(dlclose(handle)<0)
	{
		fprintf(stderr, "%s\n", dlerror());
		exit(1);	
	}
	return 0;
}
