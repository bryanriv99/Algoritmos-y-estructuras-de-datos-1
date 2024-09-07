#include<stdio.h>
#include<stdlib.h>
#include "ejercicio2.h"

PILA important(PILA S);
PILA lee(PILA S);
void mostrarHistorial(PILA S);
void manejaMsg(int msg);
void liberarMem(PILA S);

void main(){
      PILA S, S1, HELP;


      S = crearPila();
      HELP = lee(S);
      S1 = important(S);
      mostrarHistorial(HELP);
      mostrarHistorial(S1);

      liberarMem(S);
      liberarMem(S1);
}

void mostrarHistorial(PILA S) {
    printf("Texto procesado: ");
    
    char caracteres[TAMPILA];
  
    int i = 0;
    while (!es_vaciaPila(S)) {
        caracteres[i] = desapilar(S);
        i++;
    }

    while (i > 0) {
        i--;
        printf("  %c", caracteres[i]);
    }
    
    printf("\n");
}

PILA important(PILA S) {
    PILA S1, S2;
  char hello;
  int hola;

  S1 = crearPila();
  S2 = crearPila();

    for(int i = 0; i < S ->tope; i++) {
    hello = desapilar(S);
    apilar(S2, hello);
  }

  int i = S ->tope;
  while(i >= 0) {
    hello = desapilar(S);
    apilar(S2, hello);
    i--;
  }

  int j = S2 ->tope;
  int r = 0;
  while(j >= 0) {
    if(j == S2 ->tope){
       hello = S2 ->pila[j];
       apilar(S1, hello);
    }else{
      if(S2 ->pila[j] == '0'){
        hello = S1 ->pila[r - 1] - 3;
        apilar(S1, hello);
      }else{
        hola = (int)S2 ->pila[j] - 48;
        hello = S1 ->pila[r - 1] + hola;
        apilar(S1, hello);
      }
      }
      j--;
      r++;
    }

  return S1;
}

PILA lee(PILA S){
  PILA HELP;
  HELP = crearPila();
  char cad;
  printf("\n\nIntroduzca el historial (de la siguiente manera: n,n1,n2 ...): ");
  while( ( cad = getchar()) != '\n') {
    if(cad != ','){
      apilar(S, cad);
      apilar(HELP, cad);
    }
  }
  return HELP;
 }

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . . \n","\nPILA LLENA!!!\n","\nPILA VACIA!!!\n"};
     printf("%s", mensajes[msg] );
}

void liberarMem(PILA S){
    free(S);
    manejaMsg(1);
}

