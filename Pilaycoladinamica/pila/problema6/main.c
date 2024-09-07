#include "pila.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

void intoducirelem(PILA );
void mostrarPila(PILA);
void manejaMsg(int);
void sacarelem(PILA);
PILA copiapila(PILA);
void imprimircesta(PILA);
void menu(PILA);

void main(){
    PILA P = crearPila();
    menu(P);
}

void menu(PILA S) {
    int respuesta; 

    while (respuesta != -1) {
        printf("\n\nMenu: \n1) Intorucir elemento a la cesta \n2) Sacar elemento de la cesta \n3) Imprimir elementos de la cesta \n0) Salir\nIntroduzca una opcion: ");
        scanf("%d", &respuesta);
        switch (respuesta) {
            case 1:
                intoducirelem(S);
                break;
            case 2:
                sacarelem(S);
                break;
            case 3:
                imprimircesta(S);
                break;
            case 0:
                respuesta = -1;
                break;
            default:
                printf("\nIntroduzca una opcion valida!: ");
                break;
        }
    }
}

void imprimircesta(PILA P){
    mostrarPila(P);
}

void sacarelem(PILA P){

    PILA aux1 = crearPila();
    PILA aux2 = crearPila();
    char elem[100];
    char n[100];
    printf("ingresa elemeto que deseas sacar del cesto:\n");
    scanf("%s",elem);

    while(!es_vaciaPila(P)){
        strcpy(n,desapilar(P));
        
        if(strcmp(n,elem)==0){
            apilar(aux2,n);
        }else{
            apilar(aux1,n);
        }
    }
    char j[100];
    
    if(!es_vaciaPila(aux2)){
    strcpy(j,desapilar(aux2));
    
    printf("\nSe ha sacado %s de la cesta\n",j);
    
    printf("\nLos elementos que siguen en la cesta son:\n");
    mostrarPila(aux1);
    }else{printf("El elmento igresado no existe en cesta");}

}

PILA copiapila(PILA S){
    PILA a,b;
    a=crearPila();
    b=crearPila();

    while(!es_vaciaPila(S)){
        char x[100];
        strcpy(x,desapilar(S));

        apilar(a,x);
    }
    

    while(!es_vaciaPila(a)){
        char z[100];
        strcpy(z,desapilar(a));
        apilar(b,z);
    }
    
    return b;
}

void intoducirelem(PILA S) {
    int op;
    char caracter[100];
    do {
        printf("In0gresa elemento a ingresar: ");
        scanf(" %s", &caracter);
        apilar(S, caracter);
        printf("--0) Dejar de insertar elementos--\n--1) Insertar otro elemento--\n");
        scanf("%d", &op);
    } while (op);
}

void mostrarPila(PILA S) {
    Nodo_Pila *actual = S->tope;

    printf("Pila: ");
    while (actual != NULL) {
        printf("%s ", actual->dato);
        actual = actual->anterior;
    }
    printf("\n");
}


void manejaMsg(int msg) {
    char *mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .", "Pila vacía . . .", "Pila llena . . ."};
    printf("%s\n", mensajes[msg]);
}

