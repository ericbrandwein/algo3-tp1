using namespace std;
#include <iostream>
#include <vector>
#include <chrono>
#include "utils.h"
#include "fuerza_bruta.h"
#include "meet_in_the_middle.h"
#include "backtracking.h"
#include "dinamica.h"

void medir_tiempo(int capacidad, vector<item> items,
	int (*funcion)(int, vector<item>&)) {

	auto tiempoAntes = chrono::steady_clock::now();
    int solucion = funcion(capacidad, items);
    auto tiempoDespues = chrono::steady_clock::now();

    auto tiempoTardado = tiempoDespues - tiempoAntes;

    cout << chrono::duration <double, milli> (tiempoTardado).count();
    cout << " ";
}

int main() {
	int cant_items, capacidad;
	vector<item> items = parsear_entrada(&cant_items, &capacidad);
	//cout << cant_items << " " << capacidad << endl;

	//medir_tiempo(capacidad, items, fuerza_bruta);
	medir_tiempo(capacidad, items, meet_in_the_middle);
	medir_tiempo(capacidad, items, backtracking);
	medir_tiempo(capacidad, items, dinamica);
	cout << endl;
    return 0;
}