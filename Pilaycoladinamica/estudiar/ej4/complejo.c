#include "complejo.h"
#include <stdio.h>

COMPLEJO crearComplejo(){
    COMPLEJO C;
    C = (COMPLEJO)malloc(sizeof(Complejo));
    if(C == NULL){
        exit(0);
    }
}

void asignaReal(COMPLEJO C, int r){
    C->real = r;
}

void asignaImaginario(COMPLEJO C, int i){
    C->imaginario = i;
}

int obtenImaginario(COMPLEJO C){
    return C->imaginario;
}

int obtenReal(COMPLEJO C){
    return C->real;
}

