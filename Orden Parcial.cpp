#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "Menu.h"
#include "Divisores.h"
#include "Matrices.h"
#include "Impresion.h"
#include "Propiedades.h"
#include "OrdenP.h"
#include "Hasse.h"

int main() {
    srand(time(NULL));
    configurarventana();

    int opcion = 0;

    while (opcion != 3) {
        system("cls");
        pantallaBienvenida();
        cin >> opcion;

        switch (opcion) {
        case 1:
            ejecutarOrdenParcial();
            break;

        case 2:
            // Opcion Salir: el bucle termina
            break;

        case 3:
            break;

        default:
            cout << "Opcion no valida\n";
            _getch();
            break;
        }
    }

    return 0;
}