#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>
#include "Utilidades.h"
using namespace std;

// 1. GENERAR DIVISORES
vector<int> generarDivisores(int n) {
    vector<int> divisores;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            divisores.push_back(i);
        }
    }
    return divisores;
}

// 2. CREAR SUBCONJUNTO
vector<int> crearSubconjunto(vector<int> divisores) {
    vector<int> A;
    int r;

    cout << "\nArma el subconjunto A:\n";
    for (int i = 0; i < (int)divisores.size(); i++) {
        cout << "Agregar " << divisores[i] << "? (1 = si / 2 = no): ";
        cin >> r;
        if (r == 1) A.push_back(divisores[i]);
    }
    return A;
}

// 3. IMPRIMIR DIVISORES
void imprimirDivisores(vector<int> divisores, int n) {
    cout << "D(" << n << ") = { ";
    for (int i = 0; i < (int)divisores.size(); i++) {
        cout << divisores[i];
        if (i != (int)divisores.size() - 1) cout << ", ";
    }
    cout << " }\n";
}

// 4. IMPRIMIR SUBCONJUNTO
void imprimirSubconjunto(vector<int> A) {
    cout << "\n__________________\n";
    cout << "Subconjunto A = { ";
    for (int i = 0; i < (int)A.size(); i++) {
        cout << A[i];
        if (i != (int)A.size() - 1) cout << ", ";
    }
    cout << " }\n";
    cout << "__________________\n";
}

// 5. RELACION DE DIVISIBILIDAD (PARES)
void relacionDivisibilidad(vector<int> A) {
    cout << "\nRelacion (pares), a|b (a divide a b):\n";
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)A.size(); j++) {
            if (A[j] % A[i] == 0) {
                cout << "(" << A[i] << ", " << A[j] << ")\n";
            }
        }
    }
    cout << "__________________\n";
}

// 6. MATRIZ DE RELACION M
void imprimirMatrizRelacion(vector<int> A) {
    cout << "\nMatriz M (1 si a divide a b):\n";
    cout << setw(5) << " ";
    for (int i = 0; i < (int)A.size(); i++)
        cout << setw(4) << A[i];
    cout << "\n    ";
    for (int i = 0; i < (int)A.size() * 4; i++)
        cout << "-";

    for (int i = 0; i < (int)A.size(); i++) {
        cout << "\n" << setw(3) << A[i] << " |";
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
    cout << "\n";
}

// 7. MATRIZ TRANSPUESTA M^T
void imprimirMatrizRelacionTranspuesta(vector<int> A) {
    cout << "\nMatriz Transpuesta M^T:\n";
    cout << setw(5) << " ";
    for (int i = 0; i < (int)A.size(); i++)
        cout << setw(4) << A[i];
    cout << "\n    ";
    for (int i = 0; i < (int)A.size() * 4; i++)
        cout << "-";

    for (int i = 0; i < (int)A.size(); i++) {
        cout << "\n" << setw(3) << A[i] << " |";
        for (int j = 0; j < (int)A.size(); j++) {
            if (A[j] != 0 && A[i] % A[j] == 0) {
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
    cout << "\n=> Esta matriz verifica que la relacion es antisimetrica\n";
}

// 8. MATRIZ M² (VERIFICA TRANSITIVIDAD)
void mostrarMatrizCuadrada(vector<int> A) {
    int n = A.size();

    // Construir M
    vector<vector<int>> M(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[j] % A[i] == 0)
                M[i][j] = 1;

    // Calcular M²
    vector<vector<int>> M2(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (M[i][k] == 1 && M[k][j] == 1)
                    M2[i][j] = 1;

    // Imprimir M²
    cout << "\nMatriz M2 (M al cuadrado):\n";
    cout << setw(5) << " ";
    for (int i = 0; i < n; i++)
        cout << setw(4) << A[i];
    cout << "\n    ";
    for (int i = 0; i < n * 4; i++)
        cout << "-";

    for (int i = 0; i < n; i++) {
        cout << "\n" << setw(3) << A[i] << " |";
        for (int j = 0; j < n; j++)
            cout << setw(4) << M2[i][j];
    }

    // Verificar transitividad
    cout << "\n\nVerificacion de transitividad:\n";
    bool esTransitiva = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (M2[i][j] == 1 && M[i][j] == 0) {
                esTransitiva = false;
                cout << "M2[" << A[i] << "][" << A[j] << "] = 1 pero M = 0 -> NO transitiva\n";
            }
        }
    }
    if (esTransitiva)
        cout << "=> M2 esta contenida en M -> la relacion ES transitiva\n";
    else
        cout << "=> M2 NO esta contenida en M -> NO es transitiva\n";
}

// 9. VERIFICAR REFLEXIVA
bool verificarReflexiva(vector<int> A) {
    for (int i = 0; i < (int)A.size(); i++)
        if (A[i] % A[i] != 0) return false;
    return true;
}

// 10. PROPIEDADES DE ORDEN PARCIAL
void propiedadesOrdenParcial(vector<int> A) {
    cout << "\n========== PROPIEDADES DE LA RELACION ==========\n";

    // REFLEXIVIDAD
    cout << "\n1. RELACION REFLEXIVA\n";
    cout << "Una relacion R es reflexiva si todo elemento\n";
    cout << "se relaciona consigo mismo: (a,a) pertenece a R.\n";
    cout << "\nEjemplos encontrados:\n";
    for (int i = 0; i < (int)A.size(); i++)
        cout << "(" << A[i] << "," << A[i] << ")\n";
    cout << "\n=> La relacion ES reflexiva.\n";

    // ANTISIMETRIA
    cout << "\n----------------------------------------------\n";
    cout << "2. RELACION ANTISIMETRICA\n";
    cout << "R es antisimetrica si cuando (a,b) y (b,a)\n";
    cout << "estan en R, entonces a = b.\n\n";

    bool esAntisimetrica = true;
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)A.size(); j++) {
            if (A[i] != A[j]) {
                if (A[j] % A[i] == 0 && A[i] % A[j] == 0) {
                    esAntisimetrica = false;
                    cout << "(" << A[i] << "," << A[j] << ") y ("
                        << A[j] << "," << A[i] << ") en R pero "
                        << A[i] << " != " << A[j] << " -> no cumple\n";
                }
                else if (A[j] % A[i] == 0) {
                    cout << "(" << A[i] << "," << A[j] << ") en R\n";
                }
            }
        }
    }
    if (esAntisimetrica)
        cout << "=> La relacion ES antisimetrica.\n";
    else
        cout << "=> La relacion NO es antisimetrica.\n";

    // TRANSITIVIDAD
    cout << "\n----------------------------------------------\n";
    cout << "3. RELACION TRANSITIVA\n";
    cout << "R es transitiva si cuando (a,b) y (b,c) estan en R,\n";
    cout << "entonces (a,c) tambien esta en R.\n\n";
    for (int i = 0; i < (int)A.size(); i++)
        for (int j = 0; j < (int)A.size(); j++)
            for (int k = 0; k < (int)A.size(); k++)
                if (A[j] % A[i] == 0 && A[k] % A[j] == 0)
                    cout << A[i] << "|" << A[j] << " y " << A[j] << "|" << A[k] << " => " << A[i] << "|" << A[k] << "\n";
    cout << "\n=> La relacion ES transitiva.\n";

    // ORDEN PARCIAL
    cout << "\n----------------------------------------------\n";
    cout << "4. ORDEN PARCIAL\n";
    cout << "Como cumple reflexividad, antisimetria y transitividad,\n";
    cout << "la relacion de divisibilidad ES un orden parcial.\n";
}

// 11. HAY INTERMEDIO (auxiliar para Hasse)
bool hayIntermedio(int a, int b, vector<int> A) {
    for (int y = 0; y < (int)A.size(); y++) {
        int c = A[y];
        if (c != a && c != b)
            if (c % a == 0 && b % c == 0)
                return true;
    }
    return false;
}

// 12. DIAGRAMA DE HASSE
void mostrarHasse(vector<int> A) {
    cout << "\nDiagrama de Hasse:\n";
    for (int i = 0; i < (int)A.size(); i++) {
        for (int j = 0; j < (int)A.size(); j++) {
            if (A[i] != A[j] && A[j] % A[i] == 0) {
                if (!hayIntermedio(A[i], A[j], A)) {
                    cout << A[i] << " ------- " << A[j] << "\n";
                }
            }
        }
    }
}

//pantalla de bienvenida
void pantallaBienvenida() {
    establecer_color(10);
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
    cout << "  ============================================================\n";
    cout << "                   TB1  -  TEORIA DE CONJUNTOS                \n";
    cout << "  ============================================================\n";
    cout << "\n";
    cout << "  1. Empezar orden parcial\n";
    cout << "  2. Salir\n";
    cout << "\n  Opcion: ";
}