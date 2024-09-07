#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void llenar(LISTA*);
void liberarLista(LISTA L);
void manejaMsg(int n);

void main(){
    LISTA L = crearLista();
    llenar(L);
    eliminar(L);
}

void llenar(LISTA *AP){
    int op = 1;
    int m;
    while(op==1){
        printf("Digite el numero: ");
        scanf("%d",&m);
        *AP = insertar(*AP, m);
        
        printf("Desea agregar otro dato: (1.-SI 0.-NO): ");
        scanf("%d",&op);
        printf("\n");
    }
    printf("\n");
}

void liberarLista(LISTA L){
    free(L);
    manejaMsg(2);
}

void manejaMsg(int n){
    char * errores[]={"No hay memoria disponible\n","La lista esta vacia\n","Memoria liberada\n"};
    printf("%s", errores[n]);
}
