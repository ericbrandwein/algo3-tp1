using namespace std;

#include <iostream>
#include <cstring>
#include <vector>
#include "utils.h"

int valor_de_items(int cant_items, vector<item>& items, bool puestos[]) {
	int valor = 0;
	for (int i = 0; i < cant_items; i++) {
		if (puestos[i]) {
			valor += items[i].valor;
		}
	}
	return valor;
}

int peso_de_items(int cant_items, vector<item>& items, bool puestos[]) {
	int peso = 0;
	for (int i = 0; i < cant_items; i++) {
		if (puestos[i]) {
			peso +=	items[i].peso;
		}
	}
	return peso;
}

/**
 * Calcula el valor de la sol_actual, y se fija si es mejor
 * solucion que la anterior. Devuelve el nuevo mejor valor.
 */
int mejor_solucion(int capacidad, int cant_items,
	vector<item>& items, int valor_anterior,
	bool sol_actual[]) {

	int valor_actual =
		valor_de_items(cant_items, items, sol_actual);
	int peso_actual = peso_de_items(cant_items, items, sol_actual);

	if (peso_actual <= capacidad && valor_anterior < valor_actual) {
		return valor_actual;
	}
	return valor_anterior;
}


/**
Devuelve true si esta combinacion es la ultima.
*/
bool proxima_combinacion(int cant_items, bool items_actuales[]) {
	int posicion;
	for (posicion = cant_items - 1;
		posicion >= 0 && items_actuales[posicion];
		posicion--){
		// Ponemos todos los items que pertenecen a la cola de trues
		// en false.
		items_actuales[posicion] = false;
	}

	// posicion == ultima posicion falsa
	if (posicion >= 0) {
		items_actuales[posicion] = true;
		return false;
	}
	// Si no hay ultima posicion falsa,
	// entonces todas las posiciones son verdaderas,
	// con lo cual ya terminamos.
	return true;
}

int fuerza_bruta(int capacidad, vector<item>& items) {
	// decidiremos para cada objeto si va o no.
	// eso lo podemos hacer con un vector de objetos,
	// o con un array que te diga si esta o no.

	// lo voy a hacer con un array porque no se usar vector,
	// y siento que se me va a complicar mas el codigo si lo uso.

	// array que te dice si cada objeto esta o no esta en la
	// solucion parcial actual.
	int cant_items = items.size();
	bool items_actuales[cant_items];
	for (int i = 0; i < cant_items; i++) {
		items_actuales[i] = false;
	}
	int mejor = 0;

	bool termino = false;
	while (!termino) {
		mejor = mejor_solucion(
			capacidad, cant_items, items, mejor, items_actuales);
		termino = proxima_combinacion(cant_items, items_actuales);
	}

	return mejor;
}

int main() {
	int capacidad, cant_items;
	vector<item> items = parsear_entrada(&cant_items, &capacidad);
    int solucion = fuerza_bruta(capacidad, items);

    cout << solucion << endl;
    return 0;
}

