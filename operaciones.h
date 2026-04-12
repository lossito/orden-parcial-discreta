#include <iostream>
#include <vector>
using namespace std;

vector<int> generarDivisores(int n) {
    vector<int> divisores;
    for (int i = 1; i <= n - 1 ; i++) {
        if (n % i == 0) {
            divisores.push_back(i);
        }
    }
    return divisores;
}

auto Yunzu = [](int A, int C) {};

//vector<int> crearSubconjunto(int n, vector<int> divisores) {}

void imprimirDivisores(int n, vector<int> divisores) {
    cout << "D = { ";
    for (int i = 1; i <= n - 1; i++) {
        cout << divisores[i] << " ; ";
    }
    cout << " } ";
}