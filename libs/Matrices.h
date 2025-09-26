#ifndef MATRICES_H_INCLUDED
#define MATRICES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OK 1
#define ERROR -1
typedef void (*Accion)(void*m);

void** crear_matriz_dinamica(unsigned filas, unsigned columnas, size_t tam_elementos);
void drop_matriz_dinamica(void**matriz, unsigned filas);
void recorrer_matriz(void**matriz,unsigned filas, unsigned columnas,size_t tam_elementos, Accion accion);
void cargar_matriz (int ** mat, unsigned filas, unsigned columnas);
void mostrar_matriz(int ** mat, unsigned filas, unsigned columnas);
void establecer_cero(void*a);
#endif // MATRICES_H_INCLUDED
