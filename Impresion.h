#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Utilidades.h"
using namespace std;

void imprimirDivisores(const vector<int>& divisores, int n) {
    cout << "D(" << n << ") = { ";
    for (int i = 0; i < (int)divisores.size(); i++) {
        cout << divisores[i];
        if (i != (int)divisores.size() - 1) cout << ", ";
    }
    cout << " }\n";
}

void imprimirCredits() {
    system("cls");
    cout << "-Piero Andre Burgos Duncan\n";
    cout << "-Jose Francisco Panuera Villanueva\n";
    cout << "-Yamil Saha Rojas Romani\n";
    cout << "-Robert Francisco Ramos Poma\n";
    cout << "-Gabriel Eduardo Dean Parodi (Nazca)\n";
    cout << "-Carlos Andres Espejo Cordova\n";
}

void imprimirSubconjunto(const vector<int>& A) {
    cout << "\n__________________\n";
    cout << "Subconjunto D = { ";
    for (int i = 0; i < (int)A.size(); i++) {
        cout << A[i];
        if (i != (int)A.size() - 1) cout << ", ";
    }
    cout << " }\n";
    cout << "__________________\n";
}

void imprimirParesRelacion(const vector<int>& A) {
    cout << "\nRelacion (pares), a|b (a divide a b):\n";
    for (int i = 0; i < (int)A.size(); i++)
        for (int j = 0; j < (int)A.size(); j++)
            if (A[j] % A[i] == 0)
                cout << "(" << A[i] << ", " << A[j] << ")\n";
    cout << "__________________\n";
}

void imprimirEncabezadoMatriz(const vector<int>& A) {
    int n = A.size();
    cout << setw(5) << " ";
    for (int i = 0; i < n; i++) cout << setw(4) << A[i];
    cout << "\n    ";
    for (int i = 0; i < n * 4; i++) cout << "-";
    cout << "\n";
}


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