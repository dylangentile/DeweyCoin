#ifndef DEWEYCOIN_KECCAK_H
#define DEWEYCOIN_KECCAK_H

#include <stdint.h>

void Keccak(unsigned int rate, unsigned int capacity, const unsigned char *input, unsigned long long int inputByteLen, unsigned char delimitedSuffix, unsigned char *output, unsigned long long int outputByteLen);
void dc_hash(const uint8_t* input_buf, const uint64_t input_size,  uint8_t* const output, const uint64_t output_size);

_Static_assert(sizeof(uint64_t) == sizeof(unsigned long long int), "bad size match with keccak code!");
_Static_assert(sizeof(uint8_t) == sizeof(unsigned char), "bad size match with keccak code!");


#endif
