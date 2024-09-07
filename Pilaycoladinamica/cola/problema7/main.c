#include "cola.h"
#include "pila.h"
#include<stdio.h>
#include<stdlib.h>

void manejaMsg(int);
void leerDatos(COLA cola);
void mostrarCola(COLA);
int leerEntero();
void esCopicua(COLA, PILA, int);

void main(){
    PILA P = crearPila();
    COLA C = crearCola();
    int n = leerEntero();
    esCopicua(C,P,n);
}

void esCopicua(COLA C, PILA P, int n){
    int t = n;
    int a,i,j;
    int cont1 = 0;
    int cont2 = 0;
    PILA aux = crearPila();
    while(t != 0){
        a = t%10;
        apilar(P,a);
        encolar(C,a);
        t = t/10;
        cont2++;
    }
    while(!es_vaciaCola(C) && !es_vaciaPila(P)){
        i = desapilar(P);
        j = desencolar(C);
        if(i==j){
            apilar(aux,i);
            cont1++;
        }
    }
    if(cont1==cont2){
        printf("\n%d es copicua",n);
    }else{
        printf("\n%d no es copicua",n);
    }
}

int leerEntero(){
    int n;
    printf("Inserta el numero que quieres verificar si es copicua: ");
    scanf("%d",&n);
    printf("\n");
    return n;
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