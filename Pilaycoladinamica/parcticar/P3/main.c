#include "cola.h"
#include<stdio.h>
#include<stdlib.h>

void manejaMsg(int);
void leerDatos(COLA);
void mostrarCola(COLA);
void intercalar(COLA, COLA, COLA);

void main(){
    COLA C1 = crearCola();
    COLA C2 = crearCola();
    COLA C3 = crearCola();
    printf("Datos de la cola 1:\n");
    leerDatos(C1);
    printf("\nDatos de la cola 2:\n");
    leerDatos(C2);
    printf("\nDatos de la cola 3:\n");
    leerDatos(C3);
    intercalar(C1,C2,C3);
}

void intercalar(COLA C1, COLA C2, COLA C3){
    COLA aux = crearCola();
    int a;
    while(!es_vaciaCola(C1) || !es_vaciaCola(C2) || !es_vaciaCola(C3)){
        if(!es_vaciaCola(C1)){
            a = desencolar(C1);
            encolar(aux, a);
        }

        if(!es_vaciaCola(C2)){
            a = desencolar(C2);
            encolar(aux, a);
        }

        if(!es_vaciaCola(C3)){
            a = desencolar(C3);
            encolar(aux, a);
        }
    }
    printf("La cola mezclada es:\n");
    mostrarCola(aux);
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