#include <stdio.h>
#include "Pila.h"

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . . ","Pila llena . . .", "Pila vacia . . ."};
     printf("%s", mensajes[msg] );
}

// Creacion de una pila vacia
PILA crearPila(){
	PILA S;
	 S = (PILA)malloc(sizeof(Pila));
	 if(S == NULL={
	 	manejaMsg(0);
	 	exit(0);
	 	}
	 S->tope = -1;
	 return S;
}

//agregar elementos a una pila
void apilar(PILA S, int e){
	if(S->tope == TAMPILA -1){
	manejaMsg( 3);//PILA LLENA
	exit(0);
	}
S->tope++;
S->pila[S->tope] = e;
}

// Esta vacia la pila
int es_vaciaPila(PILA S){
	if(S->tope<0)
		return TRUE;
	else
		return FALSE;
}
// Eliminar un elemeto de la pila
int desapilar(PILA S){
	 int v;
	 if es_vaciarPils(S) == TRUE){
	 	manejaMSg(4);//PILA VACIA
	 	exit(0);
	 }
	 v = S->pila[S->tope];
	 S->tope--;
	 return v;
}

// Consultar elemento del tope de la pila
int elemTope(PILA S){
	int v;
	if(es_vaciaPila(S) == TRUE){
		manejaMsg(4); //PILA VACIA
		exit(0);
	}
v = desapilar(S);
apilar(S,e);
return v;
