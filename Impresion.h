#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Utilidades.h"
using namespace std;

// ============================================================
//  IMPRESION EN CONSOLA
//  Cada funcion tiene una unica responsabilidad: mostrar algo.
// ============================================================

// Imprime el conjunto de divisores: D(n) = { 1, 2, ... }
void imprimirDivisores(const vector<int>& divisores, int n) {
    cout << "D(" << n << ") = { ";
    for (int i = 0; i < (int)divisores.size(); i++) {
        cout << divisores[i];
        if (i != (int)divisores.size() - 1) cout << ", ";
    }
    cout << " }\n";
}

// Imprime el subconjunto A seleccionado por el usuario
void imprimirSubconjunto(const vector<int>& A) {
    cout << "\n__________________\n";
    cout << "Subconjunto A = { ";
    for (int i = 0; i < (int)A.size(); i++) {
        cout << A[i];
        if (i != (int)A.size() - 1) cout << ", ";
    }
    cout << " }\n";
    cout << "__________________\n";
}

// Imprime todos los pares (a, b) de la relacion de divisibilidad
void imprimirParesRelacion(const vector<int>& A) {
    cout << "\nRelacion (pares), a|b (a divide a b):\n";
    for (int i = 0; i < (int)A.size(); i++)
        for (int j = 0; j < (int)A.size(); j++)
            if (A[j] % A[i] == 0)
                cout << "(" << A[i] << ", " << A[j] << ")\n";
    cout << "__________________\n";
}

// Imprime el encabezado de una matriz (fila de etiquetas y linea separadora)
void imprimirEncabezadoMatriz(const vector<int>& A) {
    int n = A.size();
    cout << setw(5) << " ";
    for (int i = 0; i < n; i++) cout << setw(4) << A[i];
    cout << "\n    ";
    for (int i = 0; i < n * 4; i++) cout << "-";
    cout << "\n";
}

// Imprime una matriz generica con un color opcional para los 1s
// colorDiagonal : color para los 1s en la diagonal principal
// colorFuera    : color para los 1s fuera de la diagonal (-1 = sin color especial)
void imprimirMatrizConColor(const string& titulo, const string& descripcion,
    const vector<int>& A,
    const vector<vector<int>>& Mat,
    int colorDiagonal, int colorFuera) {
    int n = A.size();
    cout << titulo << "\n";
    if (!descripcion.empty()) cout << descripcion << "\n\n";

    imprimirEncabezadoMatriz(A);

    for (int i = 0; i < n; i++) {
        cout << setw(3) << A[i] << " |";
        for (int j = 0; j < n; j++) {
            if (Mat[i][j] == 1) {
                int color = (i == j) ? colorDiagonal : colorFuera;
                if (color != -1) establecer_color(color);
                cout << setw(4) << "1";
                if (color != -1) establecer_color(7);
            }
            else {
                cout << setw(4) << "0";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

// Imprime el banner ASCII del titulo "ORDEN PARCIAL" con el color indicado
void imprimirTituloOrdenParcial(int color) {
    establecer_color(color);
    cout << " _____   ____    ____    ____    __  __     \n";
    cout << "/\\  __`\\/\\  _`\\ /\\  _`\\ /\\  _`\\ /\\ \\/\\ \\    \n";
    cout << "\\ \\ \\/\\ \\ \\ \\L\\ \\ \\ \\/\\ \\ \\ \\L\\_\\ \\ `\\\\ \\   \n";
    cout << " \\ \\ \\ \\ \\ \\ ,  /\\ \\ \\ \\ \\ \\  _\\L\\ \\ , ` \\  \n";
    cout << "  \\ \\ \\_\\ \\ \\ \\\\ \\\\ \\ \\_\\ \\ \\ \\L\\ \\ \\ \\`\\ \\ \n";
    cout << "   \\ \\_____\\ \\_\\ \\_\\ \\____/\\ \\____/\\ \\_\\ \\_\\\n";
    cout << "    \\/_____/\\/_/\\/ /\\/___/  \\/___/  \\/_/\\/_/\n";
    cout << "\n";
    cout << " ____    ______  ____    ____    ______   ______  __        \n";
    cout << "/\\  _`\\ /\\  _  \\/\\  _`\\ /\\  _`\\ /\\__  _\\ /\\  _  \\/\\ \\       \n";
    cout << "\\ \\ \\L\\ \\ \\ \\L\\ \\ \\ \\L\\ \\ \\ \\/\\_\\/_/\\ \\/ \\ \\ \\L\\ \\ \\ \\      \n";
    cout << " \\ \\ ,__/\\ \\  __ \\ \\ ,  /\\ \\ \\/_/_ \\ \\ \\  \\ \\  __ \\ \\ \\  __ \n";
    cout << "  \\ \\ \\/  \\ \\ \\/\\ \\ \\ \\\\ \\\\ \\ \\L\\ \\ \\_\\ \\__\\ \\ \\/\\ \\ \\ \\L\\ \\\n";
    cout << "   \\ \\_\\   \\ \\_\\ \\_\\ \\_\\ \\_\\ \\____/ /\\_____\\\\ \\_\\ \\_\\ \\____/\n";
    cout << "    \\/_/    \\/_/\\/_/\\/_/\\/ /\\/___/  \\/_____/ \\/_/\\/_/\\/___/ \n";
    cout << "\n";
    establecer_color(7);
}