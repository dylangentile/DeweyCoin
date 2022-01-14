#include <stdio.h>
#include <stdlib.h>

#include "keccak.h"

const char msg[] = "Sicko Mode!";
const size_t msg_size = sizeof(msg);

int 
main(/*int argc, char const *argv[]*/)
{
	printf("DeweyCoin!!!\n\n");

	uint8_t* hash = (uint8_t*)calloc(32, sizeof(*hash));
	dc_hash((const uint8_t*)msg, msg_size, hash, 32);

	for(int i = 0; i < 32; i++)
		printf("%02x", hash[i]);
	printf("\n\n");



	
	return 0;
}
