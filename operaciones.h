#include <iostream>
#include <vector>
using namespace std;

vector<int> generarDivisores(int n) {
    vector<int> divisores;
    for (int i = 1; i <= n - 1; i++)
    {
        if (n % i == 0) {
            divisores.push_back(i);
        }
    }
    return divisores;
}

//vector<int> crearSubconjunto(int n, vector<int> divisores) {}

void imprimirDivisores(vector<int> divisores) {
    cout << "D = { ";
    for (auto i : divisores)
    {
        cout << i << " ; ";
    } 
    cout << " } ";
}

vector<int> crearSubconjunto(vector<int> divisores) {
    vector<int> A;
    int r;

    cout << "Arma el subconjunto A:" << endl;

    for (int i = 0; i < divisores.size(); i++) {
        cout << "¿Agregar " << divisores[i] << "? (1 = si / 2 = no): ";
        cin >> r;

        if (r == 1) {
            A.push_back(divisores[i]);
        }
    }

    return A;
}

void imprimirSubconjunto(vector<int> A) {
    cout << "__________________" << endl;
    cout << "Subcojunto A = { " << endl;
    for (int i = 0; i < A.size(); i++) {
        cout << A[i];
        if (i != A.size() - 1) cout << ", ";
    }
    cout << " }" << endl;
    cout << "__________________" << endl;
}


void relacionDivisibilidad(vector<int> A) {
    cout << "Relacion (pares):" << endl;

    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {

            if (A[j] % A[i] == 0) {
                cout << "(" << A[i] << ", " << A[j] << ")" << endl;
            }

        }
    }
    cout << "__________________" << endl;
}