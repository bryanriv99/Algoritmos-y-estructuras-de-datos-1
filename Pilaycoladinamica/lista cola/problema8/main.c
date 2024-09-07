#include <stdio.h>
#include <stdlib.h>
#include "cola.h"

void leerDatos(COLA cola);
COLA interseccion(COLA cola1, COLA cola2);
void mostrarCola(COLA cola);

int main() {
    COLA colaA, colaB, colaC;

    colaA = crearCola();
    colaB = crearCola();
    colaC = crearCola();

    printf("Cola A:\n");
    leerDatos(colaA);

    printf("\nCola B:\n");
    leerDatos(colaB);

    colaC = interseccion(colaA, colaB);

    printf("\nCola C (Interseccion):\n");
    mostrarCola(colaC);

    liberarCOLA(colaA);
    liberarCOLA(colaB);
    liberarCOLA(colaC);

    return 0;
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

COLA interseccion(COLA cola1, COLA cola2) {
    COLA colaInterseccion = crearCola();
    
    while (!es_vaciaCola(cola1) && !es_vaciaCola(cola2)) {
        int elemento1 = primero(cola1);
        int elemento2 = primero(cola2);

        if (elemento1 == elemento2) {
            encolar(colaInterseccion, desencolar(cola1));
            desencolar(cola2); // Avanzar en la cola2
        } else if (elemento1 < elemento2) {
            desencolar(cola1);
        } else {
            desencolar(cola2);
        }
    }

    return colaInterseccion;
}

void mostrarCola(COLA cola) {
    COLA colaAux = crearCola();

    while (!es_vaciaCola(cola)) {
        int elemento = desencolar(cola);
        printf("%d ", elemento);
        encolar(colaAux, elemento);
    }

    while (!es_vaciaCola(colaAux)) {
        encolar(cola, desencolar(colaAux));
    }

    printf("\n");
    liberarCOLA(colaAux);
}
void manejaMsg(int msg){
    char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
    "La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola LLena","Cola liberada"};
    printf("%s\n", mensajes[msg] );
}