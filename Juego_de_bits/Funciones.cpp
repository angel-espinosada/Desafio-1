
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
void eliminar_ficha(unsigned char* tablero, int filas, int columnas, int totalbytes) {
    int fila, columna;
    cout << "Fila a eliminar (0 a " << filas - 1 << "): ";
    cin >> fila;
    cout << "Columna a eliminar (0 a " << columnas - 1 << "): ";
    cin >> columna;

    if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas) {
        cout << "Posicion invalida." << endl;
        return;
    }

    escribirficha(tablero, fila, columna, columnas, totalbytes, 6);   // 6 = estado libre
    cout << "Ficha eliminada." << endl;
}


bool* crear_marcas(int filas, int columnas){

    bool* marca = new bool[filas * columnas];
    for (int i = 0; i < filas * columnas; i++) {
        marca[i] = false;
    }
    return marca;
}


void detectar_horizontales(unsigned char* tablero, int filas, int columnas, int totalbytes, bool* marca){

    for (int f = 0; f < filas; f++) {
        int c = 0;
        while (c < columnas) {
            unsigned char valor = leerficha(tablero, f, c, columnas, totalbytes);
            if (valor > 5) { c++; continue; }   // salta estado libre/especial

            int inicio = c;
            while (c + 1 < columnas && leerficha(tablero, f, c + 1, columnas, totalbytes) == valor) {
                c++;
            }
            int largo = c - inicio + 1;
            if (largo >= 3) {
                for (int k = inicio; k <= c; k++) {
                    marca[f * columnas + k] = true;
                }
            }
            c++;
        }
    }
}
void detectar_verticales(unsigned char* tablero, int filas, int columnas, int totalbytes, bool* marca){
    for (int c = 0; c < columnas; c++) {
    int f = 0;
    while (f < filas) {
        unsigned char valor = leerficha(tablero, f, c, columnas, totalbytes);
        if (valor > 5) { f++; continue; }

        int inicio = f;
        while (f + 1 < filas && leerficha(tablero, f + 1, c, columnas, totalbytes) == valor) {
            f++;
        }
        int largo = f - inicio + 1;
        if (largo >= 3) {
            for (int k = inicio; k <= f; k++) {
                marca[k * columnas + c] = true;
            }
        }
        f++;
    }
}
}
int eliminar_marcadas(unsigned char* tablero, int filas, int columnas, int totalbytes, bool* marca){

    int contador = 0;
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            if (marca[f * columnas + c]) {
                escribirficha(tablero, f, c, columnas, totalbytes, 6);
                contador++;
            }
        }
    }
    return contador;
}

void caida_fichas(unsigned char* tablero, int filas, int columnas, int totalbytes){
    for (int c = 0; c < columnas; c++) {
        int escritura = filas - 1;   // apunta a la fila mas baja aun sin llenar

        for (int f = filas - 1; f >= 0; f--) {
            unsigned char valor = leerficha(tablero, f, c, columnas, totalbytes);
            if (valor <= 5) {   // es una ficha valida (no vacio ni especial)
                escribirficha(tablero, escritura, c, columnas, totalbytes, valor);
                escritura--;
            }
        }

        // lo que quedo arriba de 'escritura' esta vacio: se rellena con fichas nuevas
        for (int f = escritura; f >= 0; f--) {
            escribirficha(tablero, f, c, columnas, totalbytes, rand() % 6);
        }
    }
}

int cascadas(unsigned char* tablero, int filas, int columnas, int totalbytes){
    int cascadas = 0;
    int eliminadas;

    do {
        bool* marca = crear_marcas(filas, columnas);
        detectar_horizontales(tablero, filas, columnas, totalbytes, marca);
        detectar_verticales(tablero, filas, columnas, totalbytes, marca);
        eliminadas = eliminar_marcadas(tablero, filas, columnas, totalbytes, marca);
        delete[] marca;

        if (eliminadas > 0) {
            caida_fichas(tablero, filas, columnas, totalbytes);
            cascadas++;
        }

    } while (eliminadas > 0);

    return cascadas;
}
