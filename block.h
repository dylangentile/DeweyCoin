#ifndef DEWEYCOIN_BLOCK_H
#define DEWEYCOIN_BLOCK_H

typedef struct
{
	uint64_t unix_timestamp; //8 bytes
	uint64_t nonce; //8
	Hash prev_hash; //32
	Hash merkle_root; //32
} BlockHeader; //80 bytes




#endif //DEWEYCOIN_BLOCK_H
