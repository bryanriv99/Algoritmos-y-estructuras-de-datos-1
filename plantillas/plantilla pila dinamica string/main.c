#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

void datosEntrada(PILA);
void mostrarPila(PILA);
void manejaMsg(int);

int main() {
    PILA pila = crearPila();
    datosEntrada(pila);
    mostrarPila(pila);
    return 0;
}

void datosEntrada(PILA S) {
    int op;
    char caracter[MAX_LONGITUD];
    do {
        printf("Ingresa un caracter: ");
        scanf(" %s", caracter);
        apilar(S, caracter);
        printf("--0) Dejar de insertar caracteres--\n--1) Insertar otro caracter--\n");
        scanf("%d", &op);
    } while (op);
}

void mostrarPila(PILA S) {
    char *actual = elemTope(S);

    printf("Pila: ");
    while (actual != NULL) {
        printf("%s ", actual);
        free(actual);  // Liberar memoria asignada por strdup
        actual = desapilar(S);
    }
    printf("\n");
}
