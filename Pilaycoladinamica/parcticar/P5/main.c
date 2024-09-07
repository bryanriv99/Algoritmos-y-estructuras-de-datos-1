#include "pila.h"
#include<stdio.h>
#include<stdlib.h>

void datosEntrada(PILA);
void mostrarPila(PILA);
void manejaMsg(int);
void topefondo(PILA);

void main(){
    PILA P = crearPila();
    datosEntrada(P);
    topefondo(P);
}

void topefondo(PILA P){
    PILA aux = crearPila();
    PILA aux2 = crearPila();
    int a, b, c;
    a = desapilar(P);
    apilar(aux, a);
    while(!es_vaciaPila(P)){
        b = desapilar(P);
        apilar(aux2,b);
    }
    while(!es_vaciaPila(aux2)){
        c = desapilar(aux2);
        apilar(aux, c);
    }
    mostrarPila(aux);
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

