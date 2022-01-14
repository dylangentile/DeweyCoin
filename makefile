CC := clang
CFLAGS := -Werror -Wall -Wextra -pedantic -std=c11 #-pthread

OBJ := main.o hash.o keccak.o
TARGET := deweycore

.PHONY: all clean depend

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

clean:
	-rm *.o
	-rm $(TARGET)

depend:
	$(CC) $(CFLAGS) -E -MM $(OBJ:.o=.c) > .depend

include .depend