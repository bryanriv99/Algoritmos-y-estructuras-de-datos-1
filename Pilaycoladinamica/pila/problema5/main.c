#include "pila.h"
#include<stdio.h>
#include<stdlib.h>

void datosEntrada(PILA);
void mostrarPila(PILA);
void manejaMsg(int);
int numelem(PILA);
void fondo(PILA);
PILA copiarPila(PILA);
void menu(PILA);

void main(){
    PILA P = crearPila();
    menu(P);

}

void menu(PILA S) {
    int respuesta; 

    while (respuesta != -1) {
        printf("\n\nMenu: \n1) Insertar Pila \n2) Numemro de elementos de la Pila \n3) Elemento del fondo de la pila \n4) Copiar una pila a otra \n0) Salir\nIntroduzca una opcion: ");
        scanf("%d", &respuesta);
        switch (respuesta) {
            case 1:
                datosEntrada(S);
                break;
            case 2:
                printf("\nLa pila tiene %d elementos\n",numelem(S));
                break;
            case 3:
                fondo(S);
                break;
            case 4: mostrarPila(copiarPila(S));
                break;
            case 0:
                respuesta = -1;
                break;
            default:
                printf("\nIntroduzca una opcion valida!: ");
                break;
        }
    }
}


PILA copiarPila(PILA P){
    PILA aux1 = crearPila();
    PILA aux2 = crearPila();
    int n,m;
    while(!es_vaciaPila(P)){
        n=desapilar(P);
        apilar(aux1,n);
    }
    while(!es_vaciaPila(aux1)){
        m=desapilar(aux1);
        apilar(aux2,m);
    }
    return aux2;
}

void fondo(PILA P){
    int n;
    PILA aux = crearPila();
    
    while(!es_vaciaPila(P)){
        n=desapilar(P);
        apilar(aux,n);
    }

    char m = desapilar(aux);
    
    printf("\n el elemento del fondo es %c", m);
}

int numelem(PILA P){
    int cont=0;

    while(!es_vaciaPila(P)){
        desapilar(P);
        cont++;
    }
    return cont;
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

