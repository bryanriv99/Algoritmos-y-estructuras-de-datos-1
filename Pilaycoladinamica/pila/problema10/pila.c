#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

void manejaMsg(int msg);

PILA crearPila() {
    PILA S;
    S = (PILA)malloc(sizeof(Pila));
    if (S == NULL) {
        manejaMsg(0);
        exit(0);
    }
    S->tope = NULL;
    return S;
}

int es_vaciaPila(PILA S) {
    if (S->tope == NULL)
        return TRUE;
    else
        return FALSE;
}

Nodo_Pila *crearNodoPila() {
    Nodo_Pila *nvo;
    nvo = (Nodo_Pila *)malloc(sizeof(Nodo_Pila));
    if (nvo == NULL) {
        manejaMsg(0);
        exit(0);
    }
    return nvo;
}

Vehiculo elemTope(PILA S) {
    Vehiculo v;
    if (es_vaciaPila(S) == TRUE) {
        manejaMsg(2); // PILA VACIA
        exit(0);
    }
    v = S->tope->dato;
    return v;
}

void apilar(PILA S, Vehiculo e) {
    Nodo_Pila *nvo;
    nvo = crearNodoPila();
    nvo->dato = e;
    nvo->anterior = S->tope;
    S->tope = nvo;
}

Vehiculo desapilar(PILA S) {
    Vehiculo e;
    Nodo_Pila *aux;
    if (es_vaciaPila(S) == TRUE) {
        manejaMsg(2); // PILA VACIA
        exit(0);
    }
    aux = S->tope;
    e = aux->dato;
    S->tope = aux->anterior;
    free(aux);
    return e;
}
