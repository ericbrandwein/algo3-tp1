all: fuerza_bruta meet_in_the_middle backtracking dinamica

tiempos: fuerza_bruta.o meet_in_the_middle.o backtracking.o dinamica.o utils.o main.cpp
	g++ $^ -o tiempos

%.o: %.cpp
	g++ $< -c -o $@

%: %.cpp utils.o
	g++ -g $< utils.o -std=c++11 -o $@

clean:
	rm fuerza_bruta
	rm meet_in_the_middle
	rm backtracking
	rm dinamica
	rm utils.o
