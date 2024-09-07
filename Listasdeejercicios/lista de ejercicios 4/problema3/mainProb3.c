#include<stdio.h>
#include "prob3.h"
#include <stdlib.h>

void datosEntrada(PILA);
void mostrarPila(PILA);
void manejaMsg(int msg);
void identificar(PILA);

int main(){
    PILA P1;
    P1 = crearPila();
    datosEntrada(P1);
    identificar(P1);

    return 0;
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

void identificar(PILA S){
    int contPA=0;
    int contPC=0;
    int contCA=0;
    int contCC=0;
    int contLA=0;
    int contLC=0;

    PILA a,b,c,d,e,f,g,h;
    a=crearPila();
    b=crearPila();
    c=crearPila();
    d=crearPila();
    e=crearPila();
    f=crearPila();
    g=crearPila();
    h=crearPila();

    while(!es_vaciaPila(S)){
        int elemento = desapilar(S);
        if(elemento != '(' && elemento != ')' && elemento != '{' && elemento != '}' && elemento != '[' && elemento != ']'){
            apilar(a, elemento);
        } else if (elemento == '(') {
            apilar(b, elemento);
        } else if(elemento == ')') {
            apilar(c, elemento);
        } else if (elemento == '{') {
            apilar(d, elemento);
        } else if (elemento == '}') {
            apilar(e, elemento);
        } else if (elemento == '[') {
            apilar(f, elemento);
        } else if (elemento == ']') {
            apilar(g, elemento);
        }
    }
    
    while(!es_vaciaPila(b)){
        int x=desapilar(b);
        apilar(h,x);
        contPA++;
    }

    while(!es_vaciaPila(c)){
        int z=desapilar(c);
        apilar(h,z);
        contPC++;
    }
    
    while(!es_vaciaPila(d)){
        int y=desapilar(d);
        apilar(h,y);
        contLA++;
    }

    while(!es_vaciaPila(e)){
        int w=desapilar(e);
        apilar(h,w);
        contLC++;
    }

    while(!es_vaciaPila(f)){
        int q=desapilar(f);
        apilar(h,q);
        contCA++;
    }

    while(!es_vaciaPila(g)){
        int r=desapilar(g);
        apilar(h,r);
        contCC++;
    }

    if(contPA==contPC){
        printf("\nLos parentesis estan equilibrados\n");
    } else {
        printf("\nLos parentesis no estan equilibrados\n");
    }

    if(contLA==contLC){
        printf("\nLas llaves estan equilibradas\n");
    } else {
        printf("\nLas llaves no estan equilibradas\n");
    }

    if(contCA == contCC){ 
        printf("\nLos corchetes estan equilibrados\n");
    } else {
        printf("\nLos corchetes no estan equilibrados\n");
    }
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .","Pila vacia . . .","Pila llena . . ."};
     printf("%s", mensajes[msg]);
}
