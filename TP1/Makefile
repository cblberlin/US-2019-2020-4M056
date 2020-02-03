all: premierprog.exe prog2.exe analyse.exe analyse_algo.exe

premierprog.exe: premierprog.cpp
	g++ -Wall -pedantic premierprog.cpp -o premierprog.exe

prog2.exe: programme2.cpp
	g++ -Wall -pedantic -O2 programme2.cpp -o prog2.exe
	
analyse.exe: analyse.cpp
	g++ -Wall -pedantic -O2 analyse.cpp -o analyse.exe
	
analyse_algo.exe: analyse_algo.cpp
	g++ -Wall -pedantic -O2 -std=c++11 analyse_algo.cpp -o analyse_algo.exe

clean:
	rm -f *.exe

