#ifndef DEWEYCOIN_BLOCK_H
#define DEWEYCOIN_BLOCK_H

typedef struct
{
	int64_t unix_timestamp; //8 bytes
	uint64_t nonce; //8 bytes
	Hash prev_hash; //32 bytes
	Hash tree_root; //32 bytes
} BlockHeader; //80 bytes



typedef struct
{
	BlockHeader header;
	uint64_t tx_count;
	Transaction* tx_array;
} Block;

#endif //DEWEYCOIN_BLOCK_H
