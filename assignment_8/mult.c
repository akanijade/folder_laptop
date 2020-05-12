// C Program to multiply two matrix using pthreads without 
// use of global variables 
#include<stdio.h> 
#include <pthread.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <immintrin.h>
//#define MAX 4 

float matA[4][4] = {3,6,7,8,3,5,6,2,9,1,2,7,0,9,3,6}; 
float matB[4][4] = {3,6,7,8,3,5,6,2,9,1,2,7,0,9,3,6};
	

//Each thread computes single element in the resultant matrix 
void *mult(void* arg) 
{ 
	//int *data = (int *)arg; 
	//int k = 0, 
    int i = 0; 
	
	//int x = data[0]; 
	for (i = 1; i <= x; i++)
    {
        __m128i data_1 = _mm_loadu_si128((__m128i*) &data[i]);
        __m128i data_2 = _mm_loadu_si128((__m128i*) &data[i+x]);
        __m128i s = _mm_mulhi_epi16(data_1, data_2);
        //__m128i a = _mm_mul_ss(data_1, data_2);
        __m128i k = _mm_add_epi16(k, s);
		//k += data[i]*data[i+x];
         
    }
    printf("data: %d, %d \n", data_1, data_2);
	int *p = (int*)malloc(sizeof(int)); 
		*p = k; 
	
//Used to terminate a thread and the return value is passed as a pointer 
	pthread_exit(p); 
} 

//Driver code 
int main() 
{ 
    //int matA[4][4];
    //int matB[4][4];
	
	int r1=4,c1=4,r2=4,c2=4,i,j,k; 

/***
	// Create random values in matA 
	for (i = 0; i < r1; i++) 
			for (j = 0; j < c1; j++) 
				matA[i][j] = rand() % 10; 
			
		//Create random values in matB 
	for (i = 0; i < r1; i++) 
			for (j = 0; j < c1; j++) 
				matB[i][j] = rand() % 10; 
***/	
	//Print matA		 
	for (i = 0; i < r1; i++){ 
		for(j = 0; j < c1; j++) 
			printf("%d ",matA[i][j]); 
		printf("\n"); 
	} 
			
	//Print matB				 
	for (i = 0; i < r2; i++){ 
		for(j = 0; j < c2; j++) 
			printf("%d ",matB[i][j]); 
		printf("\n");	 
	} 
	
	
	int max = r1*c2; 
	
	
	//declaring array of threads of size r1*c2		 
	pthread_t *threads; 
	//threads = (pthread_t*)malloc(max*sizeof(pthread_t)); 
	
	//int count = 0; 
	//int* data = NULL; 
	//for (i = 0; i < r1; i++) 
		//for (j = 0; j < c2; j++) 
			//{ 
				
			//storing row and column elements in data 
			//data = (int *)malloc((20)*sizeof(int)); 
			//data[0] = c1; 
	
			//for (k = 0; k < c1; k++) 
				//data[k+1] = matA[i][k]; 
	
			//for (k = 0; k < r2; k++) 
				//data[k+c1+1] = matB[k][j]; 
			
			//creating threads 
				pthread_create(&threads, NULL, 
							mult, NULL); 
				
					//} 
	
	printf("RESULTANT MATRIX IS : \n"); 
	for (i = 0; i < max; i++) 
	{ 
	void *k; 
		
	//Joining all threads and collecting return value 
	pthread_join(threads[i], &k); 
			
			
		int *p = (int *)k; 
	printf("%d ",*p); 
	if ((i + 1) % c2 == 0) 
		printf("\n"); 
	} 

return 0; 
} 
