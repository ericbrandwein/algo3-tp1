using namespace std;

#include <vector>
#include <iostream>
#include "utils.h"

vector<item> parsear_entrada(int* cant_items, int* capacidad) {
	cin >> *cant_items >> *capacidad;
	vector<item> items;
	for (int i = 0; i < *cant_items; i++) {
		int peso, valor;
		cin >> peso >> valor;
		items.push_back(item(peso, valor));
	}
	return items;
}