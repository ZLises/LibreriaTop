#include "Matrices.h"

void** crear_matriz_dinamica(unsigned filas, unsigned columnas, size_t tam_elementos){

    void**puntero = malloc(filas*sizeof(void*));

    if(!puntero){
        return NULL;
    }

    int i,j;
    void**ini = puntero;

    for(i=0;i<filas;i++){
       *puntero = malloc(columnas*tam_elementos);
       if(*puntero == NULL){
           puntero = ini;
           for(j=0;j<i;j++){
             free(*puntero);
             puntero++;
           }
           free(ini);
           return NULL;
       }
       puntero++;
    }
    return ini;
}

void drop_matriz_dinamica(void**matriz, unsigned filas){
    int i;

    void**ini = matriz;

    for(i=0;i<filas;i++){
        free(*matriz);
        matriz++;
    }
    free(ini);
}
void recorrer_matriz(void**matriz,unsigned filas, unsigned columnas,size_t tam_elementos, Accion accion){
   void*pivot;

   int i,j;

   for(i=0;i<filas;i++){
    for(j=0;j<columnas;j++){
        pivot = (*matriz) + (j*tam_elementos);
        accion(pivot);
    }
    matriz++;
   }
}

void cargar_matriz (int ** mat, unsigned filas, unsigned columnas)
{
    for(int i = 0; i <filas; i++){
        for(int j=0; j<columnas; j++){
            mat[i][j]=i*4+j+1;
        }
    }
}
void mostrar_matriz(int ** mat, unsigned filas, unsigned columnas)
{
    for(int i = 0; i <filas; i++){
        for(int j=0; j<columnas; j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}
