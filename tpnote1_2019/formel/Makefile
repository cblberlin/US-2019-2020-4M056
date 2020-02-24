CC = g++

CXXFLAGS = -std=c++11

test_fonction.exe: fonction.o test_fonction.cpp
	$(CC) -o test_fonction.exe test_fonction.cpp fonction.o

fontion.o: fonction.hpp fonction.cpp
	$(CC) -c fonction.cpp $(CXXFLAGS)

clean:
	rm *.o
