#include "cola.h"
#include<stdio.h>
#include<stdlib.h>

void manejaMsg(int);
void leerDatos(COLA cola);
void mostrarCola(COLA);
COLA mezclaCola(COLA, COLA);

void main(){
    COLA C1=crearCola();
    COLA C2=crearCola();
    printf("\nAgrega los datos de la cola 1:\n");
    leerDatos(C1);
    printf("\nAgrega los datos de la cola 2:\n");
    leerDatos(C2);
    mostrarCola(mezclaCola(C1,C2));
}

COLA mezclaCola(COLA C1, COLA C2){
	COLA C3 = crearCola();
	Cola temp1 = *C1;
	Cola temp2 = *C2;
	int n;
	while(!es_vaciaCola(&temp1)&&!es_vaciaCola(&temp2)){
		encolar(C3, desencolar(&temp1));
		encolar(C3, desencolar(&temp2));
	}
	while(!es_vaciaCola(&temp1))
			encolar(C3, desencolar(&temp1));
	while(!es_vaciaCola(&temp2))
			encolar(C3, desencolar(&temp2));
	return C3;
}

void leerDatos(COLA cola) {
    int opcion, elemento;

    do {
        printf("Ingrese un elemento a la cola: ");
        scanf("%d", &elemento);
        encolar(cola, elemento);

        printf("Agregar otro elemento a la cola? (1: Si, 0: No): ");
        scanf("%d", &opcion);
    } while (opcion != 0);
}


void mostrarCola(COLA C) {
    if (es_vaciaCola(C) == TRUE) {
        manejaMsg(5);
        return;
    }

    Nodo_Cola *actual = C->primero;
    printf("Cola:\n");

    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

void manejaMsg(int msg) {
    char *mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .", "Pila vacía . . .", "Pila llena . . .","Cola llena . . .","Cola vacia . . ."};
    printf("%s\n", mensajes[msg]);
}