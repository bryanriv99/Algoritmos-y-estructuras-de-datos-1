#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "prob2.h"

void leerExpresion(char *ent);
void manejaMsg(int e);
void liberar(PILA S);
int contarPA(char *cadena);
int contarPC(char *cadena);
void checaParentesis(int, int);
int contarCA(char *cadena);
int contarCC(char *cadena);
void checaCorchete(int, int);
int contarLA (char *cadena);
int contarLC(char *cadena);
void checaLlave(int, int);

void main(){
    Pila S;
    char ent[TAMPILA];
    crearPila(&S);
    leerExpresion(ent);
    checaParentesis(contarPA(ent),contarPC(ent));
    checaCorchete(contarCA(ent),contarCC(ent));
    checaLlave(contarLA(ent),contarLC(ent));
    liberar(S);
}

void checaParentesis(int a, int b){
    if(a==b){
        printf("\nLos parentesis estan equilibrados\n");
    }
    else printf("\nLos parentesis no estan equilibrados\n");
}

int contarPA(char *cadena) {
    int contador = 0;
    while (*cadena != '\0') {
        if (*cadena == '(') {
            contador++;
        }
        cadena++;
    }
    return contador;
}

int contarPC(char *cadena) {
    int contador = 0;
    while (*cadena != '\0') {
        if (*cadena == ')') {
            contador++;
        }
        cadena++;
    }
    return contador;
}

void checaCorchete(int a, int b){
    if(a==b){
        printf("\nLos corchetes estan equilibrados\n");
    }
    else printf("\nLos corchetes no estan equilibrados\n");
}

int contarCA(char *cadena) {
    int contador = 0;
    while (*cadena != '\0') {
        if (*cadena == '[') {
            contador++;
        }
        cadena++;
    }
    return contador;
}

int contarCC(char *cadena) {
    int contador = 0;
    while (*cadena != '\0') {
        if (*cadena == ']') {
            contador++;
        }
        cadena++;
    }
    return contador;
}

void checaLlave(int a, int b){
    if(a==b){
        printf("\nLas llaves estan equilibradas\n");
    }
    else printf("\nLas llaves no estan equilibradas\n");
}

int contarLA(char *cadena) {
    int contador = 0;
    while (*cadena != '\0') {
        if (*cadena == '{') {
            contador++;
        }
        cadena++;
    }
    return contador;
}

int contarLC(char *cadena) {
    int contador = 0;
    while (*cadena != '\0') {
        if (*cadena == '}') {
            contador++;
        }
        cadena++;
    }
    return contador;
}

void leerExpresion(char *ent){

  int pos=0;
  
  printf("\n\tEvaluacion de expresiones Postfijas\n");
  printf("\n\n Introduzca la expresion en Postfija: ");
  while( (ent[pos++] = getchar()) != '\n');
  ent[--pos]='\0';
}

void liberar(PILA S){
    free(S);
    manejaMsg(4);
}

void manejaMsg(int e){
  char * errores[]={"No hay memoria disponible\n","Pila Llena\n", "Pila Vacia\n", "\n\n Division por CERO\n", "Memoria Liberada ..."};
  printf("%s", errores[e]);
}