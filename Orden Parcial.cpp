#include "operaciones.h"
#include <conio.h>

int main() {
    srand(time(NULL));
    configurarventana();
    int opc = 0;

    while (opc != 2) {
        system("cls");
        pantallaBienvenida();
        cin >> opc;

        switch (opc) {

        case 1: {
            system("cls");
            int n = 0;

            cout << "Ingrese un numero entero: ";
            cin >> n;

            vector<int> aux = generarDivisores(n);
            vector<int> A = crearSubconjunto(aux);

            // pantalla 1: divisores, subconjunto y pares
            system("cls");
            imprimirDivisores(aux, n);
            imprimirSubconjunto(A);
            relacionDivisibilidad(A);
            _getch();

            // pantalla 2: matrices
            //system("cls");
            //imprimirMatrizRelacion(A);
            //imprimirMatrizRelacionTranspuesta(A);
            //mostrarMatrizCuadrada(A);
            //_getch();

            // pantalla 3: propiedades + hasse (el hasse sale desde adentro al presionar enter)
            system("cls");
            propiedadesOrdenParcial(A);
            _getch();
            break;
        }
        case 2:
            break;
        default:
            cout << "Opcion no valida\n";
            _getch();
            break;
        }
    }
    return 0;
}