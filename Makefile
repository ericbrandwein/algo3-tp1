meet_in_the_middle: meet_in_the_middle.cpp utils.o
	g++ meet_in_the_middle.cpp utils.o -std=c++11 -o meet_in_the_middle

backtracking: backtracking.cpp utils.o
	g++ backtracking.cpp utils.o -std=c++11 -o backtracking

fuerza_bruta: fuerza_bruta.cpp utils.o
	g++ fuerza_bruta.cpp utils.o -std=c++11 -o fuerza_bruta

utils.o: utils.cpp
	g++ utils.cpp -c -o utils.o

clean:
	rm fuerza_bruta
	rm backtracking
	rm meet_in_the_middle
	rm utils.o
