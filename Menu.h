#pragma once
#include <iostream>
#include <cstdlib>
#include "Utilidades.h"
#include "Impresion.h"
using namespace std;


void animarTituloOrdenParcial() {
    int colores[] = { 1, 2, 3, 4, 5, 9, 10, 11, 12, 13, 14, 15 };
    for (int i = 0; i < 15; i++) {
        int color = colores[rand() % 12];
        mover_cursor(0, 0);
        imprimirTituloOrdenParcial(color);
        Sleep(57);
    }
}

void pantallaBienvenida() {
    animarTituloOrdenParcial();
    establecer_color(7);
    cout << "  ============================================================\n";
    cout << "                   TB1  -  ORDEN PARCIAL                      \n";
    cout << "  ============================================================\n";
    cout << "\n";
    cout << "  1. Empezar orden parcial\n";
    cout << "  2. Creditos\n";
    cout << "  3. Salir\n";
    cout << "\n  Opcion: ";
}