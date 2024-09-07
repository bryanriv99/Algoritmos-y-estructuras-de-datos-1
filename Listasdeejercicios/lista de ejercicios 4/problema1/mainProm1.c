#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "prom1.h"

void leerExpresion(char *ent);
void manejaMsg(int e);
void liberar(PILA S);
int contarA(char *cadena);
int contarC(char *cadena);
void checaParentesis(int, int);

int main(){
    PILA S;
    char ent[TAMPILA];
    S = crearPila();
    leerExpresion(ent);
    checaParentesis(contarA(ent),contarC(ent));
    liberar(S);

    return 0;
}

void checaParentesis(int a, int b){
    if(a==b){
        printf("\nLos parentesis estan equilibrados\n");
    }
    else printf("\nLos parentesis no estan equilibrados\n");
}
int contarA(char *cadena) {
    int contador = 0;
    while (*cadena != '\0') {
        if (*cadena == '(') {
            contador++;
        }
        cadena++;
    }
    return contador;
}
int contarC(char *cadena) {
    int contador = 0;
    while (*cadena != '\0') {
        if (*cadena == ')') {
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
