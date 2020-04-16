#include <stdio.h>
#include <stdint.h>
//rax //rdi //rsi //rdx //rcx
int variance(uint32_t* s, int32_t* t, uint32_t z);
// 10, 7
int main(int argc, char** argv) {
uint32_t src[10] = {1, 2, 3, 4, 5, 60, 77, 23, 33, 55};
int32_t tmp[10] = {0};

int x = variance(src, tmp, 10);
//calculate avergae of of the array
//x = sub each value from average
//sq the each number
// add them
// divide with total number elements
printf("avg: %d \n", x);
for(int i = 0; i < 10; i++)
    printf("tmp: %d ", tmp[i]);

printf("sum: %d \n", )
return 0;
}