/***
Write matrix multiplication application in C using SSE library.

1. Use 4x4 matrix in your program 

2. Use pthreads library and SSE C library.
***/
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

//https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html
//https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm

pthread_mutex_t readerlock = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t writerlock = PTHREAD_MUTEX_INITIALIZER;

//bool done = false;

void* thread_function(void* arg)
{
srand(time(0));
printf("worker pthread:%lu\n", pthread_self());
int *count = (int*)arg;
for (int i = 0; i<1000000;i++) {
// CRITICAL SECTION is PART of code Which modifies/updates/read shared/global data
// context switch

pthread_mutex_lock( &writerlock);//50 threads 1 thread took the lock and 49 are waiting
int num = rand() % 201; // next time, after that 1 thread is also in the queue
if (num == 129)
(*count)++;
pthread_mutex_unlock( &readerlock );
}
//done = true;
}

 

int main(int avgc, char** avgs)
{
int count = 0;
pthread_t tx;
pthread_create(&tx, NULL, thread_function, &count);
printf("main pthread:%lu\n", pthread_self());
for (int i = 0; i<10000000;i++)
{
pthread_mutex_lock( &readerlock);
printf("count: %d\n", count);
pthread_mutex_unlock( &writerlock);

}

//while(!done); //busy waiting
pthread_join(tx, NULL);

return 0;
}