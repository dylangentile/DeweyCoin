#include "key.h"
#include "secp256k1.h"
#include <stdio.h>
#include <stdlib.h>

PrivateKey 
dc_key_generate()
{
	secp256k1_context* const ctx = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY);
	PrivateKey key;
	
	FILE* fd = fopen("/dev/urandom", "r");
	if(!fd)
	{
		fprintf(stderr, "failed to open /dev/urandom");
		exit(1);
	}


	int i = 1;
	while(1)
	{	
		if(fread(&key, 1, DC_PRIVATE_KEY_SIZE, fd) != DC_PRIVATE_KEY_SIZE)
		{
			fprintf(stderr, "Failed to read from urandom....\n");
			exit(1);
		}


		if(secp256k1_ec_seckey_verify(ctx, (const unsigned char*)&key))
			break;
		i++;
	}

	printf("%d tries\n", i);

	fclose(fd);

	return key;
}


PublicKey 
dc_key_make_public(const PrivateKey* key)
{
	
}

void 
dc_key_private_print(const PrivateKey* key)
{
	for(int i = 0; i < DC_PRIVATE_KEY_SIZE; i++)
		printf("%02x", key->bytes[i]);
	fflush(stdout);
}
