#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

unsigned int absolute(int x)
{
    if(x < 0)
        x = x * (-1);
    return x;
}

unsigned int absolute_asm(int x);

int main(int argc, char **argv)
{
    unsigned int x = absolute_asm(-10);
    unsigned int y = absolute_asm(20);
    printf("x: %d, y: %d \n", x, y);
    return 0;

}