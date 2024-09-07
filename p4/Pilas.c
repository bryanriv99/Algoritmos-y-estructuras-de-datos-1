#include "Pilas.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

PILA crearPila() {
  PILA tmp = (PILA)malloc(sizeof(pila));
  if (tmp == NULL) {
    manejaError(0);
    exit(-1);
  }
  tmp->tope = -1;
  return tmp;
}

// num de errores posibles:    4
void manejaError(int e) {
  char *errores[] = {"No hay memoria disponible\n",
                     "Canasta Llena, no se añadira el elemento\n",
                     "No se pudo crear el arrChar\n",
                     "Se ha liberado la memoria...\n",
                     "Canasta vacia.\n"};
  printf("%s", errores[e]);
}

int es_vaciaPila(PILA S) {
  if (S->tope < 0)
    return 1;
  return 0;
}

void apilar(PILA S, char *cad) {
  if (!(S->tope == (TAM - 1))) {
    (S->tope)++;
    S->pila[S->tope] = cad;
  } else manejaError(4);
}

char *desapilar(PILA S) {
  char *a;
  if (!(es_vaciaPila(S))) {
    a = S->pila[S->tope];
    S->pila[S->tope] = 0;
    (S->tope)--;
    return a;
  }else manejaError(4); // Pila vacia
}

char *elemTope(PILA S) {
  char *a;
  if (!(es_vaciaPila(S))) {
    a = S->pila[S->tope];
    return a;
  }
  manejaError(4); // Pila vacia
  exit(0);
}

void liberarPilaTmp(PILA ap) {
    free(ap);
}
