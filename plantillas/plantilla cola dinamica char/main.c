#include "cola.h"
#include <stdio.h>
#include <stdlib.h>

void manejaMsg(int);
void leerDatos(COLA cola);
void mostrarCola(COLA);

int main() {
    COLA cola = crearCola();
    leerDatos(cola);
    mostrarCola(cola);

    return 0;
}

void leerDatos(COLA cola) {
    int opcion;
    char elemento;

    do {
        printf("Ingrese un elemento a la cola: ");
        scanf(" %c", &elemento);  // Se cambió el formato a %c para leer caracteres
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
        printf("%c ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

void manejaMsg(int msg) {
    char *mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .", "Pila vacía . . .", "Pila llena . . .","Cola llena . . .","Cola vacia . . ."};
    printf("%s\n", mensajes[msg]);
}
