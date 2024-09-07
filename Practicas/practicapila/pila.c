#include<stdio.h>
#include<stdlib.h>
#include "pila.h"

void manejaMsg(int);

PILA crearPila(void){
	PILA S;
	S = (PILA)malloc(sizeof(Pila));
	if (S == NULL){
		manejaMsg(0);
        	exit(0);
	}
	S->tope = -1;
	return S;
}

void apilar(PILA S, Datos e){
	if(S->tope == TAMPILA -1){
		manejaMsg(2);
		exit(0);
	}
	S->tope++;
	S->pila[S->tope] = e;
}

int es_vaciaPila(PILA S){
	if(S->tope<0)
		return TRUE;
	else
		return FALSE;
}

Datos desapilar(PILA S){
	Datos v;
	if(es_vaciaPila(S)==TRUE){
		manejaMsg(3);
		exit(0);
	}
	v = S->pila[S->tope];
	S->tope--;
	return v;
}

Datos elemTope(PILA S){
	Datos v;
	if(es_vaciaPila(S)==TRUE){
		manejaMsg(3);
		exit(0);
	}
	v=desapilar(S);
	apilar(S,v);
	return v;
}

PIL CrearPila(void){
	PIL S;
	S = (PIL)malloc(sizeof(Pil));
	if (S == NULL){
		manejaMsg(0);
        	exit(0);
	}
	S->Tope = -1;
	return S;
}

void Apilar(PIL S, int e){
	if(S->Tope == TAMPILA -1){
		manejaMsg(2);
		exit(0);
	}
	S->Tope++;
	S->pil[S->Tope] = e;
}

int es_vaciaPil(PIL S){
	if(S->Tope<0)
		return TRUE;
	else
		return FALSE;
}
int Desapilar(PIL S){
    int v;
    if(es_vaciaPil(S) == TRUE){
        manejaMsg(3); //PILA VACIA
        exit(0);
    }
    v = S -> pil[S-> Tope];
    S -> Tope--;
    return v;
}

