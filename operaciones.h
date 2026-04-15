#include <iostream>
#include <vector>
#include <iomanip>
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

//vector<int> crearSubconjunto(int n, vector<int> divisores) {}

void imprimirDivisores(vector<int> divisores, int n) {
    cout << "D = { ";
    for (auto i : divisores)
    {
        cout << i;
		if (i != n) cout << ", ";
    } 
    cout << " } ";
}

vector<int> crearSubconjunto(vector<int> divisores) {
    vector<int> A;
    int r;

    cout << "Arma el subconjunto A:" << endl;

    for (int i = 0; i < divisores.size(); i++) {
        cout << "Agregar " << divisores[i] << "? (1 = si / 2 = no): ";
        cin >> r;

        if (r == 1) {
            A.push_back(divisores[i]);
        }
        //Faltaria validad si no es 1 ni 2
    }

    return A;
}

void imprimirSubconjunto(vector<int> A) {
    cout << "__________________" << endl;
    cout << "Subcojunto A = { ";
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i != A.size() - 1) cout << ", ";
    }
    cout << " }" << endl;
    cout << "__________________" << endl;
}

void imprimirMatrizRelacion(vector<int> A) {
    cout << "Relacion (matriz), 1 si a divide a b:" << endl;
	cout << setw(6) << " "; //le puse un espacio extra para que se vea bien, nose pq no funciona el setw(7) lol
    for (int i = 0; i < A.size(); i++) { 
        cout << setw(5) << A[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < A.size(); i++) {
        cout << setw(5) << A[i] << " ";
        for (int j = 0; j < A.size(); j++) {
            if (A[j] % A[i] == 0) {
                cout << setw(5) << "1" << " ";
            } else {
                cout << setw(5) << "0" << " ";
            }
        }
        cout << endl;
    }
    cout << endl;
}


bool verificarReflexiva(vector<int> A) {
    for (int i = 0; i < A.size(); i++) {
        if (A[i] % A[i] != 0) {
            return false;
        }
    }
    return true;
}


//Esto es el punto 4.1, representar la relacion mediante pares ordenados
void relacionDivisibilidad(vector<int> A) {
    cout << "Relacion (pares), a|b (a divide a b):" << endl;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {

            if (A[j] % A[i] == 0) {
                cout << "(" << A[i] << ", " << A[j] << ")" << endl;
            }

        }
    }
    cout << "__________________" << endl;
}