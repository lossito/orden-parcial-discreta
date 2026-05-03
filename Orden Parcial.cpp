// ============================================================
//  ORDEN PARCIAL - PROGRAMA PRINCIPAL
//
//  Estructura de archivos:
//    Utilidades.h   -> colores, cursor, ventana (Windows API)
//    Divisores.h    -> generarDivisores, crearSubconjunto
//    Matrices.h     -> construccion de matrices M, MT, M^2, Hasse
//    Impresion.h    -> funciones de impresion en consola
//    Propiedades.h  -> reflexividad, antisimetria, transitividad
//    Hasse.h        -> diagrama de Hasse paso a paso
//    Menu.h         -> pantalla de bienvenida y animacion
// ============================================================

#include <conio.h>
#include <cstdlib>
#include <ctime>
#include "Menu.h"
#include "Divisores.h"
#include "Matrices.h"
#include "Impresion.h"
#include "Propiedades.h"
#include "Hasse.h"

// ------------------------------------------------------------------
// Flujo principal de la opcion "Empezar orden parcial":
//   1. Pide el numero n y genera sus divisores
//   2. El usuario arma el subconjunto A
//   3. Pantalla 1: muestra divisores, subconjunto y pares
//   4. Pantalla 2: muestra las tres propiedades + conclusion
//   5. Pantalla 3: diagrama de Hasse paso a paso
// ------------------------------------------------------------------
void ejecutarOrdenParcial() {
    system("cls");

    // --- Entrada de datos ---
    int n = 0;
    cout << "Ingrese un numero entero: ";
    cin >> n;

    vector<int> divisores = generarDivisores(n);
    vector<int> A = crearSubconjunto(divisores);

    // --- Pantalla 1: divisores, subconjunto y pares de la relacion ---
    system("cls");
    imprimirDivisores(divisores, n);
    imprimirSubconjunto(A);
    imprimirParesRelacion(A);
    _getch();

    // --- Calcular matrices una sola vez para reutilizarlas ---
    vector<vector<int>> M = construirMatrizM(A);
    vector<vector<int>> MT = construirMatrizTranspuesta(M);
    vector<vector<int>> M2 = construirMatrizCuadrada(M);

    // --- Pantalla 2: propiedades de orden parcial ---
    system("cls");
    cout << "========== PROPIEDADES DE LA RELACION ==========\n\n";

    mostrarReflexividad(A, M);
    mostrarAntisimetria(A, MT);
    mostrarTransitividad(A, M, M2);
    mostrarConclusionOrdenParcial();

    _getch();

    // --- Pantalla 3: diagrama de Hasse ---
    mostrarHasse(A);
    _getch();
}

// ------------------------------------------------------------------
// Punto de entrada del programa
// ------------------------------------------------------------------
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