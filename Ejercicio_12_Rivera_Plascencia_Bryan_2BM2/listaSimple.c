#include "listaSimple.h"
#include<stdio.h>
#include<stdlib.h>

void manejaMsg(int n);

LISTA crearLista(){
    LISTA L;
    L = NULL;
    return L;
}

int es_vaciaLista(LISTA L){
    if( L == NULL)
        return TRUE;
    else
        return FALSE;
}

Nodo_Lista * crearNodoLista(){
    Nodo_Lista * nvo;
    nvo = (Nodo_Lista *)malloc(sizeof(Nodo_Lista));
    if(nvo == NULL){
        manejaMsg(0);
        exit(0); 
    }
    return nvo;
}

LISTA insertar(LISTA L, Mascota e){
    Nodo_Lista * nvo;
    Nodo_Lista * actual, *anterior;

    nvo = crearNodoLista();    
    nvo -> dato = e;
    if(es_vaciaLista(L)==TRUE){
        nvo ->siguiente = NULL;
        L = nvo;
    }
    else{
        actual = L;
        while(actual != NULL){
            anterior = actual;
            actual = actual -> siguiente;
        }
        nvo -> siguiente = NULL;
        anterior -> siguiente = nvo;
    }
  
    return L;
}

void visualizaLista(LISTA L){
    Nodo_Lista * actual;
    int pos;
    actual = L;
    if(es_vaciaLista(L)==TRUE){
        manejaMsg(1); //LISTA VACIA
        exit(0);
    }
    pos=1;
    while(actual != NULL){    
        mostrar(actual->dato, 1,pos); 
        pos++;
        actual = actual -> siguiente;
    }
}

void buscarElem(LISTA L, Mascota elem){
    Nodo_Lista * actual;
    int pos=1;
    actual = L;
    if(es_vaciaLista(L)==TRUE){
        manejaMsg(1); //LISTA VACIA
        exit(0);
    } 
    while(actual != NULL && elem.id != actual -> dato.id){    
        actual = actual -> siguiente;
        pos++;
    }
    if( actual == NULL)
        mostrar(elem, 0,0);//No se encuentra
    else 
        mostrar(elem, 2, pos);//indica la posicion
}

LISTA borrar(LISTA L, Mascota elem){ 
    Nodo_Lista * actual,* anterior; 
  
    if(es_vaciaLista(L) == TRUE){ 
        manejaMsg(5); // LISTA VACIA
        exit(0); 
    } 
    actual = L; 
    anterior = L;   
    while(actual != NULL && elem.id != actual->dato.id){ 
        anterior = actual; 
        actual = actual -> siguiente; 
    } 
    if(actual == NULL) 
        mostrar(elem, 0, 0); // No se encontro
    else if (anterior == actual){ 
        L = anterior -> siguiente; 
        free(anterior); 
    } 
    else {
        anterior ->siguiente = actual -> siguiente; 
        free(actual); 
    } 
    return L; 
}

void mostrar(Mascota e, int msg, int p){
    if(msg == 0)
        printf("El elemento %d no se encuentra en la lista\n", e.id);
    else if(msg == 1)
        printf("\n Nodo %d = %d, %s, %.2f\n",p,e.id, e.raza, e.peso);
    else
        printf("El elemento %d se encuentra en la posición %d\n", e.id, p);
}

