#include "pila.h"
#include <stdlib.h>


void maneMsg(int);

PILA crearPila(){

    PILA S;
    S = (PILA)malloc(sizeof(Pila));
    if(S == NULL){
        maneMsg(0);
        exit(0);
    }
    S->tope = -1;
    return S;

}


void apilar(PILA S, int elem){

    if(S->tope == TAMPILA -1){
        maneMsg(2);
        exit(0);
    }
    S->tope++;
    S->pila[S->tope] = elem;

}


int es_vaciaPila(PILA S){

    if(S->tope < 0)
        return TRUE;
    else
        return FALSE;
}

int desapilar(PILA S){
    int v;
    if(es_vaciaPila(S) == TRUE){
        maneMsg(3);
        exit(0);
    }

    v = S->pila[S->tope];
    S->tope--;
    return v;

}


int elemTope(PILA S){
     int v;
    if(es_vaciaPila(S) == TRUE){
        maneMsg(2);
        exit(0);
    }
    v = desapilar(S);
    apilar(S, v);
    return v;
}