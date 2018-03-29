backtracking: backtracking.cpp utils.o
	g++ backtracking.cpp utils.o -std=c++11 -o backtracking

fuerza_bruta: fuerza_bruta.cpp utils.o
	g++ fuerza_bruta.cpp utils.o -std=c++11 -o fuerza_bruta

utils.o: utils.cpp
	g++ utils.cpp -c -o utils.o

clean:
	rm fuerza_bruta
	rm backtracking
	rm utils.o
