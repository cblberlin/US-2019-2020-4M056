CC = g++

CFLAGS = -Wall -pedantic -std=c++11

test_permutation.exe: arithm.o permutation.o test_permutation.o
	$(CC) -o test_permutation.exe arithm.o permutation.o test_permutation.o

arithm.o: arithm.hpp arithm.cpp
	$(CC) -c arithm.cpp $(CFLAGS)

permutation.o: permutation.hpp permutation.cpp
	$(CC) -c permutation.cpp $(CFLAGS)

test_permutation.o: permutation.o test_permutation.cpp
	$(CC) -c test_permutation.cpp $(CFLAGS)

clean:
	rm *.o
