#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "cola.h"
#include <ctype.h>

void manejaMsg(int);
PILA invertirPila(PILA S);
void mostrarPila(PILA S);
COLA invertirCola(COLA C);
void mostrarCola(COLA C);
void solicitarCadena(char *cadena);
int esPalindromo(char *cadena);

void main() {
    char cadena[100];

    solicitarCadena(cadena);

    if (esPalindromo(cadena)==1) {
        printf("\n%s es un palindromo\n", cadena);
    } else {
        printf("\n%s no es un palindromo\n", cadena);
    }
}

void solicitarCadena(char *cadena) {
    printf("Ingresa una cadena:\n");
    scanf("%[^\n]s", cadena);
}

void mostrarPila(PILA S) {
    printf("Pila:");
    while (!es_vaciaPila(S)) {
        printf("%c ", desapilar(S));
    }
    printf("\n");
}

void mostrarCola(COLA C) {
    printf("Cola:");
    while (!es_vaciaCola(C)) {
        printf("%c ", desencolar(C));
    }
    printf("\n");
}

int esPalindromo(char *cadena) {
    PILA pila = crearPila();
    COLA cola = crearCola();
    PILA auxP;
    COLA auxC;

    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] != ' ') {
            apilar(pila, tolower(cadena[i]));
            encolar(cola, tolower(cadena[i]));
        }
    }
    auxP = pila;
    auxC = cola;

    while (!es_vaciaPila(auxP) && !es_vaciaCola(auxC)) {
        if (desapilar(auxP) != desencolar(auxC)) {
            return 0;
        }
        else{
            return 1;}
    }

    
}
void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
    "La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola LLena","Cola liberada"};
	printf("%s", mensajes[msg] );
}