#pragma once
#include <iostream>
#include <vector>
using namespace std;

vector<int> generarDivisores(int n) {
    vector<int> divisores;
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            divisores.push_back(i);
    return divisores;
}


vector<int> crearSubconjunto(const vector<int>& divisores) {
    vector<int> A;
    int respuesta;

    cout << "\nArma el subconjunto D:\n";
    for (int div : divisores) {
        cout << "Agregar " << div << "? (1 = si / 2 = no): ";
        respuesta = leerEnteroPositivo("");
        if (respuesta == 1)
            A.push_back(div);
    }
    return A;
}