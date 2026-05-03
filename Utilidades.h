#pragma once
#include <windows.h>
#include <iostream>
using namespace std;

// ============================================================
//  UTILIDADES DE CONSOLA  (colores, cursor, ventana)
// ============================================================

// Configura el tamanio de la ventana y oculta el cursor
void configurarventana() {
    HWND consola = GetConsoleWindow();
    MoveWindow(consola, 100, 50, 900, 700, TRUE);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 1;
    cursor.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursor);
}

// Mueve el cursor a la posicion (columna, fila) en la consola
void mover_cursor(int columna, int fila) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD posicion = { (SHORT)columna, (SHORT)fila };
    SetConsoleCursorPosition(hConsole, posicion);
}

// Cambia el color del texto en la consola
// Codigos usados: 3=verde, 4=rojo, 5=amarillo, 7=blanco(reset),
//                 10=verde claro, 11=cyan, 12=rojo claro, 13=magenta, etc.
void establecer_color(int color_codigo) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (color_codigo) {
    case 0:  SetConsoleTextAttribute(hConsole, 1);  break;
    case 1:  SetConsoleTextAttribute(hConsole, 7);  break;
    case 2:  SetConsoleTextAttribute(hConsole, 9);  break;
    case 3:  SetConsoleTextAttribute(hConsole, 2);  break;   // verde
    case 4:  SetConsoleTextAttribute(hConsole, 4);  break;   // rojo
    case 5:  SetConsoleTextAttribute(hConsole, 6);  break;   // amarillo
    case 6:  SetConsoleTextAttribute(hConsole, 0);  break;
    case 7:  SetConsoleTextAttribute(hConsole, 7);  break;   // blanco (reset)
    case 8:  SetConsoleTextAttribute(hConsole, 8);  break;
    case 9:  SetConsoleTextAttribute(hConsole, 1);  break;
    case 10: SetConsoleTextAttribute(hConsole, 10); break;   // verde claro
    case 11: SetConsoleTextAttribute(hConsole, 11); break;
    case 12: SetConsoleTextAttribute(hConsole, 12); break;
    case 13: SetConsoleTextAttribute(hConsole, 13); break;
    case 14: SetConsoleTextAttribute(hConsole, 14); break;
    case 15: SetConsoleTextAttribute(hConsole, 15); break;
    default: SetConsoleTextAttribute(hConsole, 7);
    }
}

// Version directa: acepta el indice de color de Windows sin mapeo
void usar_color(short colorIndex) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorIndex);
}