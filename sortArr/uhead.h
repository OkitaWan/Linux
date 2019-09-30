#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/time.h>
#include<unistd.h>
#define UNUMBER 100

struct arg {
	int sum;
	float ave;
};

int usum(int *, int );
void urand(int *, int);
void writedata(int *a, int n);
void show(int *, int);
struct arg operater(int *, int);
void bsort(void *, size_t , size_t , int (*cmp)(const void *, const void *));
int compare1(const void *, const void *);
int compare2(const void *, const void *);
void swap(char *, char *, size_t );
void syssort(void *, size_t , size_t , int (*cmp)(const void *, const void *), void (*sort)(void *, size_t, size_t, int (*cmp)(const void *, const void *)));
