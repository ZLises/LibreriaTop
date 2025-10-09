#include <stdio.h>
#include <stdlib.h>
#include "libs\Cadenas.h"
#include "libs\Vectores.h"
#include "libs\Matrices.h"
#include "libs\Algoritmos.h"

int filtro1(void*valor){
   int x = *(int*)valor;
   if(x==0){
     return OK;
   }else{
     return ERROR;
   }
}

int main()
{
    int vectores[] = {12332,222222,3,4,6,7,1,22,23,55,12,-2323,-1};
    int*puntero = vectores;
    int ce = sizeof(vectores)/sizeof(int);
    ssort(vectores,&ce,sizeof(int),comparar_enteros);
    for(int i=0;i<ce;i++){
        printf("%d ", *puntero);
        puntero++;
    }

    return 0;
}
