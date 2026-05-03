#pragma once
#include <iostream>
#include <vector>
using namespace std;

// ============================================================
//  DIVISORES Y SUBCONJUNTOS
//  Logica pura de conjuntos: sin salida de matrices ni colores.
// ============================================================

// Devuelve todos los divisores de n en orden ascendente
vector<int> generarDivisores(int n) {
    vector<int> divisores;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            divisores.push_back(i);
    return divisores;
}

// Permite al usuario elegir interactivamente que divisores
// forman el subconjunto A (responde 1=si / 2=no)
vector<int> crearSubconjunto(const vector<int>& divisores) {
    vector<int> A;
    int respuesta;

    cout << "\nArma el subconjunto A:\n";
    for (int div : divisores) {
        cout << "Agregar " << div << "? (1 = si / 2 = no): ";
        cin >> respuesta;
        if (respuesta == 1)
            A.push_back(div);
    }
    return A;
}