#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#ifndef  _ecuacion_
#define  _ecuacion_

typedef struct{
   double A;
   double B;
   double C;
}Ecuacion;

typedef Ecuacion * ECUACION;

// operaciones
ECUACION crearEcuacion(void);
void asignaA(ECUACION E,  int n);
void asignaB(ECUACION E,  int b);
void asignaC(ECUACION E,  int m);
int obtenA(ECUACION E);
int obtenB(ECUACION E);
int obtenC(ECUACION E);
int raizReal(ECUACION E1);
int raizcompleja(ECUACION E1);

#endif