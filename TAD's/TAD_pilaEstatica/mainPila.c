#include<stdio.h>
#include "Pila.h"
#include <stdlib.h>

void datosEntrada(PILA);
void mostrarPila(PILA);
void manejaMsg(int msg);
void elemMayor(PILA);

void main(){
    PILA P1;
    P1 = crearPila();
    datosEntrada(P1);
    elemMayor(P1);
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
    int i=1;
    while (es_vaciaPila(S) != TRUE)
    {
        printf("-> %d\n", desapilar(S));
    }
    
}

void elemMayor(PILA S) {
    int mayor = -1; 
    PILA a = crearPila(); 

    while (!es_vaciaPila(S)) {
        int elemento = desapilar(S);
        if (elemento > mayor) {
            mayor = elemento; 
        }
        apilar(a, elemento);
    }

    printf("Elemento mayor: %d\n", mayor);
    printf("--------------------------------------------------\n");
    printf("Cadena:\n\n");
 
   mostrarPila(a);


    free(a);
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .","Pila vacia . . .","Pila llena . . ."};
     printf("%s", mensajes[msg] );
}