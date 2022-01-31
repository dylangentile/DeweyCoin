#include "key.h"
#include "secp256k1.h"
#include <stdio.h>
#include <stdlib.h>

int 
dc_key_generate(PrivateKey* key)
{
	secp256k1_context* const ctx = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY);
	FILE* fd = fopen("/dev/urandom", "r");
	int ret_code = 1;

	if(!fd)
	{
		fprintf(stderr, "failed to open /dev/urandom \n");
		ret_code = 0;
		goto CTX_CLEANUP;
	}


	while(1)
	{	
		if(fread(key, 1, DC_PRIVATE_KEY_SIZE, fd) != DC_PRIVATE_KEY_SIZE)
		{
			fprintf(stderr, "Failed to read from urandom....\n");
			ret_code = 0;
			goto CLEANUP;
		}


		if(secp256k1_ec_seckey_verify(ctx, (const unsigned char*)key))
			break;
	}

	CLEANUP:
	fclose(fd);
	CTX_CLEANUP:
	secp256k1_context_destroy(ctx);
	return ret_code;
}


int 
dc_key_make_public(PublicKey* pub_key, const PrivateKey* priv_key)
{
	secp256k1_context* const ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN);
	secp256k1_pubkey pubkey_raw;
	size_t output_size = DC_PUBLIC_KEY_SIZE;
	int ret_code = 1;

	if(!secp256k1_ec_pubkey_create(ctx, &pubkey_raw, (const unsigned char*)priv_key))
	{
		fprintf(stderr, "Failed to create public key from private!");
		ret_code = 0;
		goto CLEANUP;
	}

	//always returns 1, no need for check
	secp256k1_ec_pubkey_serialize(ctx, (unsigned char*)pub_key, &output_size, &pubkey_raw, SECP256K1_EC_COMPRESSED);


	CLEANUP:
	secp256k1_context_destroy(ctx);
	return ret_code;

}

void 
dc_key_private_print(const PrivateKey* key)
{
	for(int i = 0; i < DC_PRIVATE_KEY_SIZE; i++)
		printf("%02x", key->bytes[i]);
	fflush(stdout);
}

void
dc_key_public_print(const PublicKey* pub_key)
{
	for(int i = 0; i < DC_PUBLIC_KEY_SIZE; i++)
		printf("%02x", pub_key->bytes[i]);
	fflush(stdout);
}
