#include<stdio.h>
#include "prob5.h"
#include<stdlib.h>

void manejaMsg(int msg);

//Creacion de una pila vacia
PILA crearPila(){
    PILA S;
    S = (PILA)malloc(sizeof(Pila));
    if(S == NULL){
        manejaMsg(0);
        exit(0);
    }
    S -> tope = -1;
    return S;
}

// Agregar elementos a la Pila
void apilar(PILA S, int e){
    if(S -> tope == TAMPILA -1){
        manejaMsg(4);// PILA LLENA
        exit(0);
    }
    S -> tope++;
    S -> pila[S -> tope] = e;
}

//Esta vacia la Pila
int es_vaciaPila(PILA S){
    if(S -> tope < 0)
        return TRUE;
    else 
        return FALSE;
}

//Eliminar un elemento de la Pila
int desapilar(PILA S){
    int v;
    if(es_vaciaPila(S) == TRUE){
        manejaMsg(3); //PILA VACIA
        exit(0);
    }
    v = S -> pila[S-> tope];
    S -> tope--;
    return v;
}

//Consultar el elemento del tope de la Pila 
int elemTope(PILA S){
    int v;
    if(es_vaciaPila(S) == TRUE){
        manejaMsg(3);//PILA VACIA
        exit(0);
    }
    v = desapilar(S);
    apilar(S,v);
    return v;
}
