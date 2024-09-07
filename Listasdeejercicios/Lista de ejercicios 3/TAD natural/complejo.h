#include<stdio.h>
#ifndef  _complejo_
#define  _complejo_

typedef struct{
   int nat;
}Natural;

typedef Natural * NATURAL;

// operaciones
COMPLEJO crearComplejo(void);
void asignaReal(COMPLEJO C,  float r);
void asignaImaginario(COMPLEJO, float);
float obtenReal(COMPLEJO);
float obtenImaginario(COMPLEJO);
COMPLEJO suma(COMPLEJO, COMPLEJO);

#endif
