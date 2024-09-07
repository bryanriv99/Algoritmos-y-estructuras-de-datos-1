#include "cola.h"
#include<stdio.h>
#include<stdlib.h>

void manejaMsg(int);
void leerDatos(COLA cola);
void mostrarCola(COLA);
void menu();

void main(){
    
}

void menu(){
    int respuesta;
    while(respuesta != -1){
        printf("1) opcion 1\n 2)opcion dos\n 3) opcion 3\n 0) salir\n");
        scanf("%d",&respuesta);
        switch (respuesta)
        {
        case 1:
            printf("hola\n");
            break;
        
        case 2:
            printf("adios\n");
            break;

        case 3:
            printf("como estas?\n");
            break;

        default:
        printf("Opcion invalida");
            break;
        }
    }
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