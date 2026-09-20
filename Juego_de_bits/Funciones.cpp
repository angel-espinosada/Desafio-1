
#include <iostream>
#include "Funciones.h"
#include <random>
using namespace std;

void crearTablero(int &filas, int &columnas, unsigned char* &tablero, int &totalbytes) {
    cout << "||||Sweet Crush, JUEGO DE BITS||||" << endl;
    cout << "Ingrese numero de filas: ";
    cin >> filas;
    cout << "Ingrese numero de columnas: ";
    cin >> columnas;


    int totalbits = 3 * filas * columnas;
    totalbytes = (totalbits + 7) / 8; //Calculo de bits

    tablero = new unsigned char[totalbytes];

    cout << "Tablero creado: " << filas << "x" << columnas
         << " (" << totalbytes << " bytes reservados)" << endl;
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

void mostrarTablero(unsigned char* tablero,int filas, int columnas,int totalbytes) {
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            unsigned char valor=leerficha(tablero, f, c, columnas, totalbytes);
            char letra=ficha_letra(valor);
            cout << "[ " << letra << " ]"; //ficha
        }
        cout << endl;
    }
}



unsigned char leerficha(unsigned char* tablero, int fila, int columna, int columnas, int totalbytes) {
    //Calculos realizados en el cuaderno
    int indice = fila * columnas + columna;
    int bitinicio = indice * 3;
    int byte = bitinicio / 8;
    int bitenbyte = bitinicio % 8;
    int siguiente = (byte + 1 < totalbytes) ? tablero[byte + 1] : 0;
    int combinado = tablero[byte] | (siguiente << 8);
    int desplazado = combinado >> bitenbyte;

    return desplazado & 7;   // Una mascara 111
}

int ficha_binario(int ficha){
    int binario[100];
    int i=0;
    if (ficha == 0) {
        cout << 0 << endl;
        return 0;
    }
    while (ficha > 0) {
        binario[i] = ficha % 2;
        cout << "Dividimos. Residuo (bit): " << binario[i] << endl;

        ficha = ficha / 2;
        i++;
}
}

void escribirficha(unsigned char* tablero, int fila, int columna, int columnas, int totalbytes, unsigned char valor) {
    int indice = fila * columnas + columna;
    int bitinicio = indice * 3;
    int byte = bitinicio / 8;
    int bitenbyte = bitinicio % 8;

    bool siguienteExiste = (byte + 1 < totalbytes);
    int siguiente = siguienteExiste ? tablero[byte + 1] : 0;

    int combinado = tablero[byte] | (siguiente << 8);

    int mascara = 7 << bitenbyte;      // mascara
    int borrador = ~mascara;           // borra solo esos 3 bits

    int limpio = combinado & borrador;
    int valorCorrido = (valor & 7) << bitenbyte;

    int nuevo = limpio | valorCorrido;

    tablero[byte] = nuevo & 0xFF;                  // 8 bits acutual
    if (siguienteExiste) {
        tablero[byte + 1] = (nuevo >> 8) & 0xFF;   // 8 bits siguiente
    }
}

char ficha_letra(unsigned char valor){
    switch (valor) {
    case 0: return 'A';
    case 1: return 'B';
    case 2: return 'C';
    case 3: return 'D';
    case 4: return 'E';
    case 5: return 'F';
    case 6: return '.';   // Estado libre
    case 7: return '*';   //Especial
    }
    return '?';
}
