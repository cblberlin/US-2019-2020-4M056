CC= g++
CFLAGS= -Wall -pedantic -I /usr/local/include/eigen3 -O2 -std=c++11

all: matrice.exe

matrice.exe: matrice.cpp
	$(CC) matrice.cpp $(CFLAGS) -o matrice.exe

clean:
	rm *.exe