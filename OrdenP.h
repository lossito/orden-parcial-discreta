#pragma once
#include "Divisores.h"
#include "Impresion.h"
#include "Propiedades.h"
#include "Hasse.h"
void ejecutarOrdenParcial() {
    system("cls");
    int n = leerEnteroPositivo("Ingrese un numero natural: ");


    vector<int> divisores = generarDivisores(n);
    vector<int> A = crearSubconjunto(divisores);

    system("cls");
    imprimirDivisores(divisores, n);
    imprimirSubconjunto(A);
    imprimirParesRelacion(A);
    _getch();

    vector<vector<int>> M = construirMatrizM(A);
    vector<vector<int>> MT = construirMatrizTranspuesta(M);
    vector<vector<int>> M2 = construirMatrizCuadrada(M);

    system("cls");
    cout << "========== PROPIEDADES DE LA RELACION ==========\n\n";

    mostrarReflexividad(A, M);
    mostrarAntisimetria(A, M, MT);
    mostrarTransitividad(A, M, M2);
    mostrarConclusionOrdenParcial();

    _getch();

    mostrarHasse(A);
    _getch();
}
