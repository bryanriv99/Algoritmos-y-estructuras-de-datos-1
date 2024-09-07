#include "listaSimple.h"
#include <stdio.h>
#include <stdlib.h>

void llenar(LISTA*);
void liberarLista(LISTA L);
void manejaMsg(int n);
LISTA ordenar(LISTA L);

void main(){
    LISTA L = crearLista();
    llenar(&L);
    ordenar(L);
    visualizaLista(L);

}

void llenar(LISTA *AP){
    int op = 1;
    Mascota m;
    while(op==1){
        printf("Digite el numero de identificacion del animal: ");
        scanf("%d",&m.id);
        printf("Digite la raza del animal: ");
        scanf("%s",m.raza);
        printf("Digite el peso del animal: ");
        scanf("%f",&m.peso);
        *AP=insertar(*AP,m);
        printf("Desea agregar otro animal: (1.-SI 0.-NO): ");
        scanf("%d",&op);
    }
    printf("\n");
}

void liberarLista(LISTA L){
    free(L);
}

void manejaMsg(int n){
    char * errores[]={"No hay memoria disponible\n","La lista esta vacia\n"};
    printf("%s", errores[n]);
}

LISTA ordenar(LISTA L) {
    if (es_vaciaLista(L) == TRUE || L->siguiente == NULL) {
        return L; 
    }
    LISTA actual, siguiente;
    int intercambio;
    Mascota temp;

    do {
        intercambio = FALSE;
        actual = L;

        while (actual->siguiente != NULL) {
            siguiente = actual->siguiente;

            if (actual->dato.id > siguiente->dato.id) {
                temp = actual->dato;
                actual->dato = siguiente->dato;
                siguiente->dato = temp;

                intercambio = TRUE;
            }

            actual = actual->siguiente;
        }
    } while (intercambio);

    return L;
}