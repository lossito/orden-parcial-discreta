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
        "\nMatriz M (1 si a divide a b):", "",
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
void mostrarAntisimetria(const vector<int>& A,
    const vector<vector<int>>& MT) {
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
                cout << "  (" << A[i] << "," << A[j] << ") y ("
                    << A[j] << "," << A[i] << ") rompen la regla\n";
            }
            else if (A[j] % A[i] == 0) {
                cout << "  (" << A[i] << "," << A[j] << ") en R\n";
            }
        }
    }

    if (antisim) { establecer_color(10); cout << "=> La relacion ES antisimetrica.\n"; }
    else { establecer_color(4);  cout << "=> La relacion NO es antisimetrica.\n"; }
    establecer_color(7);

    // Muestra la transpuesta: los 1s fuera de diagonal en amarillo
    imprimirMatrizConColor(
        "\nMatriz Transpuesta M^T:", "",
        A, MT,
        /*colorDiagonal=*/7,   // diagonal: sin color especial
        /*colorFuera=*/5       // amarillo: resalta transposicion
    );

    cout << "\n----------------------------------------------\n\n";
}

// ------------------------------------------------------------------
// Verifica y muestra la propiedad TRANSITIVA
// R es transitiva si (a,b) en R y (b,c) en R => (a,c) en R.
// Se verifica con M^2: si M2[i][j]=1 entonces M[i][j] debe ser 1.
// ------------------------------------------------------------------
void mostrarTransitividad(const vector<int>& A,
    const vector<vector<int>>& M,
    const vector<vector<int>>& M2) {
    int n = A.size();

    cout << "3. RELACION TRANSITIVA\n";
    cout << "R es transitiva si cuando (a,b) y (b,c) estan en R,\n";
    cout << "entonces (a,c) tambien esta en R.\n\n";

    // Muestra cada cadena transitiva encontrada
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (M[i][j] == 1 && M[j][k] == 1)
                    cout << "  " << A[i] << "|" << A[j]
                    << " y " << A[j] << "|" << A[k]
                    << " => " << A[i] << "|" << A[k] << "\n";

    // Comprueba si M2 esta contenida en M
    bool transitiva = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (M2[i][j] == 1 && M[i][j] == 0)
                transitiva = false;

    if (transitiva) { establecer_color(10); cout << "=> La relacion ES transitiva.\n"; }
    else { establecer_color(4);  cout << "=> La relacion NO es transitiva.\n"; }
    establecer_color(7);

    // Muestra M^2 sin colores especiales
    imprimirMatrizConColor(
        "\nMatriz M2 (M al cuadrado):", "",
        A, M2,
        /*colorDiagonal=*/7,
        /*colorFuera=*/7
    );
    cout << (transitiva
        ? "=> M2 contenida en M -> ES transitiva\n"
        : "=> M2 NO contenida en M -> NO es transitiva\n");

    cout << "\n----------------------------------------------\n\n";
}

// ------------------------------------------------------------------
// Muestra la conclusion de orden parcial y espera una tecla
// para continuar al diagrama de Hasse.
// ------------------------------------------------------------------
void mostrarConclusionOrdenParcial() {
    cout << "4. ORDEN PARCIAL\n";
    cout << "Como cumple reflexividad, antisimetria y transitividad,\n";
    cout << "la relacion de divisibilidad ES un orden parcial.\n\n";
    cout << "Presiona una tecla para ver el Diagrama de Hasse...\n";
}