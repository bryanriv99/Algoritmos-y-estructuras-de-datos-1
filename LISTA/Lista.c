#include "Lista.h"

#include <stdio.h>
#include <stdlib.h>

void mensajes(int e, int msg, int p);

LISTA crearLista(){
    LISTA L;
    L=NULL;
    return L;
}

Nodo_Lista *crearNodoLista(){
    Nodo_Lista * nvo;
    nvo=(LISTA)malloc(sizeof(Nodo_Lista));
    if(nvo==NULL){
        manejaError(0);
        exit(0);
    }
    return nvo;
}

LISTA insertar(LISTA L, int e){
    LISTA nvo;
    LISTA actual, anterior;
    nvo=crearNodoLista();
    nvo->dato=e;
    nvo->siguiente=NULL;
    if(es_vaciaLista(L)){
        L=nvo;
        return L;
    }else{
        actual=L;
        while (actual!=NULL){
            anterior=actual;
            actual=actual->siguiente;
        }
        anterior->siguiente=nvo;
        return L;
    }
}

void mostrarLista(LISTA L){
    LISTA actual;
    int pos;
    actual=L;
    if(es_vaciaLista(L)){
        manejaError(1);
        exit(0);
    }
    pos=1;
    while(actual!=NULL){
        mensajes(actual->dato,1,pos);
        pos++;
        actual=actual->siguiente;
    }
}

void buscarElem(LISTA L, int elem){
    LISTA actual;
    int pos=1;
    actual=L;
    if(es_vaciaLista(L)){
        manejaError(1);
        exit(0);
    }
    while(actual!=NULL && elem!=actual->dato){
        actual=actual->siguiente;
        pos++;
    }
    if(actual==NULL){
        mensajes(elem,0,0);
    }else{
        mensajes(elem,2,pos);
    }
}

LISTA borrar(LISTA L, int elem){
    LISTA actual, anterior;
    if(es_vaciaLista(L)){
        manejaError(1);
        exit(0);
    }
    actual=L;
    anterior=L;
    while(actual!=NULL && elem!= actual->dato){
        anterior=actual;
        actual=actual->siguiente;
    }
    if(actual==NULL){
        mensajes(elem,0,0);
    }else if(anterior==actual){
        L=anterior->siguiente;
        free(anterior);
    }else{
        anterior->siguiente=actual->siguiente;
        free(actual);
    }
    return L;
}

int es_vaciaLista(LISTA L){
    if(L==NULL){
        return TRUE;
    }else
        return FALSE;
}