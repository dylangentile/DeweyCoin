#include <stdio.h>
#include <stdlib.h>

#include "hash.h"
#include "keccak.h"

const char msg[] = "Sicko Mode!";
const size_t msg_size = sizeof(msg);
const char msg_2[] = "ZA WARUDO";
const size_t msg_2_size = sizeof(msg_2);

int 
main(/*int argc, char const *argv[]*/)
{
	printf("DeweyCoin!!!\n\n");

	Hash hash_1;
	Hash hash_2;

	Hash result;
	dc_data_hash((const uint8_t*)msg, msg_size, &hash_1);
	dc_hash_print(&hash_1);
	printf("\n");
	dc_data_hash((const uint8_t*)msg_2, msg_2_size, &hash_2);
	dc_hash_print(&hash_2);
	printf("\n\n");

	dc_hash_add(&result, &hash_1, &hash_2);
	dc_hash_print(&result);



	printf("\n\n");



	
	return 0;
}
