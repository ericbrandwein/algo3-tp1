using namespace std;

#include <iostream>
#include <algorithm>
#include <vector>
#include "utils.h"

int dinamica(int capacidad, vector<item> items) {
	// Le sumamos uno a la capacidad por si hay items con peso 0
	bool items_presentes[capacidad + 1][items.size()];
	for (int i = 0; i <= capacidad; i++) {
		for (int j = 0; j < items.size(); ++j) {
			items_presentes[i][j] = false;
		}
	}
	// for (int i = 0; i < capacidad; i++) {

	// }
	return 0;
}

int main() {
	int capacidad, cant_items;
	vector<item> items = parsear_entrada(&capacidad, &cant_items);
    int solucion = dinamica(capacidad, items);

    cout << solucion << endl;
    return 0;
}
