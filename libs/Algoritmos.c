#include "Algoritmos.h"

int * entero_bsearch(int*vec,int ce,int valor){
   int * ini = vec;
   int * fin = vec + (ce - 1);
   int cant_elementos = (ce-1)/2;
   int * medio;
   int comparacion;

   while(ini <= fin){
      medio = ini + cant_elementos;
      comparacion = *medio - valor;
      if(*medio == valor){
        return medio;
      }
      if(comparacion < 0){
        ini = medio + 1;
      }else{
        fin = medio - 1;
      }
     cant_elementos = (cant_elementos - 1)/2;
   }
    return NULL;
}

