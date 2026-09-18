#include <iostream>
#include "Funciones.h"
using namespace std;

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

int main() {
    int opcion, filas,columnas;
    cout << "Sweet Crush, JUEGO DE BITS" << endl;
    cout << "Ingrese numero de filas: ";
    cin >> filas;
    cout << "Ingrese numero de columnas: ";
    cin >> columnas;

    do {
        opcion = menu();

        switch (opcion) {
        case 1:
            cout << "Mostrar tablero" << endl;
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
