#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void llenar(LISTA*);
void liberarLista(LISTA);
void manejaMsg(int);
int mayor(LISTA);
int menor(LISTA);
int promedio(LISTA);

void main(){
    LISTA L = crearLista();
    llenar(&L);
    printf("El numero mayor de la lista es: %d\n",mayor(L));
    printf("El numero menor de la lista es: %d\n",menor(L));
    printf("El promedio de la lista es: %d\n", promedio(L));
}

int promedio(LISTA L){
    int suma = 0;
    int cont = 0;
    int aux;
    if(es_vaciaLista(L)==TRUE){
        manejaMsg(1);//LISTA vacia
        exit(0);
    }
    //se utiliza nodo lista para poder apuntar al primer nodo
    Nodo_Lista *actual = L;
    int prom = actual->dato;
    while(actual!=NULL){
        suma += actual->dato;
        cont++;
        actual = actual->siguiente;
    }
    aux = suma / cont;
    return aux;
}

int mayor(LISTA L){
    if(es_vaciaLista(L)==TRUE){
        manejaMsg(1);//LISTA vacia
        exit(0);
    }
    //se utiliza nodo_lista para que apunte al primer nodo de la lista
    Nodo_Lista *actual = L;
    int mayor = actual->dato;
    while(actual!=NULL){
        if(actual->dato > mayor){
            mayor = actual->dato;
        }
        actual = actual->siguiente;
    }
    return mayor;
}

int menor(LISTA L){
    if(es_vaciaLista(L)==TRUE){
        manejaMsg(1);//LISTA vacia
        exit(0);
    }
    //Seutuliza nodo_lista para que apunnte al primer nodo de la lista
    Nodo_Lista *actual = L;
    int menor = actual->dato;
    while(actual!=NULL){
        if(actual->dato < menor){
            menor = actual->dato;
        }
        actual = actual->siguiente;
    }
    return menor;
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
