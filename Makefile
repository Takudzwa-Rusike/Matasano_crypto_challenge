CC =g++
SET1_OBJ = util.o decrypt.o encrypt.o aes.o
SET2_OBJ = block_cipher.o
FLAGS = -Wall -Werror -pedantic -std=c++11 -lcrypto -lssl
SRCDIR = src
INCDIR = include
PROJ = 

all: set1 set2

set2: $(SET2_OBJ)
	$(CC) $(FLAGS) $(SET2_OBJ) set2.cpp -o set2

set1: $(SET1_OBJ)
	$(CC) $(FLAGS) $(SET1_OBJ) set1.cpp -o set1

util.o:
	$(CC) $(FLAGS) $(SRCDIR)/util.cpp $(INCDIR)/util.hpp -c 

decrypt.o:
	$(CC) $(FLAGS) $(SRCDIR)/decrypt.cpp $(INCDIR)/decrypt.hpp -c 

encrypt.o:
	$(CC) $(FLAGS) $(SRCDIR)/encrypt.cpp $(INCDIR)/encrypt.hpp -c 

aes.o:
	$(CC) $(FLAGS) $(SRCDIR)/aes.cpp $(INCDIR)/aes.hpp -c 

block_cipher.o:
	$(CC) $(FLAGS) $(SRCDIR)/block_cipher.cpp $(INCDIR)/block_cipher.hpp -c 


clean:
	rm set1 set2 *.o

.PHONY: clean all

