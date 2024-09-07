#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void manejaMsg(int msg);

PILA crearPila() {
    PILA S;
    S = (PILA)malloc(sizeof(Nodo_Pila));
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

char *elemTope(PILA S) {
    char *v;
    if (es_vaciaPila(S) == TRUE) {
        manejaMsg(2); // PILA VACIA
        exit(0);
    }
    v = strdup(S->tope->dato);
    return v;
}

void apilar(PILA S, const char *e) {
    Nodo_Pila *nvo;
    nvo = crearNodoPila();
    strncpy(nvo->dato, e, MAX_LONGITUD - 1);
    nvo->dato[MAX_LONGITUD - 1] = '\0';
    nvo->anterior = S->tope;
    S->tope = nvo;
}

char *desapilar(PILA S) {
    char *e;
    Nodo_Pila *aux;
    if (es_vaciaPila(S) == TRUE) {
        manejaMsg(2); // PILA VACIA
        exit(0);
    }
    aux = S->tope;
    e = strdup(aux->dato);
    S->tope = aux->anterior;
    free(aux);
    return e;
}

void manejaMsg(int msg) {
    char *mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .", "Pila vacía . . .", "Pila llena . . ."};
    printf("%s\n", mensajes[msg]);
}
