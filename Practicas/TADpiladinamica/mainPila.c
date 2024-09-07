#include <stdio.h>
#include "pila.h"
#include <stdlib.h>

void datosEntrada(PILA);
void mostrarPila(PILA);
void manejaMsg(int msg);
void intercalar(PILA, PILA);
PILA invertir(PILA);

void main(){
	PILA a = crearPila();
	PILA b =crearPila();
}
PILA invertir(PILA S){
	PILA aux=crearPila();
	while(!es_vaciaPila(S)){
        char x=desapilar(S);
        apilar(aux,x);
    }
    return aux;
}

void intercalar(PILA a, PILA b){
	PILA aux= crearPila();
	PILA auxb=crearPila();

	auxb=invertir(b);
	
	while(!es_vaciaPila(a) && !es_vaciaPila(auxb)){
	char x=desapilar(a);
	apilar(aux,x);
	char y=desapilar(auxb);
	apilar(aux,y);
	}
	
	
	
}


void datosEntrada(PILA S){
    int op, num;
    do
    {
        printf ("Ingresa un dato\n");
        scanf("%d",&num);
        apilar(S,num);
        printf("--0) Dejar de insertar datos--\n--1) Insertar otro dato--\n");
        scanf("%d",&op);
    } while (op);
    
}

void mostrarPila(PILA S){
    while (es_vaciaPila(S) != TRUE)
    {
        printf("-> %d\n", desapilar(S));
    }
    
}
void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .","Pila vacia . . .","Pila llena . . ."};
     printf("%s", mensajes[msg] );
}
