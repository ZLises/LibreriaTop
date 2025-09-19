#ifndef CADENAS_H_INCLUDED
#define CADENAS_H_INCLUDED
#define MAYUS(x) ( ((x)>96 && (x)<123) ?  ((x)-32) : (x) )

int mistrlen(char* cadena);
char* mistrcat(char* destino, char*origen);
char* mistrcpy(char* destino, char* origen);
int mistrcmp(char* c1, char* c2);
int mistrcmpi(char* c1, char* c2);
char* mistrchr(char* cadena, int valor);
char* mistrrchr(char* cadena, int valor);
char* mistrrchrStrlen(char* cadena, int valor);
int es_palindromo(char* cadena);
int es_letra(int x);
int proxima_palabra(char * cadena, char**posIni);
char ofuscar_caracter(char* regla,char caracter, int pos_caracter);

#endif // CADENAS_H_INCLUDED
