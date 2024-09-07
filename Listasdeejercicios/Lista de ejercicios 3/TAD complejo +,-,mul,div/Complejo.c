#include<stdlib.h>
#include "complejo.h"

void manejaMsg(int);

COMPLEJO crearComplejo(void){
   COMPLEJO C;
   C = (COMPLEJO)malloc(sizeof(Complejo));
   if( C == NULL){
        manejaMsg(0);
        exit(0);
   }
}
void asignaReal(COMPLEJO C,  float r){
    C -> real = r;
}
void asignaImaginario(COMPLEJO C, float i){
      C -> imaginario = i;
}

float obtenReal(COMPLEJO C){
       return ( C -> real);
}

float obtenImaginario(COMPLEJO C){
      return ( C -> imaginario);
}

COMPLEJO suma(COMPLEJO C1, COMPLEJO C2){
      COMPLEJO C3 =  crearComplejo();
      asignaReal( C3, obtenReal(C1) + obtenReal(C2) );
      asignaImaginario( C3, obtenImaginario(C1) + obtenImaginario(C2) );
       return C3;
}

COMPLEJO resta(COMPLEJO C1, COMPLEJO C2){
      COMPLEJO C4 =  crearComplejo();
      asignaReal( C4, obtenReal(C1) - obtenReal(C2) );
      asignaImaginario( C4, obtenImaginario(C1) - obtenImaginario(C2) );
       return C4;
}

COMPLEJO producto(COMPLEJO C1, COMPLEJO C2){
      COMPLEJO C5 = crearComplejo();
      asignaReal(C5, obtenReal(C1) * obtenReal(C2));
      asignaImaginario(C5, obtenImaginario(C1)*obtenImaginario(C2));
      return C5;
}

COMPLEJO division(COMPLEJO C1, COMPLEJO C2){
      COMPLEJO C6 = crearComplejo();
      asignaReal(C6,obtenReal(C1)/obtenReal(C2));
      asignaImaginario(C6, obtenImaginario(C1)/obtenImaginario(C2));
      return C6;
}