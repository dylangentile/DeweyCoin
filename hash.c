#include "hash.h"

#include <stdio.h>

void 
dc_hash_print(const Hash* const hash)
{
	for(int i = 0; i < DC_HASH_SIZE; i++)
		printf("%02x", hash->byte_array[i]);
	fflush(stdout);
}
