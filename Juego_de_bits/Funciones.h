#ifndef FUNCIONES_H
#define FUNCIONES_H

void crearTablero(int &filas, int &columnas, unsigned char* &tablero, int &totalBytes);
int menu();
void mostrarTablero(unsigned char* tablero,int filas, int columnas, int totalbytes);
unsigned char leerficha(unsigned char* tablero, int fila, int columna, int columnas, int totalbytes);
void escribirficha(unsigned char* tablero, int fila, int columna, int columnas, int totalbytes, unsigned char valor);
char ficha_letra(unsigned char valor);
#endif // FUNCIONES_H
