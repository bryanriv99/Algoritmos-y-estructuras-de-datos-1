#include <stdio.h>
#include "Pila.h"
#include "Cola.h"
#include <stdlib.h>

int esCapicua(int);
void solicitarNumero(int *);
void verificarCapicua(PILA, COLA);
void mostrarResultado(int, int );
void manejaMsg(int);
void liberarPila(PILA);

int main() {
    PILA pila;
    COLA cola;
    pila = crearPila();
    cola = crearCola();

    verificarCapicua(pila, cola);

    liberarPila(pila);
    liberarCOLA(cola);

    return 0;
}

void solicitarNumero(int *num) {
    printf("Ingresa un numero entero: ");
    scanf("%d", num);
}

int esCapicua(int num) {
    PILA pila = crearPila();
    COLA cola = crearCola();

    int temp = num;
    while (temp > 0) {
        int digito = temp % 10;
        apilar(pila, digito);
        encolar(cola, digito);
        temp /= 10;
    }

    int capicua = TRUE;
    while (!es_vaciaPila(pila) && !es_vaciaCola(cola)) {
        if (desapilar(pila) != desencolar(cola)) {
            capicua = FALSE;
            break;
        }
    }

    liberarPila(pila);
    liberarCOLA(cola);

    return capicua;
}

void verificarCapicua(PILA pila, COLA cola) {
    int num;
    solicitarNumero(&num);

    int esCapicuaNuevo = esCapicua(num);

    printf("Verificar si el numero es capicua...\n\n");
    mostrarResultado(num, esCapicuaNuevo);
}

void mostrarResultado(int num, int esCapicua) {
    printf("\nNumero introducido: %d\n", num);
    if (esCapicua) {
        printf("\nEs un numero capicua.\n\n");
    } else {
        printf("\nNo es un nmero capicua.\n\n");
    }
}
void manejaMsg(int i) {
    char *manejaMsg[] = {"No hay memoria disponible...\n",
                         "Memoria Liberada... \n",
                         "Cola Llena...\n",
                         "Cola Vacia...\n",
                         "Pila llena...\n",
                         "Pila vacia..."};
    printf("%s", manejaMsg[i]);
}
void liberarPila(PILA P){
    free(P);
    manejaMsg(1);

}
