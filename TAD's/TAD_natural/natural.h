#include <stdio.h>
#include <stdlib.h>

#ifndef  _natural_
#define  _natural_

typedef struct {
    int valor;
} Natural;

typedef Natural* NATURAL;

// Declaraciones de las operaciones
NATURAL crearNatural(int entero);
int esCero(NATURAL natural);
NATURAL sucesor(NATURAL natural);
int esMenor(NATURAL natural1, NATURAL natural2);
int esMenorIgual(NATURAL natural1, NATURAL natural2);
int esMayor(NATURAL natural1, NATURAL natural2);
int esMayorIgual(NATURAL natural1, NATURAL natural2);
NATURAL predecesor(NATURAL natural);

#endif
