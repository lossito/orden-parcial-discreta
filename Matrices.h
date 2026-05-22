#pragma once
#include <vector>
using namespace std;


vector<vector<int>> construirMatrizM(const vector<int>& A) {
    int n = A.size();
    vector<vector<int>> M(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[j] % A[i] == 0)
                M[i][j] = 1;
    return M;
}

vector<vector<int>> construirMatrizTranspuesta(const vector<vector<int>>& M) {
    int n = M.size();
    vector<vector<int>> MT(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            MT[i][j] = M[j][i];
    return MT;
}


vector<vector<int>> construirMatrizCuadrada(const vector<vector<int>>& M) {
    int n = M.size();
    vector<vector<int>> M2(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (M[i][k] == 1 && M[k][j] == 1)
                    M2[i][j] = 1;
    return M2;
}


vector<vector<int>> construirMatrizSinDiagonal(const vector<vector<int>>& M) {
    int n = M.size();
    vector<vector<int>> M1(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                M1[i][j] = M[i][j];
    return M1;
}


vector<vector<int>> construirMatrizHasse(const vector<vector<int>>& M1,
    const vector<vector<int>>& M2) {
    int n = M1.size();
    vector<vector<int>> M3(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (M1[i][j] == 1 && M2[i][j] == 0)
                M3[i][j] = 1;
    return M3;
}