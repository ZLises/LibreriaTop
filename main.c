#include <stdio.h>
#include <stdlib.h>
#include "libs\Cadenas.h"
#include "libs\Vectores.h"

#define TAM 5
int main()
{
    int vector[TAM] = {3,4,5,6,9};
    int ce = 5;
    int i;
    int *puntero = vector;

    insert_in_order(vector,&ce,TAM,8);

    for(i=0;i<ce;i++){
       printf("%d ", *puntero);
       puntero++;
    }


    return 0;
}
