#include "Vectores.h"

int crear_vector_general(gVector*v,unsigned tam, size_t tam_elementos){

   v->ini = malloc(tam*tam_elementos);
   if( !(v->ini) ){
     return ERROR;
   }
   v->ce = 0;
   v->tam = tam;

   return OK;
}

void destruir_vector_general(gVector*v){
   free(v->ini);
   v->tam = 0;
   v->ce = 0;
}

int insertar_ordenado_vector_general(gVector*v, void*elemento, size_t tam_elemento, Cmp comparacion){

   if(v->ce == v->tam){
      int resultado = _redimensionar_vector(v,2,tam_elemento);
      if(resultado == ERROR){
        return ERROR;
      }
   }

   if(v->ce==0){
      memcpy(v->ini,elemento,tam_elemento);
      v->ce = v->ce + 1;
      return OK;
   }

   void*fin = v->ini +( (v->ce)*tam_elemento );
   void*ini = v->ini;

   while(ini < fin && comparacion( (fin - (tam_elemento) ) , elemento  ) > 0 ){
        memcpy(fin, (fin - (tam_elemento)), tam_elemento);
        fin = fin - (tam_elemento);
   }

   memcpy(fin,elemento,tam_elemento);
   v->ce = v->ce + 1;

   return OK;
}
void recorrer_vector_general(gVector *v,size_t tam_elementos, Accion accion){
   int i;
   void*pivot = v->ini;

   for(i=0;i<v->ce;i++){
      accion(pivot);
      pivot = pivot + (tam_elementos);
   }
}

int obtener_por_posicion_vector_general(gVector*v,void*elemento,unsigned pos, size_t tam_elementos){
    if(v->ce == 0 || pos > v->ce || pos < 0){
        return ERROR;
    }
    void*pivot = v->ini + (pos*tam_elementos);
    memcpy(elemento,pivot,tam_elementos);

    return OK;
}

int _redimensionar_vector(gVector* v, unsigned agregado, size_t tam_elementos){

   void* aux = realloc( v->ini, (v->tam + agregado)*tam_elementos);
   if(!aux){
     return ERROR;
   }

   v->ini = aux;
   v->tam = v->tam + agregado;

   return OK;
}


int drop_by_pos(int*vec,int pos, int* ce){
   if(*(ce) == 0 || pos < 0){
     return ERROR;
   }
   if(*(ce) < pos){
     return ERROR;
   }
   int*ini = (vec + pos);
   int*fin = vec + (*(ce)-1);

   while(ini < fin){
     *ini = *(ini + 1);
     ini++;
   }

   *(ce) = *(ce) - 1;

   return OK;
}

int insert_in_order(int*vec,int* ce,int tam_max,int valor){

   if(*(ce) == 0){
       *vec = valor;
       *(ce) = *(ce) + 1;
       return OK;
   }

   int*fin;
   int*ini = vec;

   if(*(ce)== tam_max){
          fin = vec + (*(ce) - 1);
          if(*fin<valor){
             return ERROR;
          }

   }else{
      fin = vec + *(ce);
   }

   while(ini < fin && *(fin - 1)>valor){
       *fin = *(fin - 1);
       fin--;
   }

   *fin = valor;

   if(*(ce)<tam_max){
    *(ce) = *(ce) + 1;
   }

   return OK;
}


int comparar_enteros(void*a,void*b){
  int num1 = *(int*)a;
  int num2 = *(int*)b;

  return num1 - num2;
}

void mostrar_enteros(void*a){
  int numero = *(int*)a;
  printf("%d ", numero);
}















