#include <stdio.h>
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
    C->primero = NULL;
    C->ultimo = NULL;
    return C;
}

Nodo_Cola *crearNodoCola() {
    Nodo_Cola *nvo;
    nvo = (Nodo_Cola *)malloc(sizeof(Nodo_Cola));
    if (nvo == NULL) {
        manejaMsg(0);
        exit(0);
    }
    return nvo;
}

int es_vaciaCola(COLA C) {
    return (C->primero == NULL && C->ultimo == NULL) ? TRUE : FALSE;
}

int primero(COLA C) {
    if (es_vaciaCola(C) == TRUE) {
        manejaMsg(5);
        exit(0);
    }
    return C->primero->dato;
}

void encolar(COLA C, int e) {
    Nodo_Cola *nvo;

    nvo = crearNodoCola();
    nvo->dato = e;
    nvo->siguiente = NULL;

    if (es_vaciaCola(C) == TRUE) {
        C->primero = nvo;
        C->ultimo = nvo;
    } else {
        C->ultimo->siguiente = nvo;
        C->ultimo = nvo;
    }
}

int desencolar(COLA C) {
    int v;
    Nodo_Cola *aux;

    if (es_vaciaCola(C) == TRUE) {
        manejaMsg(5);
        exit(0);
    }

    aux = C->primero;
    v = aux->dato;
    C->primero = aux->siguiente;

    if (C->primero == NULL) {
        C->ultimo = NULL;
    }

    free(aux);
    return v;
}

