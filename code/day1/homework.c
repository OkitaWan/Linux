#include "my.h"
#define NUM 4
struct info{
	int no;
	int num;
};
struct rval{
	int sum;
	pthread_t tid;
};

void fun(void *arg)
{
	struct info *pt;
	pt = (struct info *)arg;
	int i,sum=0;
	printf("worker thread %d: tid=%lx\n",pt->no,pthread_self());
	for(i=0;i<(pt->num);i++)
	{
		sum+=i;
	}
	printf("worker num %d: sum=%d\n",pt->num,sum);
}

void * fun1(void *arg)
{
	struct info *pt;
	struct rval *r;
	pt = (struct info *)arg;
	int i,sum=0;
	printf("worker thread %d: tid=%lx\n",pt->no,pthread_self());
	for(i=0;i<(pt->num);i++)
	{
		sum+=i;
	}
	printf("worker num %d: sum=%d\n",pt->num,sum);
	r=(struct rval *)malloc(sizeof(struct rval));
	r->sum=sum;
	r->tid=pthread_self();
	printf("r sum=%d,tid=%lx\n",r->sum,r->tid);
	pthread_exit((void*)r);
	return NULL;
}
int main()
{
	pthread_t tid[NUM];
	int ret;
	int i;
	struct info a[NUM];
	struct rval *r;
	void *rval;
	struct info *b;
	for(i=0;i<NUM;i++)
	{
		a[i].no=i;
		a[i].num=(i+1)*100;
		pthread_create(&tid[i],NULL,(void *(*))fun,(void *)&a[i]);
	}
	for(i=0;i<NUM;i++)
	{
		pthread_join(tid[i],NULL);
	}
	pthread_create(&tid[0],NULL,fun1,(void *)&a[0]);
	pthread_join(tid[0],&rval);
	r=(struct rval *)rval;
	printf("struct rval sum=%d,tid=%lx\n",r->sum,r->tid);
	printf("All finished\n");
	return 0;
}

