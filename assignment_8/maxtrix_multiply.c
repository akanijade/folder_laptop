//matrix multiplication
//gcc -pthread -omatrix_multiply maxtrix_multiply.c -mavx
#include "pthread.h"
#include <stdio.h>
#include <immintrin.h>
#define HAVE_STRUCT_TIMESPEC
#include <pthread.h>

float a[4][4] = { 3,7,3,6,9,2,0,3,0,2,1,7,2,2,7,9 }, b[4][4] = { 6,5,5,2,1,7,9,6,6,6,8,9,0,3,5,2 }, results[4][4] = { 0 };

void *thread(void *arg)
{
	int k = 0;
	float c[4] = { 0 };
	for (int k = 0; k < 2; k++)
	{
		__m128 x = _mm_load_ps(a[k]);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				c[j] = b[j][i];
			__m128 y = _mm_load_ps(c);
			__m128 z = _mm_mul_ps(x, y);
			__m128 xx = _mm_hadd_ps(z, z);
			results[k][i] = ((float*)&xx)[0] + ((float*)&xx)[1];
		}
	}
	return NULL;
}

int main(int argc, char **args)
{
	pthread_t t;
	pthread_create(&t, NULL, thread, NULL);
	int k = 0;
	float c[4] = { 0 };
	for (int k = 2; k < 4; k++)
	{
		__m128 x = _mm_load_ps(a[k]);
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
				c[j] = b[j][i];
			__m128 y = _mm_load_ps(c);
			__m128 z = _mm_mul_ps(x, y);
			__m128 xx = _mm_hadd_ps(z, z);
			results[k][i] = ((float*)&xx)[0] + ((float*)&xx)[1];
		}
	}
	pthread_join(t, NULL);
    printf("Resultant matrix is: \n");
	for (int column = 0; column < 4; column++)
	{
		for (int row = 0; row < 4; row++)
			printf("%5.0f", results[column][row]);
		printf("\n");
	}
	return 0;
}