#include<stdio.h>
#include "complejo.h"
#include<stdlib.h>

void manejaMsg(int);
void darComplejos(COMPLEJO, COMPLEJO);
void mostrarComplejo(COMPLEJO, COMPLEJO);
void mostrarsuma(COMPLEJO);
void mostrarresta(COMPLEJO);
void mostrarpro(COMPLEJO);
void mostrardiv(COMPLEJO);
void liberarMem(COMPLEJO, COMPLEJO);
void liberarsuma(COMPLEJO);
void liberarresa(COMPLEJO);
void liberarpro(COMPLEJO);
void liberardiv(COMPLEJO);
void menu(COMPLEJO,COMPLEJO);

void main( ){
      COMPLEJO C1, C2, C3, C4, C5, C6;
      C1=crearComplejo();
      C2=crearComplejo();
      C3=crearComplejo();
       darComplejos(C1, C2);
     
      
      menu(C1,C2);


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

void mostrarComplejo(COMPLEJO C1, COMPLEJO C2){
    printf("Complejo 1  %.2f + %.2fi \n", obtenReal(C1), obtenImaginario(C1) );
    printf("Complejo 2  %.2f + %.2fi \n", obtenReal(C2), obtenImaginario(C2) ); 
}

void mostrarsuma(COMPLEJO C3){
     printf("La suma es %.2f + %.2fi \n",obtenReal(C3), obtenImaginario(C3));
}

void mostrarresta(COMPLEJO C4){
     printf("La resta es %.2f + %.2fi \n",obtenReal(C4), obtenImaginario(C4));
}

void mostrarpro(COMPLEJO C5){
     printf("El producto es %.2f + %.2fi \n",obtenReal(C5), obtenImaginario(C5));
}

void mostrardiv(COMPLEJO C6){
     printf("La division es %.2f + %.2fi \n",obtenReal(C6), obtenImaginario(C6));
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible ...\n"};
     printf("%s", mensajes[msg] );
}

void liberarMem(COMPLEJO C1, COMPLEJO C2){
    free(C1);
    free(C2);
    manejaMsg(1);
}

void liberarsuma(COMPLEJO C3){
    free(C3);
    manejaMsg(1);
}

void liberarresta(COMPLEJO C4){
    free(C4);
    manejaMsg(1);
}

void liberarpro(COMPLEJO C5){
    free(C5);
    manejaMsg(1);
}

void liberardiv(COMPLEJO C6){
    free(C6);
    manejaMsg(1);
}

void menu(COMPLEJO C1, COMPLEJO C2){
    int respuesta;
    COMPLEJO C3, C4, C5, C6;

    while(respuesta!=-1){
        printf("\n\nMenu: \n1)Suma \n2)Resta \n3)Multiplicacion \n4)Division \n5)Mostrar complejo \n0)Salir\nIntroduzca una opcion: ");
        scanf("%d",&respuesta);
        switch (respuesta){
    case 1: C3 = suma(C1, C2);
      mostrarsuma(C3);
        break;

    case 2: C4 = resta(C1, C2);
     mostrarresta(C4);
        break;

    case 3: C5 = producto(C1, C2);
     mostrarpro(C5);
        break;

    case 4: C6 = division(C1, C2);
     mostrardiv(C6);
        break;

     case 5: mostrarComplejo(C1,C2);
          break;

    case 0: respuesta= -1;
        break;
    default: printf("\nIntroduzca una opcion valida!: ");
        break;
    }
    }

}
