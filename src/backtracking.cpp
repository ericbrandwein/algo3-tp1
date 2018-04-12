using namespace std;

#include <iostream>
#include <algorithm>
#include <vector>
#include "utils.h"

double ratio(item i) {
	return (double) i.valor / (double) i.peso;
}

/**
Devuelve false si este camino no lleva a una solucion optima.

Poda por optimalidad:
	Si llenar lo restante de la capacidad con
	un objeto hipotetico que tenga el mismo ratio que el
	del item de la posicion_actual no mejora el mejor valor,
	entonces no agregamos el item.
	Como los items estan ordenados por ratio, el mejor item proximo es
	el proximo item.
*/
bool por_optimalidad(int capacidad, int peso_actual, int valor_actual,
	int posicion_actual, vector<item> items, int mejor_valor) {

	int valor_solucion = valor_actual;
	double ratio_item = ratio(items[posicion_actual]);
	valor_solucion += ratio_item * (capacidad - peso_actual);
	return valor_solucion > mejor_valor;
}

/**
Devuelve false si no se deberia agregar el item, porque no es factible una
solucion si se agrega.

Poda por factibilidad:
	Si agregar el item hace que nos pasemos de la capacidad,
	no lo agregamos.
*/
bool por_factibilidad(int capacidad, int peso_actual, item nuevo_item) {
	return peso_actual + nuevo_item.peso <= capacidad;
}

int retroceder(bool items_actuales[], vector<item> items,
	int posicion_actual, int *valor_actual, int* peso_actual) {
	// Encontramos el ultimo que sea verdadero
	for (;posicion_actual >= 0 && !items_actuales[posicion_actual];
		posicion_actual--);

	if (posicion_actual >= 0) {
		*valor_actual -= items[posicion_actual].valor;
		*peso_actual -= items[posicion_actual].peso;
		items_actuales[posicion_actual] = false;
	}

	return posicion_actual;
}

int avanzar(int capacidad, bool items_actuales[], vector<item> items,
	int posicion_actual, int* valor_actual, int* peso_actual,
	int mejor_valor) {

	int valor = *valor_actual;
	int peso = *peso_actual;
	// Hacemos decisiones hasta que no nos sirva seguir, por optimalidad.
	for (;
		posicion_actual < items.size() &&
			por_optimalidad(capacidad, peso, valor, posicion_actual,
				items, mejor_valor);
		posicion_actual++) {

		item item_actual = items[posicion_actual];

		if (por_factibilidad(capacidad, peso, item_actual)) {
			peso += item_actual.peso;
			valor += item_actual.valor;
			items_actuales[posicion_actual] = true;
		} else {
			items_actuales[posicion_actual] = false;
		}
	}
	*peso_actual = peso;
	*valor_actual = valor;
	return posicion_actual;
}

bool proxima_solucion_retrocediendo_desde(int capacidad, vector<item> items,
	bool items_actuales[], int* valor_actual, int* peso_actual,
	int mejor_valor, int posicion_actual) {

	do {
		posicion_actual = retroceder(items_actuales, items,
				posicion_actual, valor_actual, peso_actual);

		if (posicion_actual < 0) {
			// Retrocedimos lo maximo y no encontramos un true.
			return false;
		}

		posicion_actual = avanzar(capacidad, items_actuales, items,
			++posicion_actual, valor_actual, peso_actual, mejor_valor);
		// Si posicion_actual < items.size(),
		// entonces todavia no encontramos una solucion nueva.
	} while (posicion_actual < items.size());

	return true;
}

/**
Setea en items_actuales la proxima combinacion de items que
podria ser solucion.

Devuelve false si los items_actuales ya constituyen la ultima solucion.
*/
bool proxima_solucion(int capacidad, vector<item> items,
	bool items_actuales[], int* valor_actual, int* peso_actual,
	int mejor_valor) {

	return proxima_solucion_retrocediendo_desde(
		capacidad, items, items_actuales, valor_actual, peso_actual,
		mejor_valor, items.size() - 1);
}

/**
Devuelve false si no hay solucion posible.
*/
bool primer_solucion(int capacidad, vector<item> items,
	bool items_actuales[], int* valor_actual, int* peso_actual) {
	for (int i = 0; i < items.size(); i++) {
		items_actuales[i] = false;
	}
	int posicion_actual = avanzar(capacidad, items_actuales, items,
			0, valor_actual, peso_actual, 0);
	if (posicion_actual < items.size()) {
		return proxima_solucion_retrocediendo_desde(
			capacidad, items, items_actuales, valor_actual, peso_actual,
			0, posicion_actual);
	}
	return true;
}

bool comparar_por_ratio(item i, item j) {
	return ratio(i) > ratio(j);
}

int backtracking(int capacidad, vector<item> items) {
	// Ordenamos primero los items por valor / peso
	sort(items.begin(), items.end(), comparar_por_ratio);

	bool items_actuales[items.size()];
	int valor_actual = 0;
	int peso_actual = 0;
	int mejor_valor = 0;
	bool hay_solucion = primer_solucion(
		capacidad, items, items_actuales, &valor_actual, &peso_actual);
	while (hay_solucion){
		mejor_valor = max(mejor_valor, valor_actual);
		hay_solucion = proxima_solucion(capacidad, items, items_actuales,
			&valor_actual, &peso_actual, mejor_valor);
	}

	return mejor_valor;
}

int main() {
	int capacidad, cant_items;
	vector<item> items = parsear_entrada(&capacidad, &cant_items);
    int solucion = backtracking(capacidad, items);

    cout << solucion << endl;
    return 0;
}

