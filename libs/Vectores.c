#include "Vectores.h"

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


















