#include <stdio.h>
#include "pila.h"
#include <stdlib.h>

void datosEntrada(PILA);
void mostrarPila(PILA);
void manejaMsg(int);
PILA invertir(PILA);

void intercalarPilas(PILA A, PILA B);

void main() {
    PILA A = crearPila();
    PILA B = crearPila();

    printf("Pila A:\n");
    datosEntrada(A);

    printf("\nPila B:\n");
    datosEntrada(B);

    intercalarPilas(A, B);

}

PILA invertir(PILA S){
	PILA aux=crearPila();
	while(!es_vaciaPila(S)){
        char x=desapilar(S);
        apilar(aux,x);
    }
    return aux;
}

void intercalarPilas(PILA A, PILA B) {
    PILA auxB = crearPila();
    PILA C=crearPila();

    auxB=invertir(B);

    // Intercalar los elementos en C según las reglas dadas
    while (!es_vaciaPila(A) || !es_vaciaPila(auxB)) {
        if (!es_vaciaPila(auxB)) {
            apilar(C, desapilar(auxB));
        }
        if (!es_vaciaPila(A)) {
            apilar(C, desapilar(A));
        }
    }
    printf("\nPILA C:\n");
    mostrarPila(C);
}

void datosEntrada(PILA S) {
    int op;
    char caracter;
    do {
        printf("Ingresa un caracter: ");
        scanf(" %c", &caracter);
        apilar(S, caracter);
        printf("--0) Dejar de insertar caracteres--\n--1) Insertar otro caracter--\n");
        scanf("%d", &op);
    } while (op);
}

void mostrarPila(PILA S) {
    Nodo_Pila *actual = S->tope;

    printf("Pila: ");
    while (actual != NULL) {
        printf("%c ", actual->dato);
        actual = actual->anterior;
    }
    printf("\n");
}


void manejaMsg(int msg) {
    char *mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .", "Pila vacía . . .", "Pila llena . . ."};
    printf("%s\n", mensajes[msg]);
}

