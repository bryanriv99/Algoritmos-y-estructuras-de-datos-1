#include "ecuacion.h"

void manejaMsg(int);
void liberarMem(ECUACION);
void darEcuacion(ECUACION);
void mostrarEcuacion(ECUACION);

void main(){
    ECUACION E1;
    E1=crearEcuacion();
    darEcuacion(E1);
    mostrarEcuacion(E1);
    printf("la raiz real de la ecuacion es: %d\n",raizReal(E1));
    raizcompleja(E1);
}
void darEcuacion(ECUACION E1){
    int n;
    printf("Asigna el valor de A\n");
    scanf("%d",&n);
    asignaA(E1,n);

    printf("Asigna el valor de B\n");
    scanf("%d",&n);
    asignaB(E1,n);

    printf("Asigna el valor de C\n");
    scanf("%d",&n);
    asignaC(E1,n);
}

void mostrarEcuacion(ECUACION E1){
    printf("Ecuacion  %d x^2 + %d x + %d \n", obtenA(E1), obtenB(E1), obtenC(E1));
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  "};
     printf("%s", mensajes[msg] );
}

void liberarMem(ECUACION E1){
    free(E1);
    manejaMsg(1);
}