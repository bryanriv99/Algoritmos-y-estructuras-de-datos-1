#include <stdio.h>
#include "prob1.h"
#include <stdlib.h>
void datosEntrada(PILA);
void mostrarPila(PILA);
void manejaMsg(int);
void leerExpresion(char *);
int contarA(char *);
int contarC(char *);
void checaParentesis(char *);

void main() {
    char S[100];
    leerExpresion(S);
    checaParentesis(S);


}

void checaParentesis(char *cad){
    int n,m;
    n=contarA(cad);
    m=contarC(cad);
    if(n==m){
        printf("\nLos parentesis estan equilibrados.\n");
    }else{printf("\nLosparentesis no estan equilibrados.\n");}

}

void leerExpresion(char *ent){

  int pos=0;
  
 
  printf("\n\n Introduzca la expresion en Postfija: ");
  while( (ent[pos++] = getchar()) != '\n');
  ent[--pos]='\0';
}

int contarA(char *cad){
    int cont=0;
    while(*cad!='\0'){
        if(*cad=='('){
            cont++;
        }
    }
    return cont;
}

int contarC(char *cad){
    int cont=0;
    while(*cad!='\0'){
        if(*cad==')'){
            cont++;
        }
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

