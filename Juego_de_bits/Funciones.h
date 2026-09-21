#ifndef FUNCIONES_H
#define FUNCIONES_H

void crearTablero(int &filas, int &columnas, unsigned char* &tablero, int &totalBytes);
int menu();
void mostrarTablero(unsigned char* tablero,int filas, int columnas, int totalbytes);
unsigned char leerficha(unsigned char* tablero, int fila, int columna, int columnas, int totalbytes);
void escribirficha(unsigned char* tablero, int fila, int columna, int columnas, int totalbytes, unsigned char valor);
char ficha_letra(unsigned char valor);
void eliminar_ficha(unsigned char* tablero, int filas, int columnas, int totalbytes);
bool* crear_marcas(int filas, int columnas);
void detectar_horizontales(unsigned char* tablero, int filas, int columnas, int totalbytes, bool* marca);
void detectar_verticales(unsigned char* tablero, int filas, int columnas, int totalbytes, bool* marca);
int eliminar_marcadas(unsigned char* tablero, int filas, int columnas, int totalbytes, bool* marca);

void caida_fichas(unsigned char* tablero, int filas, int columnas, int totalbytes);
int cascadas(unsigned char* tablero, int filas, int columnas, int totalbytes,int &total_eliminadas);
void agregar_fila(unsigned char* &tablero, int &filas, int columnas, int &totalbytes);
void eliminar_fila(unsigned char* &tablero, int &filas, int columnas, int &totalbytes);
void mostrarbit(unsigned char valor);
void mostrartablerobin(unsigned char* tablero, int filas, int columnas, int totalbytes);
#endif // FUNCIONES_H
