#include "pila.h"
#include<stdio.h>
#include<stdlib.h>

void datosEntrada(PILA);
void mostrarPila(PILA);
void manejaMsg(int);
void suma(char *);

void main(){
    char a[7];
    printf("Ingresa el arreglo: ");
    scanf("%s",a);
    suma(a);
}

void suma(char *a){
    int i, n, m = 0;
    char p;
    PILA aux = crearPila();
    for(i=0; a[i] != '\0'; i++){
        if(a[i] >= '0' && a[i] <= '9'){
            apilar(aux, a[i]);
        }else if(a[i] == 'x'){
            desapilar(aux);
        }
    }
    while(!es_vaciaPila(aux)){
        p = desapilar(aux);
        n = atoi(&p);
        m += n;
    }
    printf("La suma es %d",m);
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

