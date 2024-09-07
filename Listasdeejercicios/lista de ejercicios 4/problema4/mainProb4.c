#include<stdio.h>
#include<stdlib.h>
#include "prob4.h"

/* Escribir un programa usando funciones que dada una cadena ésta se
 * imprima en forma invertida usando para ello una Pila y sus operaciones.
 */

void leer(char*);
char *crearCadenaChar();
void invertir(char*, char*);
void mostrarInvertida(char*);
void liberarChar(char*);
void manejaMsg(int msg);

int main( )
{
    char *cadena = crearCadenaChar();
    char *cadenaNueva = crearCadenaChar();
    leer(cadena);
    invertir(cadena,cadenaNueva);
    mostrarInvertida(cadenaNueva);
    liberarChar(cadena);
    liberarChar(cadenaNueva);
    return 0;
}

char *crearCadenaChar() {
  char *ap = (char *)malloc(sizeof(char) * TAMPILA);
  if (ap == NULL) {
    manejaMsg(4);
    exit(0);
  }
  return ap;
}

void leer(char *cadena) {
  int cont = 0;

  printf("\n Introduzca la cadena a invertir: ");
  while ((cadena[cont++] = getchar()) != '\n');
  cadena[--cont] = '\0';
}

void invertir(char *vieja, char *nueva){
    PILA p = crearPila();
    int aux = 0;
    while(vieja[aux] != '\0'){
        apilar(p,vieja[aux]);
        aux++;
    }
    aux = 0;
    while(!(es_vaciaPila(p))){
        nueva[aux] = desapilar(p);
        aux++;
    }
    nueva[aux] = '\0';

}

void mostrarInvertida(char *cadena){
    printf("\n----------------------------------------------\n\tCadena Invertida: %s\n\n",cadena);
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .","Pila vacia . . .","Pila llena . . .","Error . . ."};
     printf("%s", mensajes[msg] );
}

void liberarChar(char *ap) {
  free(ap);
  manejaMsg(1);
}
