#ifndef VECTORES_H_INCLUDED
#define VECTORES_H_INCLUDED
#define OK 1
#define ERROR -1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 5

typedef struct{
   void*ini;
   unsigned tam;
   unsigned ce;
}gVector;

typedef int (*Cmp)(void*a,void*b);
typedef void (*Accion)(void*m);
typedef int (*Filtro)(void*valor);

int insert_in_order(int*vec,int* ce,int tam_max,int valor);
int drop_by_pos(int*vec,int pos, int* ce);
int _redimensionar_vector(gVector* v, unsigned agregado, size_t tam_elementos);
int crear_vector_general(gVector*v,unsigned tam, size_t tam_elementos);
void destruir_vector_general(gVector*v);
int insertar_ordenado_vector_general(gVector*v, void*elemento, size_t tam_elemento, Cmp comparacion);
int obtener_por_posicion_vector_general(gVector*v,void*elemento,unsigned pos, size_t tam_elementos);
void recorrer_vector_general(gVector *v,size_t tam_elementos, Accion accion);

int comparar_enteros(void*a,void*b);
void mostrar_enteros(void*a);

void mi_filter(void*vec, int*ce,size_t tam_elemento, Filtro filtro);
int mi_swap(void*a,void*b,size_t tam_elemento);
void* extremos_vector(void*vec,int*ce,size_t tam_elemento, Cmp cmp);
void ssort(void*vec,int*ce,size_t tam_elemento,Cmp cmp);
void* mi_busqueda(void*inicio,void*elemento, size_t tam_elemento,int ce,Cmp cmp);
#endif // VECTORES_H_INCLUDED
