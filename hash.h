#ifndef DEWEYCOIN_HASH_H
#define DEWEYCOIN_HASH_H

#include <stdint.h>

#define DC_HASH_SIZE 32

typedef struct
{
	uint8_t byte_array[DC_HASH_SIZE];
} Hash;


void dc_hash_print(const Hash* const hash);
void dc_hash_add(Hash* sum, const Hash* const a, const Hash* const b); //note: this is not naive addition, it is a hash of the two hashes concatenated.



#endif //DEWEYCOIN_HASH_H
