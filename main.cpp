#include <iostream>

void fuerza_bruta(int capacidad, int cant_objetos, int pesos[], int valores[]) {
	// decidiremos para cada objeto si va o no.
	// eso lo podemos hacer con un vector de objetos,
	// o con un array que te diga si esta o no.
}


int main(int argc, char *argv[]) {
	int capacidad, cant_objetos;
	std::cin >> cant_objetos >> capacidad;

	int pesos[cant_objetos];
	int valores[cant_objetos];
	for (int i = 0; i < cant_objetos; i++) {
		std::cin >> pesos[i] >> valores[i];
	}

    std::cout << "capacidad: " << capacidad << std::endl
    	<< "objetos: " << cant_objetos << std::endl;
    return 0;
}

