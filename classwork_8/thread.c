/**
gcc thread.c -othread -lpthread
When thread function is writing on random_variable,  
main function should not read it until thread  function says or signals main function to go and read. 
Also while main function is reading, thread function should not generate next number. 
**/

 

 

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

//https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html
//https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm

int random_number = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

bool msg = false;
void* thread_function(void* arg)
{
int* p = (int*)arg;
for (int i = 0; i<1000000;i++) {
pthread_mutex_lock( &mutex1 );
//create randowm number 0 to 200
//message main thread and that read the number and see if it is 129.
//msg = true;
//pthread_mutex_unlock( &mutex1 );
}
}

int main(int avgc, char** avgs)
{

pthread_t thread1, thread2;
pthread_create(&thread1, NULL, thread_function, &ex);

while (true) // check if 129 appeared, if it did add 1 to count
//stop - when I get a signal from thread_function, then I should read and see if rn is 129
check random_number
unlock
count++
msg =false
pthread_join(thread1, NULL);
printf("ex: %d\n",ex);
//pthread_join(thread2, NULL);
return 0;
}