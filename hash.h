#ifndef DEWEYCOIN_HASH_H
#define DEWEYCOIN_HASH_H

#include <stdint.h>

#define DC_HASH_SIZE 32

typedef struct
{
	uint8_t byte_array[DC_HASH_SIZE];
} Hash;


void dc_hash_print(const Hash* const hash);



#endif //DEWEYCOIN_HASH_H
