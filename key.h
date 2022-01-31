#ifndef DEWEYCOIN_KEY_H
#define DEWEYCOIN_KEY_H

#include <stdint.h>


#define DC_PRIVATE_KEY_SIZE 32

typedef struct
{
	uint8_t bytes[DC_PRIVATE_KEY_SIZE];
} PrivateKey;

typedef struct
{
	uint8_t bytes[33];
	uint8_t padding[7];
} PublicKey;


PrivateKey dc_key_generate();
PublicKey dc_key_make_public(const PrivateKey* key);
void dc_key_private_print(const PrivateKey* key);




#endif //DEWEYCOIN_KEY_H
