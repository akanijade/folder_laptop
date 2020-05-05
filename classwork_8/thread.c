/**
gcc thread.c -othread -lpthread
When thread function is writing on random_variable,  
main function should not read it until thread function says or signals main function to go and read. 
Also while main function is reading, thread function should not generate next number. 
**/


#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

//https://www.cs.cmu.edu/afs/cs/academic/class/15492-f07/www/pthreads.html
//https://www.tutorialspoint.com/c_standard_library/c_function_rand.htm




int count = 0; //how many times it matches with the number 1
int i = 0;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

//bool msg = false;
void* thread_function(void* arg) 
{
    
    pthread_detach(pthread_self());
    int p = (int)arg; 
    //for (int i = 0; i<1000000;i++) {
        pthread_mutex_lock( &mutex1 );
        //create random number 0 to 200
        
        //printf("%d \n", random_number);
        if (p == 1) //if matches with 1
            count++;
        //message main thread and that read the number and see if it is 129. 
        //msg = true;
        pthread_mutex_unlock( &mutex1 );
        pthread_exit(NULL); //terminate thread
    //}
}

int main(int avgc, char** avgs)
{
    
    time_t t;
    srand((unsigned) time(&t));
    while (i < 100 ) // check if 1 appeared, if it did add 1 to count
    {
        int random_number = rand() % 5;
        int result;
        pthread_t thread1, thread2;
        result = pthread_create(&thread1, NULL, thread_function, (void*)random_number);
        if (result)
        {
            printf("Error");
            break;
        }
        i++;
        //count++;
        //msg = false;
        //pthread_mutex_unlock( &mutex1 );
    }
    //stop - when I get a signal from thread_function, then I should read and see if rn is 129
    //while(true)
    //    check random_number
    //    unlock
    //count++
    //msg = false
    //pthread_join(thread1, NULL);
    printf("how many times number matches with "1": %d\n",count);
    //i = 0;
    //pthread_join(thread2, NULL);
    return 0;
}