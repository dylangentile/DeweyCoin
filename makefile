CC := clang
CFLAGS := -Werror -Wall -Wextra -pedantic -std=c11 #-pthread

OBJ := main.o hash.o keccak.o
TARGET := deweycore

.PHONY: all clean depend

all: $(TARGET)

libsecp256k1.a:
	cd secp256k1; \
	./autogen.sh; \
	./configure
	make -C secp256k1
	mv secp256k1/.libs/libsecp256k1.a .

$(TARGET): libsecp256k1.a $(OBJ)
	$(CC) libsecp256k1.a $(OBJ) -o $(TARGET)

clean:
	-rm *.o
	-rm $(TARGET)

depend:
	$(CC) $(CFLAGS) -E -MM $(OBJ:.o=.c) > .depend

include .depend