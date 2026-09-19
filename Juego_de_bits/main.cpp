#include <iostream>
#include "Funciones.h"
using namespace std;


int main() {
    int filas, columnas, totalbytes;
    int opcion;
    unsigned char* tablero;
    crearTablero(filas, columnas, tablero, totalbytes);
    do {
        opcion = menu();

        switch (opcion) {
        case 1:
            cout << "Mostrar tablero" << endl;
            mostrarTablero(tablero,filas, columnas,totalbytes);
            generarfichas(filas * columnas);
            break;
        case 2:
            cout << "Eliminar ficha" << endl;
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
