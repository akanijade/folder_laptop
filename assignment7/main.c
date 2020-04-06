#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

uint8_t	compute_grey(uint32_t* p);

int 	main(int ac, char** av)
{
	uint32_t* p = malloc(sizeof(uint32_t));
	*p = 0xffbc0011;
	uint8_t num = compute_grey(p);
	printf("%u\n", num);

}
