#include <stdio.h>
#include <immintrin.h>
#include <pthread.h>

float MatA[4][4] = {0,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3};   //matrix A
float MatB[4][4] = {0,1,2,3,4,5,6,7,8,9,8,7,6,5,4,3};   //matrix B
float temp[2][32] = {0};                                //temporary array to store 2 rows at a time
float resultant[4][4] = {0};                            //resultant matrix of the multiplication

void* matrixMul(void *arg)
{
	int rows = 0, col = 0;
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				temp[rows][col] = MatA[i][k] * MatB[k][j];      //store the result of the multiplication to a temporary array
				if (rows != 0)                                  //elements in rows
				{
					rows--;                                      //to go to the next row
					col++;                                      //increment to the next column
				}
				else 
					rows++;                                     // increment if first row
			}
		}
	}
	
	
	int row_1 = 0; //first two rows
	for (int row = 0; row < 2; row++) 
	{
		int column = 0;
		for (int i = 0; i < 2; i++)
		{
			__m128 load_row_1 = _mm_load_ps(temp[0] + (row_1 * 4));                         //load row 1
			__m128 load_row_2 = _mm_load_ps(temp[1] + (row_1 * 4));                         //load row 2
			__m128 add_row12 = _mm_add_ps(load_row_1, load_row_2);                          //add together
			resultant[column][row] = ((float*)&add_row12)[0] + ((float*)&add_row12)[1];     //like classwork_7
			resultant[column + 1][row] = ((float*)&add_row12)[2] + ((float*)&add_row12)[3]; // 
			if (column != 2)
			{
				column += 2;                                                                //check if you have two columns
			}
            else
				column = 0;
			row_1++;
		}
	}

//repeat for the next two rows

	int row_2 = 4; //third and fourth row
	for (int row = 2; row < 4; row++)
	{
		int column = 0;
		for (int i = 0; i < 2; i++)
		{
			__m128 load_row_3 = _mm_load_ps(temp[0] + (row_2 * 4));                         //load row 3
			__m128 load_row_4 = _mm_load_ps(temp[1] + (row_2 * 4));                         //load row 4
			__m128 add_row34 = _mm_add_ps(load_row_3, load_row_4);                          //add row 3 and row 4
			resultant[column][row] = ((float*)&add_row34)[0] + ((float*)&add_row34)[1]; 
			resultant[column + 1][row] = ((float*)&add_row34)[2] + ((float*)&add_row34)[3];   
			if (column != 2)                                                                //check if thir
			{
				column += 2;
			}
			else
				column = 0;
			row_2++;
		}
	}
	return NULL;
}

int main(int avgc, char **avgs)
{
	pthread_t thread1;                                  
	pthread_create(&thread1, NULL, matrixMul, NULL);                                        //create thread
	pthread_join(thread1, NULL);                                                            //join main thread after thread1 done
	
	printf("RESULTANT MATRIX: \n");
	for (int row = 0; row < 4; row++)
	{
		for (int column = 0; column < 4; column++)
		{
			printf("%5.0f  ", resultant[column][row]); 
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
