CC = g++

CXXFLAGS = -std=c++11

test_interpolation.exe: interpolation.o interpolation.cpp
	$(CC) -o test_interpolation.exe test_interpolation.cpp interpolation.o

interpolation.o: interpolation.hpp interpolation.cpp
	$(CC) -c interpolation.cpp $(CXXFLAGS)

clean:
	rm *.o
