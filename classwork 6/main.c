#include <stdio.h>
#include <nmmintrin.h>

 

int main(int argc, char** argv) {

float r[8] = {0};
float xx[8] = {1.2, 1.3, 1.4, 1.5, 2.1, 6.1, 7.2, 3.5};
float yy[8] = {1.2, 1.3, 1.4, 1.5, 2.1, 6.1, 7.2, 3.5};
/***
//xmm0 128 bit
//xmm0 1f 1f 1f 1f = 32 x 4 = 128
__m128 x = _mm_load_ps(xx);
__m128 y = _mm_load_ps(yy);

//__m128 x = _mm_set_ps (1.2, 1.3, 1.4, 1.5);
//__m128 y = _mm_set_ps (1.2, 1.3, 1.4, 1.5);
__m128 z = _mm_mul_ps (x, y);
_mm_storeu_ps (r, z);


__m128 x2 = _mm_load_ps(&xx[4]);
__m128 y2 = _mm_load_ps(&yy[4]);

__m128 z2 = _mm_mul_ps (x2, y2);
_mm_storeu_ps (&r[4], z2);

__m128 x = _mm_load_ps(&xx[i]);
__m128 y = _mm_load_ps(&yy[i]);
***/
for (int i = 0; i < 2; ++i) //more efficient
{
    __m128 x = _mm_load_ps(&xx[i*4]);  //load 128-bits from xx array
    __m128 y = _mm_load_ps(&yy[i*4]);  //load 128-bits from yy array

    __m128 z = _mm_mul_ps(x, y);        //multiply single-precisino floating point in x and y
    _mm_storeu_ps (&r[i], z);           //store 128-bits from z to array r

for (int i = 0; i<4; i++)
    printf("%f \n", r[i]);              //print the array r
}
    return 0;
}