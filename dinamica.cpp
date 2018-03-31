using namespace std;

#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include "utils.h"

int dinamica(int capacidad_total, vector<item> items) {
	// Vector de vectores de valores, cada columna indica la capacidad
	// y cada fila indica la cantidad de items que estamos usando.
	vector<vector<int>> valores_por_capacidades;
	// Le sumamos uno a la capacidad por si hay items con peso 0.

	for (int numero_item = 0; numero_item < items.size(); numero_item++) {
		vector<int> valores;
		item item_actual = items[numero_item];

		for (int capacidad_parcial = 0;
			capacidad_parcial <= capacidad_total;
			capacidad_parcial++) {

			int valor = 0;
			if (item_actual.peso <= capacidad_parcial) {
				valor = item_actual.valor;
				if (numero_item > 0) {
					int capacidad_sumable =
						capacidad_parcial - item_actual.peso;
					int cantidad_de_items = numero_item - 1;
					valor += valores_por_capacidades[
						cantidad_de_items][capacidad_sumable];
				}
			}

			if (numero_item > 0) {
				valor = max(valor, valores_por_capacidades[
					numero_item - 1][capacidad_parcial]);
			}
			valores.push_back(valor);
		}
		valores_por_capacidades.push_back(valores);
	}

	int valor_final = 0;
	if (items.size() > 0) {
		valor_final = valores_por_capacidades[items.size() - 1][capacidad_total];
	}

	return valor_final;
}

int main() {
	int capacidad, cant_items;
	vector<item> items = parsear_entrada(&capacidad, &cant_items);
    int solucion = dinamica(capacidad, items);

    cout << solucion << endl;
    return 0;
}
