#pragma once
#include "Divisores.h"
#include "Impresion.h"
#include "Propiedades.h"
#include "Hasse.h"
void ejecutarOrdenParcial() {
    system("cls");
    int n = 0;
    do
    {
        cout << "Ingrese un numero natural: ";
        cin >> n;
    } while (n <= 0);

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
    mostrarAntisimetria(A, M, MT);
    mostrarTransitividad(A, M, M2);
    mostrarConclusionOrdenParcial();

    _getch();

    // --- Pantalla 3: diagrama de Hasse ---
    mostrarHasse(A);
    _getch();
}
