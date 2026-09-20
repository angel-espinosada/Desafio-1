#include <iostream>
#include "Funciones.h"
using namespace std;


int main() {
    int filas, columnas, totalbytes;
    int opcion;
    unsigned char* tablero;
    crearTablero(filas, columnas, tablero, totalbytes);

    srand(time(0));
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            escribirficha(tablero, f, c, columnas, totalbytes, rand() % 6);
        }
    }
    do {
        opcion = menu();

        switch (opcion) {
        case 1:
            cout << "Mostrar tablero" << endl;


            mostrarTablero(tablero,filas, columnas,totalbytes);
            break;
        case 2:{
            cout << "Eliminar ficha" << endl;
            eliminar_ficha(tablero, filas, columnas, totalbytes);
            bool* marca = crear_marcas(filas, columnas);
            detectar_horizontales(tablero, filas, columnas, totalbytes, marca);
            detectar_verticales(tablero, filas, columnas, totalbytes, marca);
            int eliminadas = eliminar_marcadas(tablero, filas, columnas, totalbytes, marca);
            cout << "Eliminacion de fichas: " << eliminadas << endl;
            delete[] marca;
            int cascada = cascadas(tablero, filas, columnas, totalbytes);
            cout << "Cascadas producidas: " << cascada << endl;
        }
            break;
        case 3:
            cout << "Agregar fila" << endl;
            break;
        case 4:
            cout << "Eliminar fila" << endl;
            break;
        case 5:
            cout << "Agregar columna" << endl;
            break;
        case 6:
            cout << "Eliminar columna" << endl;
            break;
        case 7:
            cout << "Ver estado del juego" << endl;
            break;
        case 0:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opcion invalida." << endl;
        }

    } while (opcion != 0);

    return 0;
}
