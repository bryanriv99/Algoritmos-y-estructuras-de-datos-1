#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void manejaMsg(int n);

LISTA crearLista() {
    return NULL;
}

int es_vaciaLista(LISTA L) {
    return (L == NULL);
}

Nodo_Lista *crearNodoLista() {
    Nodo_Lista *nvo = (Nodo_Lista *)malloc(sizeof(Nodo_Lista));
    if (nvo == NULL) {
        manejaMsg(0);
        exit(0);
    }
    return nvo;
}

LISTA insertar(LISTA L, TNodoMedico e) {
    Nodo_Lista *nvo;
    Nodo_Lista *actual, *anterior;

    nvo = crearNodoLista();
    nvo->dato = e;
    if (es_vaciaLista(L) == TRUE) {
        nvo->siguiente = NULL;
        L = nvo;
    } else {
        actual = L;
        while (actual != NULL) {
            anterior = actual;
            actual = actual->siguiente;
        }
        nvo->siguiente = NULL;
        anterior->siguiente = nvo;
    }

    return L;
}

void visualizaLista(LISTA L) {
    Nodo_Lista *actual;
    int pos;
    actual = L;
    if (es_vaciaLista(L) == TRUE) {
        manejaMsg(1); // LISTA VACIA
        exit(0);
    }
    pos = 1;
    while (actual != NULL) {
        mostrar(actual->dato, 1, pos);
        pos++;
        actual = actual->siguiente;
    }
}

void buscarElem(LISTA L, TNodoMedico elem) {
    Nodo_Lista *actual;
    int pos = 1;
    actual = L;
    if (es_vaciaLista(L) == TRUE) {
        manejaMsg(1); // LISTA VACIA
        exit(0);
    }
    while (actual != NULL && strcmp(elem.listaPaci->infoPaci.diagnostico, actual->dato.listaPaci->infoPaci.diagnostico) != 0) {
        actual = actual->siguiente;
        pos++;
    }
    if (actual == NULL)
        mostrar(elem, 0, 0); // No se encuentra
    else
        mostrar(elem, 2, pos); // Indica la posición
}

LISTA borrar(LISTA L, TNodoMedico elem) {
    Nodo_Lista *actual, *anterior;

    if (es_vaciaLista(L) == TRUE) {
        manejaMsg(1); // LISTA VACIA
        exit(0);
    }
    actual = L;
    anterior = L;
    while (actual != NULL && strcmp(elem.listaPaci->infoPaci.diagnostico, actual->dato.listaPaci->infoPaci.diagnostico) != 0) {
        anterior = actual;
        actual = actual->siguiente;
    }
    if (actual == NULL)
        mostrar(elem, 0, 0); // No se encontro
    else if (anterior == actual) {
        L = anterior->siguiente;
        free(anterior);
    } else {
        anterior->siguiente = actual->siguiente;
        free(actual);
    }
    return L;
}

void mostrar(TNodoMedico e, int msg, int p) {
    int i;

    if (msg == 0)
        printf("El elemento %s no se encuentra en la lista\n", e.listaPaci->infoPaci.diagnostico);
    else if (msg == 1)
        printf("\n Nodo %d = %s\n", p, e.listaPaci->infoPaci.diagnostico);
    else
        printf("El elemento %s se encuentra en la posición %d\n", e.listaPaci->infoPaci.diagnostico, p);
}

