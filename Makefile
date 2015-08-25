CC =g++
OBJ = decode_encode.o decrypt.o encrypt.o
FLAGS = -Wall -Werror -pedantic -std=c++11
SRCDIR = src
INCDIR = include
PROJ = 

set1: $(OBJ)

	$(CC) $(FLAGS) $(OBJ) set1.cpp -o set1

decode_encode.o:
	$(CC) $(FLAGS) $(SRCDIR)/decode_encode.cpp $(INCDIR)/decode_encode.hpp -c 

decrypt.o:
	$(CC) $(FLAGS) $(SRCDIR)/decrypt.cpp $(INCDIR)/decrypt.hpp -c 

encrypt.o:
	$(CC) $(FLAGS) $(SRCDIR)/encrypt.cpp $(INCDIR)/encrypt.hpp -c 

clean:
	rm set1 *.o

.PHONY: clean

