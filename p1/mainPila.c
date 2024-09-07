#include <stdio.h>
#include "pila.h"
#include <stdlib.h>

void maneMsg(int);
 void datosEntrada(PILA);
 void llenarB(PILA, PILA);
 void mostrarPila(PILA);
 void liberarMem(PILA);
 int existe(PILA , int);
 PILA invertir(PILA);

void main(){
    PILA A, B, aux, aux2;
    
   printf("Practica 4\n");
   
   A = crearPila();
   B = crearPila();
   aux = crearPila();

   datosEntrada(A);

   llenarB(A, B);

   A = invertir(A);
   B = invertir(B);

    mostrarPila(A);
   mostrarPila(B);

   liberarMem(A);
   liberarMem(B);

}


void llenarB(PILA A, PILA B){
    PILA aux;
    aux = crearPila(A);
    int temp;


    while(!es_vaciaPila(A)){
             temp = desapilar(A);

             if(existe(A, temp)){
                    apilar(B, temp);   // Si temp aun no esta en B, lo va a apilar
             }

            apilar(aux, temp);   // en aux se le esta creando un respaldo a A
    }

    //Regresamos de aux a A
    while (!es_vaciaPila(aux))
    {
        int temp = desapilar(aux);
        apilar(A, temp);
    
    }
    liberarMem(aux);
}

int existe(PILA A, int a){
    PILA aux;
    int bandera = 0;
    aux = crearPila(A);

    while(!es_vaciaPila(A)){

        int temp = desapilar(A);   //Vaciamos la pila que recivimos
       
        if(temp == a){            //Si encuntra que el elemto ya existe en la Pila, marca la bandera 1
            bandera = 1;
        }

        apilar(aux, temp);
    }

    while(!es_vaciaPila(aux)){
        int temp = desapilar(aux);              //regrresmaos a la pila original
        apilar(A, temp);
    }

    liberarMem(aux);
    return bandera;

}

PILA invertir(PILA A){
    
    PILA aux = crearPila();

      while(!es_vaciaPila(A)){
        int temp = desapilar(A);              //sacamos copia
        apilar(aux, temp);
    }
    
    return aux;

}

void datosEntrada(PILA s){

    char op;
    int elem;
    do
    {
        printf("Ingrese un elemento a la pila\n");
        scanf("%d", &elem);
        apilar(s, elem);
        printf("Quiere ingresar otro elemento a la pila? ('s' Si / 'n' No)\n");
       getchar();
        scanf("%c", &op);
    } while (op != 'n');
    
    printf("\n");

 }

void mostrarPila(PILA s){
    printf("Mostrar Pila: \n");
    while (!es_vaciaPila(s))
    {
        printf("%d\t", desapilar(s));
    }
    printf("\n");
    printf("\n");
    
 }

void liberarMem(PILA A){
    free(A);
    maneMsg(1);
 }

void maneMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ", "Pila llena. . .", "Pila vacia. . ."};
     printf("\n %s \n", mensajes[msg] );
}