#ifndef FUNCIONES_H
#define FUNCIONES_H

void crearTablero(int &filas, int &columnas, unsigned char* &tablero, int &totalBytes);
int menu();
void mostrarTablero(unsigned char* tablero,int filas, int columnas, int totalbytes);
void generarfichas(int totalFichas);
unsigned char leerficha(unsigned char* tablero, int fila, int columna, int columnas, int totalbytes);
#endif // FUNCIONES_H
