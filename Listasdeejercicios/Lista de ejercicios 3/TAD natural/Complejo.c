#include<stdlib.h>
#include "complejo.h"

void manejaMsg(int);

NATURAL crearNatural(int N){
      N -> nat = r;
      return N;
   }

void asignaNatural(NATURAL N, int r){
    N -> nat = r;
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


