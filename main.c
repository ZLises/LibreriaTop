#include <stdio.h>
#include <stdlib.h>
#include "libs\Cadenas.h"
#include "libs\Vectores.h"
#include "libs\Matrices.h"
#define TAM 5

void establecer_cero(void*a){
  *(int*)a = 0;
}

int main()
{
    int ** m;
    m = (int**)crear_matriz_dinamica(3,3,sizeof(int));
    //cargar_matriz(m,3,3);
    recorrer_matriz((void**)m,3,3,sizeof(int),(Accion)establecer_cero);
    mostrar_matriz(m,3,3);
    drop_matriz_dinamica((void**)m,3);
    return 0;
}
