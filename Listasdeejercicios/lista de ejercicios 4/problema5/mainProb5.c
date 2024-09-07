#include<stdio.h>
#include "prob5.h"
#include <stdlib.h>

void datosEntrada(PILA);
void mostrarPila(PILA);
void manejaMsg(int msg);
void elempila(PILA);
void elemfondo(PILA);
void copiapila(PILA);
void menu(PILA);

void main(){
    PILA P1;
    P1 = crearPila();
    menu(P1);

}

void datosEntrada(PILA S){
    int op;
    char num;
    do {
        printf ("Ingresa un dato\n");
        scanf(" %c", &num);  // Agregar un espacio para consumir el carácter de nueva línea
        apilar(S, num);
        printf("--0) Dejar de insertar datos--\n--1) Insertar otro dato--\n");
        scanf("%d", &op);
    } while (op);
}

void mostrarPila(PILA S){
	PILA aux;
	aux=crearPila();
    while (es_vaciaPila(S) != TRUE)
    {   int v;
    	v=desapilar(S);
    	apilar(aux,v);
        printf("-> %c\n", v );
    }
    while(es_vaciaPila(aux)!= TRUE){
    apilar(S,desapilar(aux));
}
}
//da la cantidad de elementos de la pila
void elempila(PILA S){
    PILA a,b;
    int cont = 0;
    a = crearPila();
    b = crearPila();
    while (!es_vaciaPila(S)) {
        char x = desapilar(S);
        apilar(a, x);
        cont++;
    }
    printf("\nLa cantidad de elementos de la pila son: %d\n",cont);
}

//da el elemento del fondo de la pila
void elemfondo(PILA S){
    PILA a,b;
    a = crearPila();
    b = crearPila();
    while(!es_vaciaPila(S)){
        char x = desapilar(S);
        apilar(a,x);
    }
    
        char z = desapilar(a);

    printf("El elemento del fondo es: %c",z);
}

//copia de una pila a otra
void copiapila(PILA S){
    PILA a,b;
    a=crearPila();
    b=crearPila();

    printf("\nPila original\n");
    mostrarPila(S);

    while(!es_vaciaPila(S)){
        char x=desapilar(S);
        apilar(a,x);
    }
    

    while(!es_vaciaPila(a)){
        char z=desapilar(a);
        apilar(b,z);
    }
    
    printf("\nCopia de la pila\n");
    mostrarPila(b);
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .","Pila vacia . . .","Pila llena . . ."};
     printf("%s", mensajes[msg]);
}

void menu(PILA S) {
    int respuesta; 
    PILA a,b,c,d;
    a=crearPila();
    b=crearPila();
    c=crearPila();
    d=crearPila();

    while (respuesta != -1) {
        printf("\n\nMenu: \n1) Insertar Pila \n2) Calcular numero de elementos \n3) Elemento del fondo de la pila \n4) Copiar una pila a otra \n0) Salir\nIntroduzca una opcion: ");
        scanf("%d", &respuesta);
        switch (respuesta) {
            case 1:
                datosEntrada(S);
                break;
            case 2:
                elempila(S);
                break;
            case 3:
                elemfondo(S);
                break;
            case 4: copiapila(S);
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
