#include<stdlib.h>
#include<stdio.h>
#include "ejercicio2.h"

void manejaMsg(int);

PILA crearPila(){
      PILA S;
      S = (PILA)malloc(sizeof(Pila));
      if(S == NULL){
            manejaMsg(0);
            exit(0);
      }
      S -> tope = -1;
      return S;
}

void apilar(PILA S, char e){
      if(S ->tope == TAMPILA -1){
            manejaMsg(2); //Pila llena
            exit(0);
      }
      S -> tope++;
      S -> pila[S -> tope] = e;
}

int es_vaciaPila(PILA S){
      if(S -> tope < 0)
          return TRUE;
      else
          return FALSE;
}

char desapilar(PILA S){
      char v;
      if(es_vaciaPila(S) == TRUE){
            manejaMsg(3); //Pila vacia
            exit(0);
      }
      v = S -> pila[S -> tope];
      S -> tope--;
      return v;
}

char elemTope(PILA S){
      char v;
      if(es_vaciaPila(S) == TRUE){
            manejaMsg(3); //Pila vacia
            exit(0);
      }
      v = desapilar(S);
      apilar(S, v);
      return v;
}

