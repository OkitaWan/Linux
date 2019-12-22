#include "my.h"
#define NUM_THREADS 4
#define TCOUNT 10
#define COUNT_LITMIT 5
//int use[5];
//int count = 0;
int front=0;
int rear=0;
int thread_ids[4]={0,1,2,3};
int buffer[5];
pthread_mutex_t count_mutex;
pthread_cond_t count_threshold_cv_full;
pthread_cond_t count_threshold_cv_empty;
void *watch_count(void *idp)
{
	int *my_id = (int *)idp;
	while(1){
		pthread_mutex_lock(&count_mutex);
		//if(count == 0){
		if(front == rear){
			pthread_mutex_unlock(&count_mutex);
			printf("watch_count(): thread %d wait Condition signal.\n",*my_id);
			pthread_cond_wait(&count_threshold_cv_full,&count_mutex);
			printf("watch_count(): thread %d Condition signal received.\n",*my_id);
		}
		//pthread_mutex_unlock(&count_mutex);
		else{
			//pthread_mutex_lock(&count_mutex);
			printf("watch_count(): thread %d front=%d rear=%d\n",*my_id,front,rear);
			printf("watch_count(): thread %d buffer[%d]=%d\n",*my_id,front,buffer[front]);
			front=(front+1)%COUNT_LITMIT;
			printf("front=%d,rear=%d\n",front,rear);
			pthread_cond_signal(&count_threshold_cv_empty);
			pthread_mutex_unlock(&count_mutex);
		}
	}
	//pthread_mutex_unlock(&count_mutex);
	pthread_exit(NULL);
}
void *inc_count(void * idp)
{
	int *my_id=(int *)idp;
	int j,i;
	double result = 0.0;
	while(1){
		pthread_mutex_lock(&count_mutex);
		//if(count ==  COUNT_LITMIT)
		if((rear+1)%COUNT_LITMIT == front)
		{
			pthread_mutex_unlock(&count_mutex);
			printf("inc_count(): thread %d  wait Condition signal.\n",*my_id);
			pthread_cond_wait(&count_threshold_cv_empty,&count_mutex);
			printf("inc_count() : thread %d Condition signal received\n",*my_id);
		}
		//pthread_mutex_unlock(&count_mutex);
		else
		{
			//pthread_mutex_lock(&count_mutex);
			buffer[rear]=rand()%10000;
			//rear=(rear+1)%COUNT_LITMIT;
			pthread_cond_signal(&count_threshold_cv_full);
			printf("inc_count(): thread %d,front=%d,rear=%d\n",*my_id,front,rear);
			printf("inc_count(): thread %d buffer[%d]=%d\n",*my_id,rear,buffer[rear]);
			rear=(rear+1)%COUNT_LITMIT;
			printf("front=%d,rear=%d\n",front,rear);
			pthread_mutex_unlock(&count_mutex);	
		
		}
	}
	pthread_exit(NULL);
}
int main()
{
	int r,rc;
	pthread_t tid[3];
	pthread_attr_t attr;
	pthread_mutex_init(&count_mutex,NULL);
	pthread_cond_init(&count_threshold_cv_full,NULL);
	pthread_cond_init(&count_threshold_cv_empty,NULL);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
	pthread_create(&tid[0],&attr,inc_count,(void*)&thread_ids[0]);
	pthread_create(&tid[1],&attr,watch_count,(void*)&thread_ids[1]);
	pthread_create(&tid[2],&attr,watch_count,(void*)&thread_ids[2]);
	pthread_create(&tid[3],&attr,watch_count,(void*)&thread_ids[3]);
	for(int i=0;i<NUM_THREADS;i++)
	{
		pthread_join(tid[i],NULL);
	}
	printf("Main(): waited on %d threads.Done\n",NUM_THREADS);
	pthread_attr_destroy(&attr);
	pthread_mutex_destroy(&count_mutex);
	pthread_cond_destroy(&count_threshold_cv_empty);
	pthread_cond_destroy(&count_threshold_cv_full);
	pthread_exit(NULL);
}
