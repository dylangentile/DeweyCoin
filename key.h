#ifndef DEWEYCOIN_KEY_H
#define DEWEYCOIN_KEY_H

#include <stdint.h>


#define DC_PRIVATE_KEY_SIZE 32
#define DC_PUBLIC_KEY_SIZE 33

typedef struct
{
	uint8_t bytes[DC_PRIVATE_KEY_SIZE];
} PrivateKey; //32 bytes

typedef struct
{
	uint8_t bytes[DC_PUBLIC_KEY_SIZE];
	uint8_t padding[8 - (DC_PUBLIC_KEY_SIZE%8)]; //7 bytes
} PublicKey; //40 bytes

typedef struct
{
	PrivateKey private; //32 bytes
	PublicKey public; //40 bytes
} KeyPair; //72 bytes


int dc_key_generate(PrivateKey* key);
int dc_key_make_public(PublicKey* pub_key, const PrivateKey* priv_key);

void dc_key_private_print(const PrivateKey* key);
void dc_key_public_print(const PublicKey* pub_key);




#endif //DEWEYCOIN_KEY_H
