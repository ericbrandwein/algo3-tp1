using namespace std;

#include <iostream>
#include <algorithm>
#include <vector>
#include "utils.h"


// void print_items(vector<item> items) {
// 	cout << endl;
// 	for (int i = 0; i < items.size(); i++) {
// 		cout << items[i].peso << " " << items[i].valor << endl;
// 	}
// }

/**
Calcula la proxima solucion, empezando desde la posicion pasada.
*/
void solucion_desde(int capacidad, vector<item> items,
	bool items_actuales[], int* valor_actual, int* peso_actual,
	int posicion_actual) {

	int peso = *peso_actual;
	int valor = *valor_actual;
	for (;posicion_actual < items.size(); posicion_actual++) {
		item item_actual = items[posicion_actual];
		// podamos por factibilidad
		if (peso + item_actual.peso <= capacidad) {
			peso += item_actual.peso;
			valor += item_actual.valor;
			items_actuales[posicion_actual] = true;
		} else {
			items_actuales[posicion_actual] = false;
		}
	}
	*peso_actual = peso;
	*valor_actual = valor;
}

/**
Setea en items_actuales la proxima combinacion de items que
podria ser una solucion.

Devuelve false si los items_actuales ya constituyen la ultima solucion.
*/
bool proxima_solucion(int capacidad, vector<item> items,
	bool items_actuales[], int* valor_actual, int* peso_actual) {

	int valor = *valor_actual;
	int peso = *peso_actual;
	int posicion_actual;
	// Encontramos el ultimo que sea verdadero
	for (posicion_actual = items.size() - 1;
		posicion_actual >= 0 && !items_actuales[posicion_actual];
		posicion_actual--);

	if (posicion_actual < 0) {
		// Si no hay ultimo que sea verdadero, entonces terminamos.
		return false;
	}

	*valor_actual -= items[posicion_actual].valor;
	*peso_actual -= items[posicion_actual].peso;
	items_actuales[posicion_actual] = false;
	solucion_desde(capacidad, items, items_actuales,
		valor_actual, peso_actual, ++posicion_actual);

	return true;
}

bool comparar_por_ratio(item i, item j) {
	return (double) i.valor / (double) i.peso >
		(double) j.valor / (double) j.peso;
}

int backtracking(int capacidad, vector<item> items) {
	// Ordenamos primero los items por valor / peso
	sort(items.begin(), items.end(), comparar_por_ratio);

	bool items_actuales[items.size()];
	int mejor = 0;
	int valor_actual = 0;
	int peso_actual = 0;
	solucion_desde(capacidad, items, items_actuales,
		&valor_actual, &peso_actual, 0);

	do {
		// items_actuales tiene la proxima solucion
		mejor = max(mejor, valor_actual);
	} while (proxima_solucion(capacidad, items, items_actuales,
			&valor_actual, &peso_actual));

	return mejor;
}

int main() {
	int capacidad, cant_items;
	vector<item> items = parsear_entrada(&capacidad, &cant_items);
    int solucion = backtracking(capacidad, items);

    cout << solucion << endl;
    return 0;
}

