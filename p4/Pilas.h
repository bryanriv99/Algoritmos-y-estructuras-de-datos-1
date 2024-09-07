#ifndef _pilas_
#define _pilas_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define TAM 20

typedef struct {
  char *pila[TAM];
  int tope;
} pila;

typedef pila *PILA;

PILA crearPila();

void manejaError(int);
void apilar(PILA, char*);
char *desapilar(PILA);
int es_vaciaPila(PILA);
char *elemTope(PILA);

void liberarPilaTmp(PILA);

#endif
