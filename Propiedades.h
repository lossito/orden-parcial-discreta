#pragma once
#include <iostream>
#include <vector>
#include "Utilidades.h"
#include "Matrices.h"
#include "Impresion.h"
using namespace std;

// ============================================================
//  PROPIEDADES DE ORDEN PARCIAL
//  Cada funcion verifica UNA propiedad y la explica en pantalla.
// ============================================================

// ------------------------------------------------------------------
// Verifica y muestra la propiedad REFLEXIVA
// Una relacion es reflexiva si (a,a) pertenece a R para todo a en A.
// En divisibilidad: a|a siempre es verdadero => siempre reflexiva.
// ------------------------------------------------------------------
void mostrarReflexividad(const vector<int>& A, const vector<vector<int>>& M) {
    int n = A.size();

    cout << "1. RELACION REFLEXIVA\n";
    cout << "Una relacion R es reflexiva si todo elemento\n";
    cout << "se relaciona consigo mismo: (a,a) pertenece a R.\n\n";

    cout << "Pares encontrados:\n";
    for (int i = 0; i < n; i++)
        cout << "  (" << A[i] << "," << A[i] << ")\n";

    establecer_color(10);
    cout << "=> La relacion ES reflexiva.\n";
    establecer_color(7);

    // Muestra la matriz M con la diagonal coloreada en verde
    imprimirMatrizConColor(
        "\nMatriz de D:", "",
        A, M,
        /*colorDiagonal=*/3,   // verde: resalta (a,a)
        /*colorFuera=*/7
    );

    cout << "\n----------------------------------------------\n\n";
}

// ------------------------------------------------------------------
// Verifica y muestra la propiedad ANTISIMETRICA
// R es antisimetrica si (a,b) en R y (b,a) en R => a == b.
// ------------------------------------------------------------------
void mostrarAntisimetria(const vector<int>& A, const vector<vector<int>>& M, const vector<vector<int>>& MT) {
    int n = A.size();

    cout << "2. RELACION ANTISIMETRICA\n";
    cout << "R es antisimetrica si cuando (a,b)\n";
    cout << "esta en R, entonces (b,a) no esta, a menos que a = b.\n\n";

    bool antisim = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i] == A[j]) continue;
            if (A[j] % A[i] == 0 && A[i] % A[j] == 0) {
                antisim = false;
                cout << "  (" << A[i] << "," << A[j] << ") esta en R y ("
                    << A[j] << "," << A[i] << ") tambien lo esta. rompen la regla\n";
            }
            else if (A[j] % A[i] == 0) {
                cout << "  (" << A[i] << "," << A[j] << ") esta en R, pero ("
                    << A[j] << "," << A[i] << ") no esta en R.\n";
            }
        }
    }

    if (antisim) { establecer_color(10); cout << "=> La relacion ES antisimetrica.\n"; }
    else { establecer_color(4);  cout << "=> La relacion NO es antisimetrica.\n"; }
    establecer_color(7);

    imprimirMatrizConColor(
        "\nMatriz de D:", "",
        A, M,
        /*colorDiagonal=*/7,  // verde: diagonal
        /*colorFuera=*/5      // normal: fuera de diagonal
    );

    // Muestra la transpuesta: los 1s fuera de diagonal en amarillo
    imprimirMatrizConColor(
        "\nMatriz transpuesta de D:", "",
        A, MT,
        /*colorDiagonal=*/7,   // diagonal: sin color especial
        /*colorFuera=*/5       // amarillo: resalta transposicion
    );

    cout << "Para que sea antisimetrica, la interseccion entre la matriz original D" << endl; 
    cout << "y su transpuesta, debe estar incluida solo la diagonal de la matriz D\n";

    cout << "\n----------------------------------------------\n\n";
}

void mostrarTransitividad(const vector<int>& A, const vector<vector<int>>& M, const vector<vector<int>>& M2) {
    int n = A.size();

    cout << "3. RELACION TRANSITIVA\n";
    cout << "R es transitiva si cuando (a,b) y (b,c) estan en R,\n";
    cout << "entonces (a,c) tambien esta en R.\n\n";

    // Muestra cada cadena transitiva encontrada
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (M[i][j] == 1 && M[j][k] == 1)
                    if (i != j && j != k && i != k) {
                        cout << "  " << A[i] << "|" << A[j]
                            << " y " << A[j] << "|" << A[k]
                            << " => " << A[i] << "|" << A[k] << "\n";
                    }
    // Comprueba si M2 esta contenida en M
    bool transitiva = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (M2[i][j] == 1 && M[i][j] == 0)
                transitiva = false;

    if (transitiva) { establecer_color(10); cout << "=> La relacion ES transitiva.\n"; }
    else { establecer_color(4);  cout << "=> La relacion NO es transitiva.\n"; }
    establecer_color(7);

    imprimirMatrizConColor(
        "\nMatriz de D:", "",
        A, M,
        /*colorDiagonal=*/7,  // verde: diagonal
        /*colorFuera=*/9      // normal: fuera de diagonal
    );

    // Muestra M^2 sin colores especiales
    imprimirMatrizConColor(
        "\nProducto booleando de la Matriz (MxM):", "",
        A, M2,
        /*colorDiagonal=*/7,
        /*colorFuera=*/9
    );
    cout << (transitiva
        ? "=> M2 no pierde 0 de M -> ES transitiva\n"
        : "=> M2 pierde 0 de M -> NO es transitiva\n");

    cout << "\n----------------------------------------------\n\n";
}

// ------------------------------------------------------------------
// Muestra la conclusion de orden parcial y espera una tecla
// para continuar al diagrama de Hasse.
// ------------------------------------------------------------------
void mostrarConclusionOrdenParcial() {
    cout << "4. ORDEN PARCIAL\n";
    cout << "Como cumple reflexividad, antisimetria y transitividad,\n";
    cout << "la relacion de divisibilidad ES de orden parcial.\n\n";
    cout << "Presiona una tecla para ver el Diagrama de Hasse...\n";
}