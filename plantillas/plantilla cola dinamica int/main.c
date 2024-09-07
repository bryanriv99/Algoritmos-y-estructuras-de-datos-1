#include "cola.h"
#include<stdio.h>
#include<stdlib.h>

void manejaMsg(int);
void leerDatos(COLA cola);
void mostrarCola(COLA);

void main(){
    
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