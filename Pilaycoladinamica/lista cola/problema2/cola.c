#include <stdlib.h>
#include "cola.h"

void manejaMsg(int);

COLA crearCola() {
    COLA C;
    C = (COLA)malloc(sizeof(Cola));
    if (C == NULL) {
        manejaMsg(0);
        exit(0);
    }
    C->primero = 0;
    C->ultimo = 0;
    C->tam = 0;
    return C;
}

int es_vaciaCola(COLA C) {
    if (C->tam == 0)
        return TRUE;
    else
        return FALSE;
}

int sig(int i) {
    int p;
    p = (i + 1) % TAMCOLA;
    return p;
}

void encolar(COLA C, int x) {
    if (C->tam == TAMCOLA) {
        manejaMsg(2);
        exit(0);
    }
    C->cola[C->ultimo] = x;
    C->ultimo = sig(C->ultimo);
    C->tam++;
}

int desencolar(COLA C) {
    int v;
    if (es_vaciaCola(C) == TRUE) {
        manejaMsg(3);
        exit(0);
    }
    v = C->cola[C->primero];
    C->primero = sig(C->primero);
    C->tam--;
    return v;
}

int primero(COLA C) {
    int v;
    if (es_vaciaCola(C) == TRUE) {
        manejaMsg(3);
        exit(0);
    }
    v = C->cola[C->primero];
    return v;
}

