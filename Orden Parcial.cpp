#include "operaciones.h"
int main() {
	int opc = 0;
	while (opc != 2)
	{
		cout << "--Bienvenido al mvp del tb1--\n";
		cout << "1. Empezar orden parcial\n";
		cout << "2. Salir\n";
		cout << "Opcion: ";
		cin >> opc;
		switch (opc) {
			case 1: {
				int n = 0;
				cout << "Ingrese un numero entero: ";
				cin >> n;
				vector<int> generarDivisores(n);
				imprimirDivisores(n, generarDivisores);
				break;
			}
			case 2: {
				break;
			}
			default: {
				cout << "Opcion no valida\n";
				break;
			}

		}
	}
}