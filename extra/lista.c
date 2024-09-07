#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void manejaMsg(int n);

// CREACION DE UNA LISTA VACÍA
LISTA crearLista(  ){
	LISTA L;
	L = NULL;
        return L;
}

// VERIFICA SI ESTA VACÍA LA LISTA
int es_vaciaLista(LISTA L){
	if( L == NULL)
		return TRUE;
	else
		return FALSE;
}

// CREA UN ELEMENTO DE LA LISTA
Nodo_Lista * crearNodoLista(  ){
   Nodo_Lista * nvo;
   nvo = (Nodo_Lista *)malloc(sizeof(Nodo_Lista));
   if(nvo == NULL){
      manejaMsg(0);
      exit(0); 
   }
   return nvo;
}

LISTA insertar(LISTA L, TNodoMedico e){
    Nodo_Lista * nvo;
	Nodo_Lista * actual, *anterior;

    nvo = crearNodoLista( );	
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
       
// MOSTRAR LOS ELEMENTOS DE LA LISTA
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


// BUSCAR UN ELEMENTO DE LA LISTA
void  buscarElem(LISTA L, TNodoMedico elem){
   Nodo_Lista * actual;
   int pos=1;
   actual = L;
    if(es_vaciaLista(L)==TRUE){
	manejaMsg(1); //LISTA VACIA
	exit(0);
    }
     while(actual != NULL && elem.listaPaci->infoPaci.diagnostico != actual->dato.listaPaci->infoPaci.diagnostico){	
	actual = actual -> siguiente;
  	pos++;
     }
     if( actual == NULL)
           mostrar(elem, 0,0);//No se encuentra
else 
	mostrar(elem, 2, pos);//indica la posicion
}


void mostrar(TNodoMedico e, int msg, int p){
    int i;

    if(msg == 0)
	 printf("El elemento %d no se encuentra en la lista\n", e);
    else if(msg == 1)
	  printf("\n Nodo %d = %s, %s, %s\n",p,e.listaPaci->infoPaci.nombre,e.listaPaci->infoPaci.NumHistoria,e.listaPaci->infoPaci.diagnostico);
    else
       printf("El elemento %d se encuentra en la posición %d\n", e, p);
}