#include <iostream>
#include <vector>
#include <iomanip>
#include "Utilidades.h"
using namespace std;

vector<int> generarDivisores(int n) {
    vector<int> divisores;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisores.push_back(i);
        }
    }
    return divisores;
}

void imprimirDivisores(vector<int> divisores, int n) {
    int x = 3;
    int y = 2;

    mover_cursor(x, y);
    cout << "D = { ";
    for (int i = 0; i < (int)divisores.size(); i++) {
        cout << divisores[i];
        if (i != (int)divisores.size() - 1) cout << ", ";
    }
    cout << " }   ";
}

vector<int> crearSubconjunto(vector<int> divisores) {
    vector<int> A;
    int r;

    int x = 3;
    int y = 4;

    mover_cursor(x, y);
    cout << "Arma el subconjunto A:";

    for (int i = 0; i < (int)divisores.size(); i++) {
        mover_cursor(x, y + 1 + i);
        cout << "Agregar " << divisores[i] << "? (1 = si / 2 = no): ";
        cin >> r;
        if (r == 1) {
            A.push_back(divisores[i]);
        }
    }

    return A;
}

void imprimirSubconjunto(vector<int> A) {
    int x = 3;
    int y = 20;

    mover_cursor(x, y);
    cout << "__________________";

    mover_cursor(x, y + 1);
    cout << "Subcojunto A = { ";
    for (int i = 0; i < (int)A.size(); i++) {
        cout << A[i];
        if (i != (int)A.size() - 1) cout << ", ";
    }
    cout << " }";

    mover_cursor(x, y + 2);
    cout << "__________________";
}

void imprimirMatrizRelacion(vector<int> A) {
    int x = 55;
    int y = 2;

    mover_cursor(x, y);
    cout << "Relacion (matriz), 1 si a divide a b:";

    mover_cursor(x, y + 1);
    cout << setw(5) << " ";
    for (int i = 0; i < (int)A.size(); i++) {
        cout << setw(4) << A[i];
    }

    mover_cursor(x, y + 2);
    cout << "    ";
    for (int i = 0; i < (int)A.size() * 4; i++) {
        cout << "-";
    }

    for (int i = 0; i < (int)A.size(); i++) {
        mover_cursor(x, y + 3 + i);
        cout << setw(3) << A[i] << " |";

        for (int j = 0; j < (int)A.size(); j++) {
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
void imprimirMatrizRelacionTranspuesta(vector<int> A) {
    int x = 55;
    int y = 2;

    mover_cursor(x, y);
    cout << "Matriz Transpuesta:";

    mover_cursor(x, y + 1);
    cout << setw(5) << " ";
    for (int i = 0; i < (int)A.size(); i++) {
        cout << setw(4) << A[i];
    }

    mover_cursor(x, y + 2);
    cout << "    ";
    for (int i = 0; i < (int)A.size() * 4; i++) {
        cout << "-";
    }

    for (int i = 0; i < (int)A.size(); i++) {
        mover_cursor(x, y + 3 + i);
        cout << setw(3) << A[i] << " |";

        for (int j = 0; j < (int)A.size(); j++) {

      
            if (A[j] != 0 && A[i] % A[j] == 0){
                if (i == j) {
                    establecer_color(5);
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
    cout << "Esta matriz afirma que la relacion es antisimetrica" << endl;
}
bool verificarReflexiva(vector<int> A) {
    for (int i = 0; i < (int)A.size(); i++) {
        if (A[i] % A[i] != 0) return false;
    }
    return true;
}

void relacionDivisibilidad(vector<int> A) {
    int x = 3;
    int y = 24;

    mover_cursor(x, y);
    cout << "Relacion (pares), a|b (a divide a b):";

    int fila = y + 1;
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)A.size(); j++) {
            if (A[j] % A[i] == 0) {
                mover_cursor(x, fila);
                cout << "(" << A[i] << ", " << A[j] << ")   ";
                fila++;
            }
        }
    }

    mover_cursor(x, fila);
    cout << "__________________";
}

bool hayIntermedio(int a, int b, vector<int> A) {
    for (int y = 0; y < (int)A.size(); y++) {
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
    int x = 70;
    int y = 30;

    mover_cursor(x, y);
    cout << "Diagrama de Hasse:";

    int fila = y + 1;
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)A.size(); j++) {
            if (A[i] != A[j] && A[j] % A[i] == 0) {
                if (!hayIntermedio(A[i], A[j], A)) {
                    mover_cursor(x, fila);
                    cout << A[i] << " ------- " << A[j] << "   ";
                    fila++;
                }
            }
        }
    }
}

void propiedadesOrdenParcial(vector<int> A) {

    cout << "\n========== PROPIEDADES DE LA RELACION ==========\n";

    // REFLEXIVIDAD
    cout << "\n1. RELACION REFLEXIVA\n";
    cout << "Una relacion R definida sobre un conjunto A es reflexiva\n";
    cout << "si todo elemento del conjunto se relaciona consigo mismo.\n";
    cout << "Es decir: (a,a) pertenece a R, para todo a perteneciente a A.\n";
    cout << "\nEn la relacion de divisibilidad, todo numero divide a si mismo.\n";
    cout << "\nEjemplos encontrados:\n";
    for (int i = 0; i < (int)A.size(); i++) {
        cout << "(" << A[i] << "," << A[i] << ")\n";
    }
    cout << "\nPor ello, la relacion es reflexiva.\n";

    
   //  2. ANTISIMETRIA 
    cout << "----------------------------------------------" << endl;
    cout << "2. RELACION ANTISIMETRICA" << endl;

    cout << "R es antisimetrica si cuando (a,b) y (b,a)" << endl;
    cout << "estan en R, entonces a = b." << endl;
    cout << "A = { ";
    for (int i = 0; i < (int)A.size(); i++) {
        cout << A[i];
        if (i != (int)A.size() - 1) cout << ", ";
    }
    cout << " }" << endl;

    bool esAntisimetrica = true;

    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)A.size(); j++) {

            if (A[i] != A[j]) {

                if (A[j] % A[i] == 0 && A[i] % A[j] == 0) {

                    esAntisimetrica = false;

                    cout << "(" << A[i] << "," << A[j] << ") y ("
                        << A[j] << "," << A[i] << ") en R pero "
                        << A[i] << " != " << A[j] << " -> no cumple" << endl;
                }
                else if (A[j] % A[i] == 0) {

                    cout << "(" << A[i] << "," << A[j] << ") en R" << endl;
                }
            }
        }
    }
  
    if (esAntisimetrica) {
        cout << "=> Ningun par rompe la regla, asi que si antisimetrica." << endl;
    }
    else 
    {
        cout << "=> Existen pares que rompen la regla: no es antisimetrica." << endl;
    }

    // TRANSITIVIDAD
    cout << "\n======================================\n";
    cout << "\n3. RELACION TRANSITIVA\n";
    cout << "Una relacion R es transitiva si cuando\n";
    cout << "(a,b) pertenece a R y (b,c) pertenece a R,\n";
    cout << "entonces (a,c) tambien pertenece a R.\n";
    cout << "\nEn la relacion de divisibilidad:\n";

    for (int i = 0; i < (int)A.size(); i++) {
       
        for (int j = 0; j < (int)A.size(); j++) {
            for (int k = 0; k < (int)A.size(); k++) {
                if (A[j] % A[i] == 0 && A[k] % A[j] == 0) {
                    cout << A[i] << " divide a " << A[j]   << " y " << A[j] << " divide a " << A[k] << ", entonces " << A[i] << " divide a " << A[k] << endl;
                }
            }
        }
    }
    cout << "\nPor ello, la relacion es transitiva.\n";

    // ORDEN PARCIAL
    cout << "\n======================================\n";
    cout << "\n4. RELACION DE ORDEN PARCIAL\n";
    cout << "Como la relacion cumple reflexividad, antisimetria\n";
    cout << "y transitividad, la relacion de divisibilidad\n";
    cout << "es una relacion de orden parcial.\n";
}
