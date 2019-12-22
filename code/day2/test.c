#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>
int t = 0;
sem_t empty,full;
pthread_mutex_t mutex;
char ran[5] = {};
void*  producer(void* arg){
    int* time1=(int*) arg;
    while(1){
        
		if(t<5){
			srand((unsigned)time(NULL));
			sem_wait(&empty);
        	pthread_mutex_lock(&mutex);
			ran[t] = 1 + rand()%100;
			printf("producer add 1 to %d, ran[%d] = %d\n", t, t, ran[t]);
			printf("ran[5]={");
			for(int i = 0; i<5; i++)
			{
				printf("%d, ", ran[i]);
			}
			printf("}\n");
			t++;
			pthread_mutex_unlock(&mutex);
        	sem_post(&full);
			sleep(*time1);		
		}
		else {
			t=0;
			ran[5] = {0,0,0,0,0};
			printf("producer re 5 to %d\n", t);	
			pthread_mutex_unlock(&mutex);	
		}
        
        
    }
}
  
void* customer(void* arg){
  
    while(1){
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        //delete
        t--;
        printf("customer delete 1 to %d\n", t);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        sleep(4);
    }
}
  
int main(){
    pthread_t pthread_producer,pthread_producer_2;
    pthread_t pthread_customer;
    pthread_mutex_init(&mutex,NULL);
    sem_init(&full,0,0);
    sem_init(&empty,0,10);
    int a = 2;
    int b = 3;
    pthread_create(&pthread_producer,NULL,producer,&a);
    pthread_create(&pthread_producer_2,NULL,producer,&b);
    pthread_create(&pthread_customer,NULL,customer,NULL);
    pthread_join(pthread_customer,NULL);
    pthread_join(pthread_producer,NULL);
    pthread_join(pthread_producer_2,NULL);
    return 0;
}
