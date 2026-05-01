#include <iostream>
#include <vector>
#include <iomanip>
#include "Utilidades.h"
using namespace std;

vector<int> generarDivisores(int n) {
    vector<int> divisores;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0) {
            divisores.push_back(i);
        }
    }
    return divisores;
}

void imprimirDivisores(vector<int> divisores, int n) {

    int x = 5;
    int y = 2;

    mover_cursor(x, y);

    cout << "D = { ";
    for (int i = 0; i < divisores.size(); i++)
    {
        cout << divisores[i];
        if (i != divisores.size() - 1) cout << ", ";
    }
    cout << " } ";
}

vector<int> crearSubconjunto(vector<int> divisores) {

    vector<int> A;
    int r;

    int x = 5;
    int y = 5;

    mover_cursor(x, y);
    cout << "Arma el subconjunto A:" << endl;

    for (int i = 0; i < divisores.size(); i++) {

        mover_cursor(x, y + i + 1);

        cout << "Agregar " << divisores[i] << "? (1 = si / 2 = no): ";
        cin >> r;

        if (r == 1) {
            A.push_back(divisores[i]);
        }
    }

    return A;
}

void imprimirSubconjunto(vector<int> A) {

    int x = 5;
    int y = 15;

    mover_cursor(x, y);

    cout << "__________________" << endl;

    mover_cursor(x, y + 1);
    cout << "Subcojunto A = { ";

    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i != A.size() - 1) cout << ", ";
    }

    cout << " }" << endl;

    mover_cursor(x, y + 2);
    cout << "__________________";
}

void imprimirMatrizRelacion(vector<int> A) {

    int x = 80;
    int y = 2;

    mover_cursor(x, y);

    cout << "Relacion (matriz), 1 si a divide a b:" << endl;

    mover_cursor(x, y + 1);
    cout << setw(5) << " ";

    for (int i = 0; i < A.size(); i++) {
        cout << setw(4) << A[i];
    }

    mover_cursor(x, y + 2);

    cout << "    ";

    for (int i = 0; i < A.size() * 4; i++) {
        cout << "-";
    }

    for (int i = 0; i < A.size(); i++) {

        mover_cursor(x, y + 3 + i);

        cout << setw(3) << A[i] << " |";

        for (int j = 0; j < A.size(); j++) {

            if (A[i] != 0 && A[j] % A[i] == 0) {

                if (i == j) {
                    establecer_color(3);
                    cout << setw(4) << "1";
                    establecer_color(7);
                }
                else {
                    cout << setw(4) << "1";
                }

            }
            else {
                cout << setw(4) << "0";
            }
        }
    }
}

bool verificarReflexiva(vector<int> A) {
    for (int i = 0; i < A.size(); i++) {
        if (A[i] % A[i] != 0) {
            return false;
        }
    }
    return true;
}

void relacionDivisibilidad(vector<int> A) {

    int x = 5;
    int y = 25;

    mover_cursor(x, y);

    cout << "Relacion (pares), a|b (a divide a b):" << endl;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {

            if (A[j] % A[i] == 0) {

                mover_cursor(x, y + 1);

                cout << "(" << A[i] << ", " << A[j] << ")" << endl;
                y++;
            }
        }
    }

    cout << "__________________" << endl;
}

bool hayIntermedio(int a, int b, vector<int> A) {
    for (int y = 0; y < A.size(); y++) {

        int c = A[y];

        if (c != a && c != b) {

            if (c % a == 0 && b % c == 0) {

                return true;
            }
        }
    }

    return false;
}

void mostrarHasse(vector<int> A) {

    int x = 50;
    int y = 100;   

    mover_cursor(x, y);
    cout << "Diagrama de Hasse:" << endl;

    y++;

    for (int i = 0; i < A.size(); i++) {

        for (int j = 0; j < A.size(); j++) {

            if (A[i] != A[j]) {

                if (A[j] % A[i] == 0) {

                    if (!hayIntermedio(A[i], A[j], A)) {

                        mover_cursor(x, y);
                        cout << A[i] << " ------- " << A[j] << endl;

                        y++; 
                    }
                }
            }
        }
    }
}
void propiedadesOrdenParcial(vector<int> A) {

    int x = 5;
    int y = 80;   // 👈 MOVIDO MÁS ABAJO (CLAVE)

    mover_cursor(x, y);
    cout << "\n========== PROPIEDADES DE LA RELACION ==========" << endl;

    // REFLEXIVIDAD
    mover_cursor(x, y + 1);
    cout << "\n1. RELACION REFLEXIVA" << endl;

    mover_cursor(x, y + 2);
    cout << "Una relacion R definida sobre un conjunto A es reflexiva" << endl;

    mover_cursor(x, y + 3);
    cout << "si todo elemento del conjunto se relaciona consigo mismo." << endl;

    mover_cursor(x, y + 4);
    cout << "Es decir: (a,a) pertenece a R, para todo a perteneciente a A." << endl;

    mover_cursor(x, y + 5);
    cout << "\nEn la relacion de divisibilidad, todo numero divide" << endl;

    mover_cursor(x, y + 6);
    cout << "a si mismo." << endl;

    mover_cursor(x, y + 7);
    cout << "\nEjemplos encontrados:" << endl;

    for (int i = 0; i < A.size(); i++) {
        mover_cursor(x, y + 8 + i);
        cout << "(" << A[i] << "," << A[i] << ")" << endl;
    }

    mover_cursor(x, y + 9 + A.size());
    cout << "\nPor ello, la relacion es reflexiva." << endl;


    // ANTISIMETRIA
    mover_cursor(x, y + 11 + A.size());
    cout << "\n======================================" << endl;

    mover_cursor(x, y + 12 + A.size());
    cout << "\n2. RELACION ANTISIMETRICA" << endl;

    mover_cursor(x, y + 13 + A.size());
    cout << "Una relacion R es antisimetrica si para dos elementos" << endl;

    mover_cursor(x, y + 14 + A.size());
    cout << "a y b, cuando (a,b) pertenece a R y (b,a) pertenece a R," << endl;

    mover_cursor(x, y + 15 + A.size());
    cout << "entonces necesariamente a = b." << endl;

    mover_cursor(x, y + 16 + A.size());
    cout << "\nEn la relacion de divisibilidad no pueden existir" << endl;

    mover_cursor(x, y + 17 + A.size());
    cout << "dos elementos distintos relacionados en ambos sentidos." << endl;

    mover_cursor(x, y + 18 + A.size());
    cout << "\nEjemplo:" << endl;

    mover_cursor(x, y + 19 + A.size());
    cout << "(2,4) pertenece a R porque 2 divide a 4." << endl;

    mover_cursor(x, y + 20 + A.size());
    cout << "Pero (4,2) no pertenece a R porque 4 no divide a 2." << endl;

    mover_cursor(x, y + 21 + A.size());
    cout << "\nPor ello, la relacion es antisimetrica." << endl;


    // TRANSITIVIDAD
    mover_cursor(x, y + 23 + A.size());
    cout << "\n======================================" << endl;

    mover_cursor(x, y + 24 + A.size());
    cout << "\n3. RELACION TRANSITIVA" << endl;

    mover_cursor(x, y + 25 + A.size());
    cout << "Una relacion R es transitiva si cuando" << endl;

    mover_cursor(x, y + 26 + A.size());
    cout << "(a,b) pertenece a R y (b,c) pertenece a R," << endl;

    mover_cursor(x, y + 27 + A.size());
    cout << "entonces (a,c) tambien pertenece a R." << endl;

    mover_cursor(x, y + 28 + A.size());
    cout << "\nEn la relacion de divisibilidad:" << endl;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            for (int k = 0; k < A.size(); k++) {

                if (A[j] % A[i] == 0 && A[k] % A[j] == 0) {

                    mover_cursor(x, y + 29 + A.size());
                    cout << A[i] << " divide a " << A[j];

                    mover_cursor(x, y + 30 + A.size());
                    cout << " y " << A[j] << " divide a " << A[k];

                    mover_cursor(x, y + 31 + A.size());
                    cout << ", entonces ";

                    mover_cursor(x, y + 32 + A.size());
                    cout << A[i] << " divide a " << A[k] << endl;
                }
            }
        }
    }

    mover_cursor(x, y + 34 + A.size());
    cout << "\nPor ello, la relacion es transitiva." << endl;


    // ORDEN PARCIAL
    mover_cursor(x, y + 36 + A.size());
    cout << "\n======================================" << endl;

    mover_cursor(x, y + 37 + A.size());
    cout << "\n4. RELACION DE ORDEN PARCIAL" << endl;

    mover_cursor(x, y + 38 + A.size());
    cout << "Como la relacion cumple reflexividad," << endl;

    mover_cursor(x, y + 39 + A.size());
    cout << "antisimetria y transitividad," << endl;

    mover_cursor(x, y + 40 + A.size());
    cout << "entonces la relacion de divisibilidad" << endl;

    mover_cursor(x, y + 41 + A.size());
    cout << "es una relacion de orden parcial." << endl;
}