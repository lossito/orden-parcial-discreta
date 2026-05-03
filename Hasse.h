#pragma once
#include <iostream>
#include <vector>
#include "Utilidades.h"
#include "Matrices.h"
#include "Impresion.h"
using namespace std;

// ============================================================
//  DIAGRAMA DE HASSE
//  Construye el diagrama paso a paso usando tres matrices:
//    M1 = M sin diagonal (relacion irreflexiva)
//    M2 = M1 x M1       (pares con intermediario)
//    M3 = M1 - M2        (aristas directas = el Hasse)
// ============================================================

// Imprime el diagrama de Hasse final a partir de la matriz de aristas M3
void imprimirDiagramaHasse(const vector<int>& A,
    const vector<vector<int>>& M3) {
    int n = A.size();
    cout << "========== DIAGRAMA DE HASSE ==========\n";
    cout << "Relaciones directas (sin intermediarios), a ------- b:\n\n";

    bool hayArista = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M3[i][j] == 1) {
                establecer_color(10);  cout << "  " << A[i];
                establecer_color(7);   cout << " ------- ";
                establecer_color(10);  cout << A[j] << "\n";
                establecer_color(7);
                hayArista = true;
            }
        }
    }
    if (!hayArista)
        cout << "  (no hay aristas - todos los elementos son incomparables)\n";
    cout << "\n";
}

// Muestra el proceso completo del diagrama de Hasse:
//   Paso 1 -> M1  (quitar diagonal)
//   Paso 2 -> M2  (composicion: detecta intermediarios)
//   Paso 3 -> M3  (aristas directas)
//   Final  -> diagrama de relaciones
void mostrarHasse(const vector<int>& A) {
    // Construir matrices necesarias
    vector<vector<int>> M = construirMatrizM(A);
    vector<vector<int>> M1 = construirMatrizSinDiagonal(M);
    vector<vector<int>> M2 = construirMatrizCuadrada(M1);   // M1 x M1
    vector<vector<int>> M3 = construirMatrizHasse(M1, M2);

    system("cls");
    cout << "========== DIAGRAMA DE HASSE (paso a paso) ==========\n\n";

    // Paso 1: M1 - se eliminan los pares (a,a)
    imprimirMatrizConColor(
        "Paso 1 - Matriz M1 (sin reflexividad):",
        "Se eliminan los pares (a,a) de la diagonal (relacion irreflexiva).",
        A, M1,
        /*colorDiagonal=*/3,
        /*colorFuera=*/3
    );

    // Paso 2: M2 = M1 x M1 - detecta pares con intermediario
    imprimirMatrizConColor(
        "Paso 2 - Matriz M2 = M1 x M1 (composicion):",
        "Detecta las relaciones cubiertas por un paso intermedio.",
        A, M2,
        /*colorDiagonal=*/5,
        /*colorFuera=*/5
    );

    // Paso 3: M3 = M1 - M2 - solo aristas directas del Hasse
    imprimirMatrizConColor(
        "Paso 3 - Matriz M3 = M1 - M2 (aristas directas):",
        "Solo quedan los pares directos sin intermediarios: estas son las aristas del Hasse.",
        A, M3,
        /*colorDiagonal=*/10,
        /*colorFuera=*/10
    );

    // Diagrama final
    imprimirDiagramaHasse(A, M3);
}