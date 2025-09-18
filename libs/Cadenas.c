#include "Cadenas.h"

int mistrlen(char* cadena){
  int contador = 0;

  while(*cadena != '\0'){
    contador++;
    cadena++;
  }

  return contador;
}

//lo mismo que strrchr pero llevando el puntero al final de la cadena
char* mistrrchrStrlen(char* cadena, int valor){
   char*resultado=0;
   char*ini = cadena;
   int cantidad = mistrlen(cadena);

   if(cantidad!=0){
     cadena+= (cantidad - 1);
   }

   while(ini < cadena){
      if(*cadena==valor){
        return cadena;
      }
      cadena--;
   }
   return resultado;
}

char* mistrrchr(char* cadena, int valor){
   char*resultado=0;
   while(*cadena != '\0'){
      if(*cadena==valor){
        resultado = cadena;
      }
      cadena++;
   }
   return resultado;
}

char* mistrchr(char* cadena, int valor){
   char*resultado=0;
   while(*cadena != '\0'){
      if(*cadena==valor){
        return cadena;
      }
      cadena++;
   }
   return resultado;
}

/*
  r>0 si a>b
  r<0 si a<b
  r==0 si a==b
*/

//compara las cadenas pero llevanto todos los caracteres a mayus
int mistrcmpi(char* c1, char* c2){
   while( (MAYUS(*c1) != '\0') && ( MAYUS(*c2) != '\0') && (MAYUS(*c1) == MAYUS(*c2)) ){
      c1++;
      c2++;
   }
   return MAYUS(*c1) - MAYUS(*c2);
}

int mistrcmp(char* c1, char* c2){
   while( (*c1 != '\0') && (*c2 != '\0') && (*c1 == *c2) ){
      c1++;
      c2++;
   }
   return *c1 - *c2;
}


char* mistrcpy(char* destino, char* origen){
   char*ini = destino;

   while(*destino != '\0' && *origen != '\0'){
      *destino = *origen;
      destino++;
      origen++;
   }
   *destino= '\0';

   return ini;
}


char* mistrcat(char* destino, char*origen){
   char*ini = destino;

   while(*destino != '\0'){
      destino++;
   }

   while(*origen != '\0'){
      *destino = *origen;
      destino++;
      origen++;
   }

   *destino = '\0';

   return ini;
}

int es_letra(int x){
   if(((x)>96 && (x)<123) || ((x)>64 && (x)<90)){
     return 1;
   }else{
     return 0;
   }
}

//retorna 1 si es palindromo, las mayus y caracteres especiales los ignora.
int es_palindromo(char* cadena){

   char*ini = cadena;
   char*fin = (cadena +  (mistrlen(cadena) - 1));

   while( es_letra(*ini) == 0){
      ini++;
   }
   if( MAYUS(*ini) != MAYUS(*fin) ){
      return 0;
   }

   while(ini < fin){
       if(es_letra(*ini) == 0){
          ini++;
       }else{
          if(es_letra(*fin)==0){
            fin--;
          }else{
            if(  MAYUS(*ini) != MAYUS(*fin)  ){
                return 0;
            }
            ini++;
            fin--;
          }
       }
   }
   return 1;
}
















