#include "cola.h"
#include<stdio.h>
#include<stdlib.h>

void manejaMsg(int);
void leerDatos(COLA cola);
void mostrarCola(COLA);
COLA interseccion(COLA, COLA);
void mostrar(COLA);

void main(){
    COLA C1 = crearCola();
    COLA C2 = crearCola();
    printf("Ingresa los datos de la cola 1:\n");
    leerDatos(C1);
    printf("\nIngresa los datos de la cola 2:\n");
    leerDatos(C2);
    mostrar(interseccion(C1,C2));
    
}

COLA copia(COLA C){
    COLA aux = crearCola();
    int n;
    while(!es_vaciaCola(C)){
        n = desencolar(C);
        encolar(aux,n);
    }
    return aux;
}

void mostrar(COLA C){
    printf("\nLa cola ordenada es:\n");
    mostrarCola(C);
}

COLA interseccion(COLA C1, COLA C2){
    COLA aux = crearCola();

    while(!es_vaciaCola(C1) && !es_vaciaCola(C2)){
        int n = primero(C1);
        int m = primero(C2);
        if(n == m){
            desencolar(C2);
            encolar(aux,desencolar(C1));
        }else if(n<m){
            desencolar(C1);
        }else{
            desencolar(C2);
        }
    }
    return aux;
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