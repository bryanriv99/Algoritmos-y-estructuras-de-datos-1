#include<stdlib.h>
#include "complejo.h"
#include<math.h>

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
      COMPLEJO C3 =  crearComplejo();
      asignaReal( C3, obtenReal(C1) - obtenReal(C2) );
      asignaImaginario( C3, obtenImaginario(C1) - obtenImaginario(C2) );
       return C3;
}

float producto(COMPLEJO C1,float escalar){
	float m;
	m=escalar*(obtenReal(C1)+obtenImaginario(C1));
	return m;
}

float modulo(COMPLEJO C1){
	float m;
	m=sqrt((obtenReal(C1)*obtenReal(C1))+(obtenImaginario(C1)*obtenImaginario(C1)));
	return m;
}

COMPLEJO conjugado(COMPLEJO C1){
	COMPLEJO C2=crearComplejo();
	asignaReal(C2,obtenReal(C1));
	asignaImaginario(C2,obtenImaginario(C1)*-1);
	return C2;
}
