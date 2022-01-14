#include <stdio.h>
#include <stdlib.h>

#include "hash.h"
#include "keccak.h"

const char msg[] = "Sicko Mode!";
const size_t msg_size = sizeof(msg);

int 
main(/*int argc, char const *argv[]*/)
{
	printf("DeweyCoin!!!\n\n");

	Hash hash;
	dc_data_hash((const uint8_t*)msg, msg_size, &hash);
	dc_hash_print(&hash);
	
	printf("\n\n");



	
	return 0;
}
