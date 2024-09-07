#include<stdio.h>
#include "complejo.h"

void manejaMsg(int);
void darComplejos(COMPLEJO, COMPLEJO);
void mostrarComplejo(COMPLEJO, COMPLEJO, COMPLEJO);

void main( ){
      COMPLEJO C1, C2, C3;
      C1=crearComplejo();
      C2=crearComplejo();
      C3=crearComplejo();
       darComplejos(C1, C2);
      C3 = suma(C1, C2);
     mostrarComplejo(C1, C2, C3);
}


void darComplejos( COMPLEJO C1, COMPLEJO C2){
     float r, i;
     
     printf("Dar la parte real del complejo 1\n");
     scanf("%f", &r);
     asignaReal(C1, r);
     printf("Dar la parte imaginario del complejo 1\n");
     scanf("%f", &i); 
     asignaImaginario(C1, i);
    printf("Dar la parte real del complejo 2\n");
     scanf("%f", &r);
     asignaReal(C2, r);
     printf("Dar la parte imaginario del complejo 2\n");
     scanf("%f", &i); 
     asignaImaginario(C2, i);
}

void mostrarComplejo(COMPLEJO C1, COMPLEJO C2, COMPLEJO C3){
    printf("Complejo 1  %f + %fi \n", obtenReal(C1), obtenImaginario(C1) );
    printf("Complejo 2  %f + %fi \n", obtenReal(C2), obtenImaginario(C2) ); 
    printf("La suma es %f + %fi \n", obtenReal(C3), obtenImaginario(C3));
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible ...\n"};
     printf("%s", mensajes[msg] );
}

