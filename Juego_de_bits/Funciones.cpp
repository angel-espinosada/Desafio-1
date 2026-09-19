
#include <iostream>
#include "Funciones.h"
#include <random>
using namespace std;

void crearTablero(int &filas, int &columnas, unsigned char* &tablero, int &totalBytes) {
    cout << "||||Sweet Crush, JUEGO DE BITS||||" << endl;
    cout << "Ingrese numero de filas: ";
    cin >> filas;
    cout << "Ingrese numero de columnas: ";
    cin >> columnas;


    int totalBits = 3 * filas * columnas;
    totalBytes = (totalBits + 7) / 8; //Calculo de bits

    tablero = new unsigned char[totalBytes];

    cout << "Tablero creado: " << filas << "x" << columnas
         << " (" << totalBytes << " bytes reservados)" << endl;
}

int menu() {
    int opcion;

    cout << endl << "******MENU*******" << endl;
    cout << "1 Mostrar tablero" << endl;
    cout << "2 Eliminar ficha" << endl;
    cout << "3 Agregar fila" << endl;
    cout << "4 Eliminar fila" << endl;
    cout << "5 Agregar columna" << endl;
    cout << "6 Eliminar columna" << endl;
    cout << "7 Ver estado del juego" << endl;
    cout << "0 Salir" << endl;
    cout << "Elija una opcion: ";
    cin >> opcion;

    return opcion;
}

void mostrarTablero(int filas, int columnas) {
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            cout << "[ * ]"; //ficha temporal...
        }
        cout << endl;
    }
}


void generarfichas(int totalfichas) {
    srand(time(0));

    for (int i = 0; i < totalfichas; i++) {
        int valor = rand() % 8;
        cout << "Ficha " << i << ": " << valor << endl;
    }
}
