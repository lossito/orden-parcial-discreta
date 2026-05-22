#pragma once
#include <windows.h>
#include <iostream>
using namespace std;

void configurarventana() {
    HWND consola = GetConsoleWindow();
    MoveWindow(consola, 100, 50, 900, 700, TRUE);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor;
    cursor.dwSize = 1;
    cursor.bVisible = false;
    SetConsoleCursorInfo(hConsole, &cursor);
}

void mover_cursor(int columna, int fila) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD posicion = { (SHORT)columna, (SHORT)fila };
    SetConsoleCursorPosition(hConsole, posicion);
}

void establecer_color(int color_codigo) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (color_codigo) {
    case 0:  SetConsoleTextAttribute(hConsole, 1);  break;
    case 1:  SetConsoleTextAttribute(hConsole, 7);  break;
    case 2:  SetConsoleTextAttribute(hConsole, 9);  break;
    case 3:  SetConsoleTextAttribute(hConsole, 2);  break;  
    case 4:  SetConsoleTextAttribute(hConsole, 4);  break;  
    case 5:  SetConsoleTextAttribute(hConsole, 6);  break;   
    case 6:  SetConsoleTextAttribute(hConsole, 0);  break;
    case 7:  SetConsoleTextAttribute(hConsole, 7);  break;   
    case 8:  SetConsoleTextAttribute(hConsole, 8);  break;
    case 9:  SetConsoleTextAttribute(hConsole, 1);  break;
    case 10: SetConsoleTextAttribute(hConsole, 10); break;   
    case 11: SetConsoleTextAttribute(hConsole, 11); break;
    case 12: SetConsoleTextAttribute(hConsole, 12); break;
    case 13: SetConsoleTextAttribute(hConsole, 13); break;
    case 14: SetConsoleTextAttribute(hConsole, 14); break;
    case 15: SetConsoleTextAttribute(hConsole, 15); break;
    default: SetConsoleTextAttribute(hConsole, 7);
    }
}

void usar_color(short colorIndex) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colorIndex);
}

int leerEnteroPositivo(string mensaje) {
    int n;

    do {
        cout << mensaje;
        cin >> n;

        if (cin.fail() || n <= 0) {
            cout << "Numero invalido. Intente otra vez.\n";

            cin.clear();
            cin.ignore(1000, '\n');

            n = -1;
        }

    } while (n <= 0);

    return n;
}