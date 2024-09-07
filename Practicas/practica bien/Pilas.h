#ifndef _pilas_
#define _pilas_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

typedef struct{
    char materia[30];
    char tema[30];
    char nombre[30];
    int hojas;
    int estado;
} trabajo;

typedef trabajo *TRABAJO;

typedef struct {
  TRABAJO pila[TAM];
  int tope;
} pila;

typedef pila *PILA;

PILA crearPila();

void manejaError(int);
void apilar(PILA, TRABAJO);
TRABAJO desapilar(PILA);
int es_vaciaPila(PILA);
TRABAJO elemTope(PILA);

void liberarPila(PILA);

#endif