#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

	// function prototype
	void* thread_function(void*);

	// global attributes
	int matchCount = 0;
	int i = 0;
	static int CONSTANT = 7;
	static int loopCount = 10;
	pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

	// driver code
	int main(int avgc, char** avgs){
		
		srand(time(0));
		do{

			int x = rand() % 10;

			 // return value
			 int rc;

			 // thread id
			 pthread_t tid;
			 
			 // thread creation
			 // thread id, default attributes, function call, arbitrary #
			 rc = pthread_create(&tid, NULL, thread_function, (void*)x);
			 
			 // if thread creation fails exit
			 if(rc){

	        	printf("\n ERROR: return code from pthread_create is %d \n", rc);
	        	exit(1);
	   		 }

	   		 i++;
		 }while(i < loopCount);


		 // debug/verify output
		 printf("matchCount: %d\n", matchCount);
		 i = 0;

		 return 0;
	}

	void* thread_function(void* data){
	 
	 	 //data received by thread
     	 int my_data = (int)data;     	 
	 
     	 pthread_detach(pthread_self());

	 	 // insert mutex here to lock/unlock global access to matchCount (*my_data)
	 	 pthread_mutex_lock(&mutex1);
	     
	     if(my_data == CONSTANT){
		         matchCount++;
		     }
	  	 
	  	 pthread_mutex_unlock(&mutex1);
	  	 // thread termination, free resource
		 pthread_exit(NULL);
	}