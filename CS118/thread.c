#include <stdio.h>
#include <pthread.h>

int ex = 0;
void* thread_function(void* arg)
{
	  int* p = (int*)arg;
	    for (int i = 0; i<100000000;i++) {
			    *p = *p + 1;
				  }
}

int main(int avgc, char** avgs)
{

	 pthread_t thread1, thread2;
	  pthread_create(&thread1, NULL, thread_function, &ex);
	   //pthread_create(&thread2, NULL, thread_function, &ex);
	   
	    for (int k=0;k<100;k++)
	     {
	        printf("From main thread\n");
	         }
	         //printf("ex: %d\n",ex);
	   
	           pthread_join(thread1, NULL);
	            printf("ex: %d\n",ex);
	             //pthread_join(thread2, NULL);
	              return 0;
	              }
