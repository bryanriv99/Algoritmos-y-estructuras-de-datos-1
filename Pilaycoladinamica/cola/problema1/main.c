#include "cola.h"
#include<stdio.h>
#include<stdlib.h>

void manejaMsg(int);
void leerDatos(COLA);
void mostrarCola(COLA);
int tamCola(COLA);
void mostrar(int);

void main(){
    COLA C = crearCola();
    leerDatos(C);
    mostrar(tamCola(C));
    
}

void mostrar(int n){
    printf("\nEl tamano de la cola es de %d\n",n);
}

int tamCola(COLA C){
    int n;
    while(!es_vaciaCola(C)){
        desencolar(C);
        n++;
    }
    return n;
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
        printf("%d \n", actual->dato);
        actual = actual->siguiente;
    }
}

void manejaMsg(int msg) {
    char *mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .", "Pila vacía . . .", "Pila llena . . .","Cola llena . . .","Cola vacia . . ."};
    printf("%s\n", mensajes[msg]);
}