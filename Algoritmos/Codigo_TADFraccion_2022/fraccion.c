#include<stdlib.h>
#include "fraccion.h"
#include<math.h>

void manejaMsg(int);

FRACCION crearFraccion(void){
 FRACCION F;
   F = (FRACCION)malloc(sizeof(Fraccion));
   if( F == NULL){
         manejaMsg(0);
         exit(0);
    }
    return F;
}
void asignaNum(FRACCION F,  int n){
    F -> numerador = n;
}

void asignaDenom(FRACCION F, int d){
      F -> denominador = d;
}

int obtenNum(FRACCION F){
       return ( F -> numerador);
}

int obtenDenom(FRACCION F){
      return ( F -> denominador);
}

FRACCION producto(FRACCION F1, FRACCION F2){
      FRACCION F3 =  crearFraccion();
      asignaNum( F3, obtenNum(F1) * obtenNum(F2) );
      asignaDenom( F3, obtenDenom(F1) * obtenDenom(F2) );
      return F3;
}

int equivalentes(FRACCION F1, FRACCION F2){
	if((obtenNum(F1)*obtenDenom(F2))==(obtenDenom(F1)*obtenNum(F2))){
		return 1;
		}
	else
      
	return 0;
	
}

FRACCION amplificacion(FRACCION F1, int ampl){
	FRACCION F5 = crearFraccion();
	asignaNum(F5, obtenNum(F1)*ampl);
	asignaDenom(F5, obtenDenom(F1)*ampl);
	return F5;
}

FRACCION potencia(FRACCION F1, int potencia){
	FRACCION F6 = crearFraccion();
	asignaNum(F6, pow(obtenNum(F1),potencia));
	asignaDenom(F6, pow(obtenDenom(F1),potencia));
	return F6;
}
