CC =g++
OBJ = util.o decrypt.o encrypt.o
FLAGS = -Wall -Werror -pedantic -std=c++11
SRCDIR = src
INCDIR = include
PROJ = 

set1: $(OBJ)

	$(CC) $(FLAGS) $(OBJ) set1.cpp -o set1

util.o:
	$(CC) $(FLAGS) $(SRCDIR)/util.cpp $(INCDIR)/util.hpp -c 

decrypt.o:
	$(CC) $(FLAGS) $(SRCDIR)/decrypt.cpp $(INCDIR)/decrypt.hpp -c 

encrypt.o:
	$(CC) $(FLAGS) $(SRCDIR)/encrypt.cpp $(INCDIR)/encrypt.hpp -c 

clean:
	rm set1 *.o

.PHONY: clean

