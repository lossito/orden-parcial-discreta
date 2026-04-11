#include <iostream>
#include <vector>
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

vector<int> crearSubconjunto(int n, vector<int> divisores) {}

int imprimirDivisores(int n, vector<int> divisores) {
    cout << "D = { ";
    for (int i = 1; i <= n; i++) {
        cout << divisores[i] << " ; ";
    }
    cout << " } ";
}