#include <stdio.h>
#include "cola.h"
#include <stdlib.h>

void manejaMsg(int);
void agregarDato(COLA);
COLA agrupaColas(COLA, COLA, COLA, COLA);
COLA mezclaCola(COLA, COLA);
void mostrarCola(COLA);
void liberarMem(COLA);

void main() {
    COLA C1, C2, C3, C4, C5;
    C1 = crearCola();
    C2 = crearCola();
    C3 = crearCola();
    C4 = crearCola();
    C5 = crearCola();

    printf("Datos C1\n");
    agregarDato(C1);
    printf("\nDatos C2\n");
    agregarDato(C2);
    printf("\nDatos C3\n");
    agregarDato(C3);
    printf("\nDatos C4\n");
    agregarDato(C4);

    C5 = agrupaColas(C1, C2, C3, C4);

    printf("\nC1:\n");
    mostrarCola(C1);
    printf("\nC2:\n");
    mostrarCola(C2);
    printf("\nC3:\n");
    mostrarCola(C3);
    printf("\nC4:\n");
    mostrarCola(C4);
    printf("\nC5:\n");
    mostrarCola(C5);

    liberarMem(C1);
    liberarMem(C2);
    liberarMem(C3);
    liberarMem(C4);
    liberarMem(C5);
}

void agregarDato(COLA C) {
    int opcion;
    char aux = 0;
    do {
        printf("Agrega el elemento a la cola:\n");
        scanf(" %c", &aux); // Usa %c para leer un carácter
        encolar(C, aux);
        printf("\nAgregar otro elemento a la cola:\nNo -0-\t Si-1-\n\n");
        scanf("%d", &opcion);
    } while (opcion != 0);
}

COLA agrupaColas(COLA C1, COLA C2, COLA C3, COLA C4) {
    COLA C5 = mezclaCola(C1, C2);
    C5 = mezclaCola(C5, C3);
    C5 = mezclaCola(C5, C4);
    return C5;
}

COLA mezclaCola(COLA C1, COLA C2) {
    COLA C3 = crearCola();
    Cola temp1 = *C1;
    Cola temp2 = *C2;
    char n;
    while (!es_vaciaCola(&temp1) && !es_vaciaCola(&temp2)) {
        encolar(C3, desencolar(&temp1));
        encolar(C3, desencolar(&temp2));
    }
    while (!es_vaciaCola(&temp1))
        encolar(C3, desencolar(&temp1));
    while (!es_vaciaCola(&temp2))
        encolar(C3, desencolar(&temp2));
    return C3;
}

void mostrarCola(COLA C) {
    Cola temp = *C;
    char n;
    while (!es_vaciaCola(&temp))
        printf("%c ", desencolar(&temp));
    printf("\n");
}

void manejaMsg(int msg) {
    char* mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .  ",
                        "La Pila esta llena . . .", "La Pila esta vacia . . .", "Cola Vacia", "Cola LLena", "Cola liberada"};
    printf("%s\n", mensajes[msg]);
}

void liberarMem(COLA C) {
    free(C);
    manejaMsg(1);
}