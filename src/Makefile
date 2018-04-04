all: fuerza_bruta meet_in_the_middle backtracking dinamica

utils.o: utils.cpp
	g++ utils.cpp -c -o utils.o

%: %.cpp utils.o
	g++ -g $< utils.o -std=c++11 -o $@

clean:
	rm fuerza_bruta
	rm meet_in_the_middle
	rm backtracking
	rm dinamica
	rm utils.o
