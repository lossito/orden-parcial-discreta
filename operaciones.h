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