#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <signal.h>
#include <limits.h>
#include <assert.h>
#include <errno.h>
#include <sys/types.h>
#include <time.h>

#define LOOP 10000000
#define NUM 4
#define NT 100
#define WRITE_FIRST
#define check_error(return_val, msg){			\
			if (return_val != 0){				\
				fprintf(stderr, "%s: %s\n", msg, strerror(return_val));\
			}\
		}
