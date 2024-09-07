#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void llenar(LISTA*);
void liberarLista(LISTA L);
void manejaMsg(int n);
TNodoPaciente * listaPacDiag(TNodoMedico *, char *, char *);

void main(){
    LISTA L = crearLista();
    llenar(&L);

    
}

TNodoPaciente * listaPacDiag(TNodoMedico *clinica, char *diagnostico, char *codColegiado){
    LISTA temp = crearLista();
    Nodo_Lista aux;
    while(clinica != NULL){
        if(codColegiado == clinica->infoMedico.codColegiado && diagnostico == clinica->listaPaci->infoPaci.diagnostico){
            insertar(temp,*clinica);
        }
    }
    printf("Los datos del pasiente con eso sintomas son:\n");
    visualizaLista(temp);
}

void llenar(LISTA *AP){
    int op = 1;
    TNodoMedico m;
    while(op==1){
        printf("Digite el colegiado del medico: ");
        scanf("%s",m.infoMedico.codColegiado);
        printf("Digite el nombre del medico: ");
        scanf("%s",m.infoMedico.nombre);
        printf("Digite el nombre del pasiente: ");
        scanf("%s",m.listaPaci->infoPaci.nombre);
        printf("Digite el numero del historial del pasiente: ");
        scanf("%s",m.listaPaci->infoPaci.NumHistoria);
        printf("Digite el diagnostico del pasiente ");
        scanf("%s",m.listaPaci->infoPaci.diagnostico);
        *AP=insertar(*AP,m);
        printf("Desea agregar otro medico y pasiente?: (1.-SI 0.-NO): ");
        scanf("%d",&op);
    }
    printf("\n");
}


void liberarLista(LISTA L){
    free(L);
    manejaMsg(2);
}

void manejaMsg(int n){
    char * errores[]={"No hay memoria disponible\n","La lista esta vacia\n","Memoria liberada\n"};
    printf("%s", errores[n]);
}
