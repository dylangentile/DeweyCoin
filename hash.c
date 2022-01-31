#include "hash.h"
#include "keccak.h"

#include <stdio.h>

void 
dc_hash_print(const Hash* const hash)
{
	for(int i = 0; i < DC_HASH_SIZE; i++)
		printf("%02x", hash->bytes[i]);
	fflush(stdout);
}

void 
dc_hash_add(Hash* sum, const Hash* const a, const Hash* const b)
{
	Hash hash_data[2];
	hash_data[0] = *a;
	hash_data[1] = *b;

	dc_hash_print(hash_data);
	dc_hash_print(hash_data + 1);
	printf("\n");

	dc_data_hash((const uint8_t*)hash_data, sizeof(*hash_data) * 2, sum);
}
