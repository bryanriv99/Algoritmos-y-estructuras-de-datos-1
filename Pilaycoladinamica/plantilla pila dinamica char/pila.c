#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

void manejaMsg(int msg);

// CREACION DE UNA PILA VACÍA
PILA crearPila ( ){
	PILA S;
	S = (PILA)malloc(sizeof(Nodo_Pila));
	if( S == NULL){
		manejaMsg(0); 
		exit(0);
	}
        S -> tope = NULL;
        return S;
}


// ESTA VACÍA LA PILA
int es_vaciaPila(PILA S){
	if( S-> tope == NULL)
		return TRUE;
	else
		return FALSE;
}

// CREA UN ELEMENTO DE LA PILA
Nodo_Pila * crearNodoPila(  ){
   Nodo_Pila * nvo;
   nvo = (Nodo_Pila *)malloc(sizeof(Nodo_Pila));
   if(nvo == NULL){
      manejaMsg(0);
      exit(0); 
   }
   return nvo;
}

// CONSULTAR EL ELEMENTO DEL TOPE LA PILA

char elemTope(PILA S){
	char v;
	if( es_vaciaPila(S)==TRUE){
		manejaMsg(2);  //PILA VACIA
		exit(0);
	}
	v = S ->tope->dato;
	return v;
}

// AGREGAR ELEMENTOS A LA PILA

void apilar(PILA S, char e){
       Nodo_Pila * nvo;
        nvo = crearNodoPila( );	
        nvo -> dato = e;
        nvo ->anterior = S->tope;
        S-> tope = nvo;
}

// ELIMINAR UN ELEMENTO DE LA PILA

char desapilar(PILA S){
	char e;
      Nodo_Pila *  aux;
	if( es_vaciaPila(S)==TRUE){
		manejaMsg(2);  //PILA VACIA
		exit(0);
	}
	aux = S->tope;
        e = aux -> dato;
	S->tope = aux -> anterior;
        free(aux);
	return e;
}
