#include<stdio.h>
#include "fraccion.h"
#include<stdlib.h>

void manejaMsg(int);
void darFracciones(FRACCION, FRACCION);
void mostrarFraccion(FRACCION, FRACCION);
void mostrarProducto(FRACCION);
void mostrarAmplificacion(FRACCION);
void mostrarPotencia(FRACCION);

void liberarMem(FRACCION, FRACCION, FRACCION, FRACCION, FRACCION);


void main(){
      FRACCION F1, F2, F3, F4, F5;
      int ampl, pot;

      F1=crearFraccion();
      F2=crearFraccion ();
      F3=crearFraccion ();
      F4=crearFraccion ();
      F5=crearFraccion ();

      darFracciones(F1, F2);
      mostrarFraccion(F1, F2);

      F3 = producto(F1, F2);
      mostrarProducto(F3);

      if(equivalentes(F1, F2)){
      printf("Las facciones son equivalentes\n");
      }
      else{
      printf("Las fracciones no son equivalentes\n");
      }

      printf("indica con que numero se va a amplificar\n");
      scanf("%d",&ampl);
      F4 = amplificacion(F1,ampl);
      mostrarAmplificacion(F4);

      printf("indica a que potencia se va a elevar\n");
      scanf("%d",&pot);
      F5 = potencia(F1, pot);
      mostrarPotencia(F5);
     
     liberarMem(F1, F2, F3, F3, F5);
}


void darFracciones(FRACCION F1, FRACCION F2){
     int n, d;
     printf("Dar el numerador de la fraccion 1\n");
     scanf("%d", &n);
     asignaNum(F1, n);
     printf("Dar el denominador de la fraccion 1\n");
     scanf("%d", &d); 
     asignaDenom(F1, d);
    printf("Dar el numerador de la fraccion 2\n");
     scanf("%d", &n);
     asignaNum(F2, n);
     printf("Dar el denominador de la fraccion 2\n");
     scanf("%d", &d); 
     asignaDenom(F2, d);
}

void mostrarFraccion(FRACCION F1, FRACCION F2){
    printf("Fraccion 1  %d/%d \n", obtenNum(F1), obtenDenom(F1) );
    printf("Fraccion 2  %d/%d \n", obtenNum(F2), obtenDenom(F2) ); 
}

void mostrarProducto(FRACCION F3){
      printf("El producto es %d/%d \n", obtenNum(F3), obtenDenom(F3));
}

void mostrarAmplificacion(FRACCION F4){
      printf("La amplificacion es %d/%d \n", obtenNum(F4), obtenDenom(F4));
}

void mostrarPotencia(FRACCION F5){
      printf("La potencia es %d/%d \n", obtenNum(F5), obtenDenom(F5));
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  "};
     printf("%s", mensajes[msg] );
}
void liberarMem(FRACCION F1, FRACCION F2, FRACCION F3, FRACCION F4, FRACCION F5){
    free(F1);
    free(F2); 
    free(F3);
    free(F4);
    free(F5);

    manejaMsg(1);
}