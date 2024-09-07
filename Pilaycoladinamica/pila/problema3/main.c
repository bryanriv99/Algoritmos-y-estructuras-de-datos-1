#include "pila.h"
#include<stdio.h>
#include<stdlib.h>

void datosEntrada(PILA);
void mostrarPila(PILA);
void manejaMsg(int);
void equilibrado(char *);
void leer(char *);

int main(){
    char cad[100];
    leer(cad);
    equilibrado(cad);
    return 0;
}

void leer(char *cadena) {
  int cont = 0;

  printf("\n Introduzca la cadena: ");
  while ((cadena[cont++] = getchar()) != '\n');
  cadena[--cont] = '\0';
}

void equilibrado(char *cadena){
    PILA pa = crearPila();
    PILA pc = crearPila();
    PILA ca = crearPila();
    PILA cc = crearPila();
    PILA la = crearPila();
    PILA lc = crearPila();
    int clc = 0;
    int cla = 0;
    int ccc = 0;
    int cca = 0;
    int cpc = 0;
    int cpa = 0;
    while(cadena[cpa] != '\0'){
        if(cadena[cpa]=='('){
        apilar(pa,cadena[cpa]);
        cpa++;
        }

        if(cadena[cpc]==')'){
            apilar(pc, cadena[cpc]);
            cpc++;
        }

        if(cadena[cca]=='['){
            apilar(ca, cadena[cca]);
            cca++;
        }

        if (cadena[ccc]==']'){
            apilar(cc, cadena[ccc]);
            ccc++;
        }

        if(cadena[cla]=='{'){
            apilar(la, cadena[cla]);
            cla++;
        }

        if(cadena[clc]=='}'){
            apilar(lc, cadena[clc]);
            clc++;
        }

    }
    if(cpa==cpc){
        printf("\nLos parentesis estan equilibrados\n");
    }else{ printf("\nLos parentesis no estan equilibrados\n");}

    if(cca=ccc){
        printf("\nLos corchetes estan equilibrados\n");
    }else{printf("\nLos parentesis no estan equilibrados\n");}

    if(cla==clc){
        printf("\nLos corchetes estan equilibrados\n");
    }else{printf("\nLos corchetes no estan equilibrados\n");}
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

