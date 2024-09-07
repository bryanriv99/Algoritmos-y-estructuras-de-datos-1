#include "pila.h"
#include<stdio.h>
#include<stdlib.h>

void datosEntrada(PILA);
void mostrarPila(PILA);
void manejaMsg(int);
void lleTexto(PILA);
void analizaTexto(PILA);
PILA invertir(PILA);
void mostrarTexto(PILA);
void leeTexto(PILA);

void main(){
    PILA P = crearPila();
    leeTexto(P);
    analizaTexto(P);
}
void mostrarTexto(PILA P){
    mostrarPila(P);
}

void analizaTexto(PILA P){
    PILA aux = crearPila();
    aux = invertir(P);
    char n,m;
    PILA a = crearPila();
    PILA mos = crearPila();
    PILA auxmos = crearPila();
    PILA arr = crearPila();

    while(!es_vaciaPila(aux)){
        n=desapilar(aux);
        if(n=='@'){
            apilar(arr,m);
            while(!es_vaciaPila(aux)){
                m=desapilar(aux);
        
            }
            mostrarPila(aux);
            printf("\nSe elimino la linea\n");
        } else{if(n=='#'){
            apilar(a,n);
            if(!es_vaciaPila(aux)){
                apilar(a,desapilar(mos));
            }
        }else{apilar(mos,n);}
        
        }
    }
    if(es_vaciaPila(arr)){
        auxmos = invertir(mos);
        mostrarTexto(auxmos);
    }
}

void leeTexto(PILA S){
    datosEntrada(S);
}

PILA invertir(PILA P){
    PILA aux = crearPila();
    char n;
    while(!es_vaciaPila(P)){
        n=desapilar(P);
        apilar(aux, n);
    }
    return aux;
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
    if(!es_vaciaPila(S)){   
        while (actual != NULL) {
            printf("%c ", actual->dato);
            actual = actual->anterior;
        }
        printf("\n");
    }else{manejaMsg(2);}

}


void manejaMsg(int msg) {
    char *mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .", "Pila vacia . . .", "Pila llena . . ."};
    printf("%s\n", mensajes[msg]);
}

