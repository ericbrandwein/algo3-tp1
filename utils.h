struct item {
	int peso;
	int valor;
	item(int peso, int valor): peso(peso), valor(valor) {} 
};

vector<item> parsear_entrada(int* capacidad, int* cant_items);