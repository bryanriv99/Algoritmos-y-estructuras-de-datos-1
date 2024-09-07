#include "pila.h"
#include<stdio.h>
#include<stdlib.h>

void datosEntrada(PILA);
void mostrarPila(PILA);
void manejaMsg(int);
void pares(PILA);
PILA invertir(PILA);

void main(){
    PILA P = crearPila();
    datosEntrada(P);
    pares(P);
}

void pares(PILA P){
    int t;
    PILA temp = crearPila();
    while(!es_vaciaPila(P)){
        t = desapilar(P);
        if(t%2 == 0){
            apilar(temp, t);
        }
    }
    PILA i = invertir(temp);
    mostrarPila(i);
}

PILA invertir(PILA P){
    PILA temp = crearPila();
    int t;
    while(!es_vaciaPila(P)){
        t = desapilar(P);
        apilar(temp, t);
    }
    return temp;
}

void datosEntrada(PILA S) {
    int op;
    int caracter;
    do {
        printf("Ingresa un caracter: ");
        scanf(" %d", &caracter);
        apilar(S, caracter);
        printf("--0) Dejar de insertar caracteres--\n--1) Insertar otro caracter--\n");
        scanf("%d", &op);
    } while (op);
}

void mostrarPila(PILA S) {
    Nodo_Pila *actual = S->tope;

    printf("Pila: ");
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->anterior;
    }
    printf("\n");
}


void manejaMsg(int msg) {
    char *mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .", "Pila vacía . . .", "Pila llena . . ."};
    printf("%s\n", mensajes[msg]);
}

