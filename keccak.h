#ifndef DEWEYCOIN_KECCAK_H
#define DEWEYCOIN_KECCAK_H

#include "hash.h"
#include <stdint.h>

void Keccak(unsigned int rate, unsigned int capacity, const unsigned char *input, unsigned long long int inputByteLen, unsigned char delimitedSuffix, unsigned char *output, unsigned long long int outputByteLen);
void dc_data_hash(const uint8_t* input_buf, const uint64_t input_size,  Hash* hash);

_Static_assert(sizeof(uint64_t) == sizeof(unsigned long long int), "bad size match with keccak code!");
_Static_assert(sizeof(uint8_t) == sizeof(unsigned char), "bad size match with keccak code!");


#endif //DEWEYCOIN_KECCAK_H
