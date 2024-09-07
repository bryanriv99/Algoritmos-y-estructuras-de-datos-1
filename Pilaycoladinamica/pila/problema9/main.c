#include "pila.h"
#include<stdio.h>
#include<stdlib.h>

void datosEntrada(PILA);
void mostrarPila(PILA);
void manejaMsg(int);
int solicitarvalor();
PILA conversion(PILA,int);
void mostrar(PILA,int);
PILA conv(PILA);
void most(PILA);

void main(){
    PILA P = crearPila();
    int n;
    n = solicitarvalor();
    mostrar(conversion(P,n),n);


}

void mostrar(PILA P,int n){
    printf("numero en hexadecimal: ");
    most(P);
    printf("\n numero en decimal: %d", n);
}

PILA conversion(PILA mod, int P) { 
    int  t; 
    t = P;
    while (t != 0) {
        char a;
        a = t % 16;
        apilar(mod,a);
        t = t / 16;
    }

    return mod;
}

void most(PILA P){
    int n;
    while(!es_vaciaPila(P)){
        n=desapilar(P);
        if(n<10){
            printf("%d ",n);
        }
        if(n==10){
            printf("A ");
        }
        if(n==11){
            printf("B ");
        }
        if(n==12){
            printf("C ");
        }
        if(n==13){
            printf("D ");
        }
        if(n==14){
            printf("E ");
        }
        if(n==15){
            printf("F ");
        }
    }
}

int solicitarvalor(){
    int n;
    printf("\nDame el valor el nnumero en decimal que deseas convertir a hexadecimal: ");
    scanf("%d",&n);
    printf("\n");
    return n;
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

