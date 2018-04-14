using namespace std;

#include <algorithm>
#include <iostream>
#include <vector>
#include "utils.h"

typedef item parte;

/**
Devuelve una nueva parte que viene de sumar el item a la parte_original.
*/
parte agregar_item(parte& parte_original, item& sumado) {
	return parte(parte_original.peso + sumado.peso,
		parte_original.valor + sumado.valor);
}

/**
Armamos el conjunto de partes sin agregar las partes que se pasan de peso.
*/
vector<parte> conjunto_de_partes(int capacidad, vector<item>& items) {
	vector<parte> partes = {parte(0, 0)};

	for (int i = 0; i < items.size(); i++) {
		item item_actual = items[i];
		int cant_partes_anteriores = partes.size();
		for (int j = 0; j < cant_partes_anteriores; j++) {
			parte nueva_parte = agregar_item(partes[j], item_actual);
			if (nueva_parte.peso <= capacidad) {
				partes.push_back(nueva_parte);
			}
		}
	}

	return partes;
}

/**
Crea un nuevo vector de partes sin las partes inservibles, o sea,
las que tengan una parte con mayor valor y con el mismo o menor peso.

El argumento partes deberia estar ordenado de menor a mayor segun el peso,
y luego de mayor a menor segun el valor.
*/
vector<parte> sacar_partes_inservibles(vector<parte>& partes_originales) {
	vector<parte> partes;
	for (int i = 0; i < partes_originales.size(); i++) {
		/*
		La unica parte que nos tenemos que fijar si es mejor que esta
		es la ultima no inservible. Esto se debe a que esta
		tiene mayor peso y valor que todas las anteriores,
		y la parte actual ya sabemos que tiene mayor o igual peso.
		Entonces, si hay partes mejores que la actual, la ultima
		no inservible tendra mayor valor a todas ellas, y no tendra mayor
		peso que la actual, entonces tambien sera mejor que la actual.

		No hace falta que nos fijemos en ninguna de las proximas partes
		porque sabemos que todas tendran o menor valor e igual peso
		o mayor peso.
		*/
		parte parte_actual = partes_originales[i];
		if (i == 0) {
			partes.push_back(parte_actual);
		} else {
			parte parte_anterior = partes.back();
			if (parte_anterior.valor < parte_actual.valor) {
				partes.push_back(parte_actual);
			}
		}
	}
	return partes;
}

bool comparar_por_peso_y_despues_valor_al_reves(parte& uno, parte& dos) {
	return uno.peso < dos.peso ||
		(uno.peso == dos.peso && uno.valor > dos.valor);
}

bool comparar_peso(int peso, parte parte_actual) {
	return peso < parte_actual.peso;
}

int meet_in_the_middle(int capacidad, vector<item>& items) {
	int mitad_size = items.size() / 2;
	vector<item> mitad_baja(items.begin(), items.begin() + mitad_size);
	vector<item> mitad_alta(items.begin() + mitad_size, items.end());

	vector<parte> partes_baja = conjunto_de_partes(capacidad, mitad_baja);
	vector<parte> partes_alta = conjunto_de_partes(capacidad, mitad_alta);

	// Ordenamos el conjunto de partes de la segunda mitad de los items
	// de menor a mayor segun el peso de cada parte, y si tienen el mismo peso,
	// de mayor a menor segun el valor.
	sort(partes_alta.begin(), partes_alta.end(), comparar_por_peso_y_despues_valor_al_reves);

	// Sacamos las partes que tengan menor valor y mayor o igual peso que
	// otra parte, porque seguro que tenemos otra parte que nos sirve mas.
	partes_alta = sacar_partes_inservibles(partes_alta);

	// Para cada parte en el conjunto bajo, buscamos el que mejor se
	// acople en el conjunto alto, o sea, el que tenga mas peso
	// tal que al sumarselo al peso de la parte actual no se supere
	// la capacidad.
	int mejor = 0;
	for (int i = 0; i < partes_baja.size(); i++) {
		parte parte_actual = partes_baja[i];
		int peso_restante = capacidad - parte_actual.peso;
		// Buscamos el primer elemento que tenga mayor peso que
		// el restante.
		vector<parte>::iterator mejor_parte =
			upper_bound(partes_alta.begin(), partes_alta.end(),
				peso_restante, comparar_peso);
		if (mejor_parte != partes_alta.begin()) {
			mejor_parte--;
			parte_actual = agregar_item(parte_actual, *mejor_parte);
		}
		mejor = max(mejor, parte_actual.valor);
	}
	return mejor;
}

int main() {
	int capacidad, cant_items;
	vector<item> items = parsear_entrada(&capacidad, &cant_items);
    int solucion = meet_in_the_middle(capacidad, items);

    cout << solucion << endl;
    return 0;
}