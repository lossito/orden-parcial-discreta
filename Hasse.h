#pragma once
#include <iostream>
#include <vector>
#include "Utilidades.h"
#include "Matrices.h"
#include "Impresion.h"
using namespace std;

void imprimirConexionesHasse(const vector<int>& A, const vector<vector<int>>& M3) {
    int n = A.size();
    bool primero = true;

    cout << "Conexiones que se conservan para el diagrama de Hasse:\n";
    cout << "H = { ";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M3[i][j] == 1) {
                if (!primero) {
                    cout << ", ";
                }
                cout << "(" << A[i] << "," << A[j] << ")";
                primero = false;
            }
        }
    }

    if (primero) {
        cout << "no hay conexiones directas";
    }
    cout << " }\n";
}


void imprimirDiagramaHasse(const vector<int>& A,
    const vector<vector<int>>& M3) {
    int n = A.size();
    cout << "========== DIAGRAMA DE HASSE ===========\n\n";
    imprimirConexionesHasse(A, M3);
    cout << "\nRelaciones directas (de inferior a superior), a ------- b:\n\n";

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


void mostrarHasse(const vector<int>& A) {

    vector<vector<int>> M = construirMatrizM(A);
    vector<vector<int>> M1 = construirMatrizSinDiagonal(M);
    vector<vector<int>> M2 = construirMatrizCuadrada(M1);   
    vector<vector<int>> M3 = construirMatrizHasse(M1, M2);

    system("cls");
    cout << "========== DIAGRAMA DE HASSE ==========\n\n";

    imprimirMatrizConColor(
        "Paso 1 - Matriz M1 (sin reflexividad):",
        "Se eliminan los pares (a,a) de la diagonal.",
        A, M1,
        3,
        3
    );

    imprimirMatrizConColor(
        "Paso 2 - Matriz M2 = M1 x M1:",
        "Detecta las relaciones cubiertas por un elemento intermedio.",
        A, M2,
        3,
        3
    );

    imprimirMatrizConColor(
        "Paso 3 - Matriz M3 = M1 - M2 (aristas directas):",
        "Solo quedan los pares directos sin intermediarios, las cuales son las aristas del Hasse.",
        A, M3,
        10,
        10
    );

    imprimirDiagramaHasse(A, M3);
}