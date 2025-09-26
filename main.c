#include <stdio.h>
#include <stdlib.h>
#include "libs\Cadenas.h"
#include "libs\Vectores.h"
#include "libs\Matrices.h"
#define TAM 5

int main()
{
    gVector v;
    int i;
    int resultado = crear_vector_general(&v,1,sizeof(int));

    if(resultado == ERROR){
        printf("ERROR DE CREACION DE VECTOR");
        return ERROR;
    }

    int numeros[] = {4,1,5,3,18,1,-1,-54,180,9000};
    int*pnum = numeros;
    int nt;

    for(i=0;i< sizeof(numeros)/sizeof(int) ;i++){
        insertar_ordenado_vector_general(&v,pnum,sizeof(int),comparar_enteros);
        pnum++;
    }

    recorrer_vector_general(&v,sizeof(int),mostrar_enteros);
    destruir_vector_general(&v);

    return 0;
}
