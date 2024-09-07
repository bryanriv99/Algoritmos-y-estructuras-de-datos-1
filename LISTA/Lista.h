#ifndef LISTA_LISTA_H
#define LISTA_LISTA_H
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
typedef struct Nodo_Lista{
    int dato;
    struct Nodo_Lista *siguiente;
}Nodo_Lista;

typedef Nodo_Lista * LISTA;

LISTA crearLista();
Nodo_Lista *crearNodoLista();
LISTA insertar(LISTA L, int e);
int es_vaciaLista(LISTA L);
void mostrarLista(LISTA L);
void buscarElem(LISTA L, int elem);
void mensajes(int e, int msg, int p);
void manejaError(int n);
LISTA borrar(LISTA L, int elem);
#endif //LISTA_LISTA_H