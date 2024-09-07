#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>


void llenar(LISTA*);
void liberarLista(LISTA L);
void mensajes(int e, int msg, int p);
void manejaError(int n);

int main()
{
    LISTA L = crearLista();
    llenar(&L);
    mostrarLista(L);

    return 0;
}

void llenar(LISTA *AP){
    int op = 1;
    int e;
    while(op==1){
        printf("Digite el numero a almacenar en la lista: ");
        scanf("%d",&e);
        *AP=insertar(*AP,e);
        printf("Desea agregar otro elemento: (1.-SI 0.-NO): ");
        scanf("%d",&op);
    }
    printf("\n");
}

void liberarLista(LISTA L){
    free(L);
}

void mensajes(int e, int msg, int p){
    int i;
    if(msg==0)
        printf("El elemento %i no se encuentra en la lista\n",e);
    else if(msg==1)
        printf("Nodo %i = %i\n",p,e);
    else
        printf("El elemento %d se encuentra en la posicion %d\n",e,p);
}

void manejaError(int n){
    char * errores[]={"No hay memoria disponible\n","La lista esta vacia\n"};
    printf("%s", errores[n]);
}

LISTA *particionar(LISTA *inicio, LISTA *fin) {
    Mascota pivote = inicio->dato;
    LISTA *p = inicio;
    LISTA *q = inicio->siguiente;

    while (q != fin) {
        if (q->dato.id < pivote.id) {
            p = p->siguiente;

            Mascota temp = p->dato;
            p->dato = q->dato;
            q->dato = temp;
        }
        q = q->siguiente;
    }


    Mascota temp = p->dato;
    p->dato = pivote;
    inicio->dato = temp;

    return p;
}

void quicksort(LISTA *inicio, LISTA *fin) {
    if (inicio != fin && inicio->siguiente != fin) {
        LISTA *pivote = particionar(inicio, fin);
        quicksort(inicio, pivote);
        quicksort(pivote->siguiente, fin);
    }
}

LISTA ordenar(LISTA L) {
    quicksort(L, NULL);
    return L;
}