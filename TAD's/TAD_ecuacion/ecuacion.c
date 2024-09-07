#include "ecuacion.h"

void manejaMsg(int);

ECUACION crearEcuacion(void){
 ECUACION E;
   E = (ECUACION)malloc(sizeof(ECUACION));
   if( E == NULL){
         manejaMsg(0);
         exit(0);
    }
    return E;
}

void asignaA(ECUACION E,  int n){
    E -> A = n;
}

void asignaB(ECUACION E,  int b){
    E -> B = b;
}

void asignaC(ECUACION E,  int m){
    E -> C = m;
}

int obtenA(ECUACION E){
       return ( E -> A);
}

int obtenB(ECUACION E){
       return ( E -> B);
}

int obtenC(ECUACION E){
       return ( E -> C);
}

int raizReal(ECUACION E1){
    double r = (obtenB(E1)*obtenB(E1))-(4*(obtenA(E1)*obtenC(E1)));

    return r;
}

int raizcompleja(ECUACION E1){
    double r = (obtenB(E1)*obtenB(E1))-(4*(obtenA(E1)*obtenC(E1)));
    
    if(r >= 0){
        double x1 = (-obtenB(E1)+sqrt(r))/(2*obtenA(E1));
        double x2 = (-obtenB(E1)-sqrt(r))/(2*obtenA(E1));
        printf("Las raices complejas son: x1 = %lf y x2 = %lf\n", x1, x2);
    } else{
        double realPart = -obtenB(E1)/(obtenA(E1)*2);
        double imagPart = sqrt(-r)/(obtenA(E1)*2);
        printf("Las raices complejas son: X1 = %lf + %lfi y x2=%lf - %lfi\n",realPart, imagPart, realPart,imagPart);
    }
}
