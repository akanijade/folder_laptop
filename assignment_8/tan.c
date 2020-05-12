#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <nmmintrin.h>

#define MAX 4

float	matrix_A[MAX][MAX];
float	matrix_B[MAX][MAX];
float	matrix_C[MAX][MAX]; //will be the result of A * B
int	working_i = 0;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;

void	generate_matrix(float tmp[MAX][MAX])
{
	time_t t;

	srand((unsigned) time(&t)); //initalize random
	for(int row = 0; row < MAX; ++row)
		for(int col = 0; col < MAX; ++col)
			tmp[row][col] = (float) (rand() % 5); //random number from 0 to 4
}

void	print_matrix(float tmp[MAX][MAX])
{
	for(int row = 0; row < MAX; ++row)
	{
		for(int col = 0; col < MAX; ++col)
			printf("%-9.2f ", tmp[row][col]);
		printf("\n");
	}
}

float	compute(float tmp_1[MAX], float tmp_2[MAX])
{
	float a[MAX];
	float result = 0;
	__m128 x = _mm_loadu_ps(tmp_1);
	__m128 y = _mm_loadu_ps(tmp_2);
	__m128 mul = _mm_mul_ps(x, y);	
	_mm_storeu_ps(a, mul);

	for(int i = 0; i < MAX; ++i)
		result += a[i];
	return result;
}

void*	mult(void *arg)
{
	float row[MAX];
	float col[MAX];
	pthread_mutex_lock(&m1);
	int r = working_i++;
	pthread_mutex_unlock(&m1);
	
	for(int i = r; i < r + 1; ++i) //row from matrix A
	{
		for(int j = 0; j < MAX; ++j) //col from matrix B
		{
			for(int k = 0; k < MAX; ++k) //col from matrix A and row from matrix B
			{
				//matrix_C[i][j] += matrix_A[i][k] * matrix_B[k][j];
				row[k] = matrix_A[i][k];
				col[k] = matrix_B[k][j];
			}
			matrix_C[i][j] = compute(row, col);
		}
	}
}

int	main()
{
	pthread_t threads[MAX];
	
	generate_matrix(matrix_A);
	printf("matrix A\n");
	print_matrix(matrix_A);

	generate_matrix(matrix_B);
	printf("matrix B\n");
	print_matrix(matrix_B);

	//start threads
	for(int i = 0; i < MAX; ++i)
		pthread_create(&threads[i], NULL, mult, NULL);
	for(int i = 0; i < MAX; ++i)
		pthread_join(threads[i], NULL);
	//wait for all the threads to finish

	printf("matrix A * matrix B\n");
	print_matrix(matrix_C);	
	return 0;
}