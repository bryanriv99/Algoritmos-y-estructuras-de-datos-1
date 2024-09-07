#include "natural.h"

void manejaMsg(int);


NATURAL crearNatural(int entero) {
    NATURAL natural = (NATURAL)malloc(sizeof(Natural));
    natural->valor = entero;
    return natural;
}


int esCero(NATURAL natural) {
    return natural->valor == 0;
}


NATURAL sucesor(NATURAL natural) {
    natural->valor++;
    return natural;
}


int esMenor(NATURAL natural1, NATURAL natural2) {
    return natural1->valor < natural2->valor;
}


int esMenorIgual(NATURAL natural1, NATURAL natural2) {
    return natural1->valor <= natural2->valor;
}


int esMayor(NATURAL natural1, NATURAL natural2) {
    return natural1->valor > natural2->valor;
}


int esMayorIgual(NATURAL natural1, NATURAL natural2) {
    return natural1->valor >= natural2->valor;
}

NATURAL predecesor(NATURAL natural) {
    natural->valor--;
    return natural;
}