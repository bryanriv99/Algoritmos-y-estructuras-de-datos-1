#include <stdlib.h>
#include <stdio.h>
#include "cola.h"


void agregarDato(COLA);
int ultimoCola(COLA);
void mostrar(COLA);

void main(){
    COLA C = crearCola();
    agregarDato(C);
    int ultimo = ultimoCola(C);
    mostrar(C);
}


void agregarDato(COLA C){
    int opcion;
    int aux = 0;
    do
    {
        printf("Agrega el elemento a la cola:\n");
        scanf("%d",&aux);
        encolar(C,aux);
        printf("\nAgregar otro elemeto a la cola:\nNo -0-\t Si-1-\n\n"); 
        scanf("%d",&opcion);
    } while (opcion != 0);
}

int ultimoCola(COLA C){
    COLA tmp = crearCola();
    int aux = 0; int val;
    int n;

    while(!es_vaciaCola(C)){
        encolar(tmp, desencolar(C));
        aux++;
    }
    while(!es_vaciaCola(tmp)){
        val = desencolar(tmp);
        if(aux == 1) n = val;
        encolar(C,val);
        aux--;
    }
    return n;
}

void mostrar(COLA C){
    int aux;
    COLA tmp = crearCola();
    printf("\n\nCola: \n");
    while(!es_vaciaCola(C)){
        aux = desencolar(C);
        printf("%d ",aux);
        encolar(tmp, aux);
    }
    printf("\nY su ultimo elemento es [%d]",ultimoCola(tmp));
}

void manejaMsg(int i) {
    char *manejaMsg[] = {"No hay memoria disponible...\n",
                         "Memoria Liberada... \n",
                         "Cola Llena...\n",
                         "Cola Vacia...\n"};
    printf("%s", manejaMsg[i]);
}

