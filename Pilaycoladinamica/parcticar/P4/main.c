#include "cola.h"
#include<stdio.h>
#include<stdlib.h>

void manejaMsg(int);
void leerDatos(COLA);
void mostrarCola(COLA);
void detras(COLA, int);

void main(){
    int n;
    COLA C = crearCola();
    leerDatos(C);
    printf("Dame el dato el cual necesitas saber cuantos numero hay detras: ");
    scanf("%d",&n);
    printf("\n");
    detras(C,n);
}

void detras(COLA C, int n){
    COLA aux = crearCola();
    COLA aux2 = crearCola();
    int cont = 0;
    int a;

    while(!es_vaciaCola(C)){
        a = desencolar(C);
        if(a == n){
            encolar(aux2,a);
            while(!es_vaciaCola(C)){
                a = desencolar(C);
                encolar(aux2,a);
                cont++;
            }
        }
        encolar(aux, a);
    }
    if(es_vaciaCola(aux2)==TRUE){
        printf("El elemento %d no existe\n",n);
        mostrarCola(aux);
    }else{
        printf("Hay %d elemntos detras de %d\n",cont,n);
    }
}

void leerDatos(COLA cola) {
    int opcion, elemento;

    do {
        printf("Ingrese un elemento a la cola: ");
        scanf("%d", &elemento);
        encolar(cola, elemento);

        printf("Agregar otro elemento a la cola? (1: Si, 0: No): ");
        scanf("%d", &opcion);
    } while (opcion != 0);
}


void mostrarCola(COLA C) {
    if (es_vaciaCola(C) == TRUE) {
        manejaMsg(5);
        return;
    }

    Nodo_Cola *actual = C->primero;
    printf("Cola:\n");

    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

void manejaMsg(int msg) {
    char *mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .", "Pila vacía . . .", "Pila llena . . .","Cola llena . . .","Cola vacia . . ."};
    printf("%s\n", mensajes[msg]);
}