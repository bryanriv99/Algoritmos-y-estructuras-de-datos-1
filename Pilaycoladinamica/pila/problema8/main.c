#include "pila.h"
#include<stdio.h>
#include<stdlib.h>

void agregarExped(PILA);
Expediente leerExped();
void expedPorMes(PILA);
void imprimirExped(Expediente);
void expedPorFecha(PILA);
void manejaMsg(int);
void menu(PILA);

void main(){
    PILA P;
    P = crearPila();
    menu(P);
}

void menu(PILA S) {
    int respuesta; 

    while (respuesta != -1) {
        printf("\n\nMenu: \n1) Agregar expediente\n2) Expedientes por mes\n3)Expediente por fecha \n0) Salir\nIntroduzca una opcion: ");
        scanf("%d", &respuesta);
        switch (respuesta) {
            case 1:
                agregarExped(S);
                break;
            case 2:
                expedPorMes(S);
                break;
            case 3:
                expedPorFecha(S);
                break;
            
            case 0:
                respuesta = -1;
                break;
            default:
                printf("\nIntroduzca una opcion valida!: ");
                break;
        }
    }
}


void expedPorFecha(PILA P){
    Expediente exp;
    int d1,d2,m1,m2,a1,a2;
    printf("\nDelilita las fechas\n");
    printf("\nFecha inicial\n");
    printf("Ingrese el dia: ");
    scanf("%d",&d1);
    printf("\nIngrese el mes: ");
    scanf("%d",&m1);
    printf("\nIngrese el ano: ");
    scanf("%d",&a1);
    printf("\n\nIngrese fecha final\n");
    printf("Ingrese el dia: ");
    scanf("%d",&d2);
    printf("\nIngrese el mes: ");
    scanf("%d",&m2);
    printf("\nIngrese el ano: ");
    scanf("%d",&a2);

    printf("Expedientes del %d/%d/%d al %d/%d/%d\n",d1,m1,a1,d2,m2,a2);
    
    while(!es_vaciaPila(P)){
        exp = desapilar(P);
        if(exp.fecha.año >= a1 && exp.fecha.año <= a2){
            if(exp.fecha.mes >= m1 && exp.fecha.mes <= a2){
                if(exp.fecha.dia >= a1 && exp.fecha.dia <= a2){
                    imprimirExped(exp);
                }
            }
    }
}
}

void expedPorMes(PILA P){
    int mes;
    PILA aux = crearPila();
    Expediente exp;
    printf("\nIngrese el mes del expediente que desea buscar: ");
    scanf("%d", &mes);
    printf("\n");
    while(!es_vaciaPila(P)){
        exp=desapilar(P);
        apilar(aux,exp);
        if(mes==exp.fecha.mes){
            imprimirExped(exp);
        }
    }

}


Expediente leerExped(){
    
    Expediente exp;

        printf("Ingrese el numero de expediente: ");
        scanf("%d", &exp.numero);

        printf("Ingrese el titular del expediente: ");
        scanf("%s", exp.titular);

        printf("Ingrese el tramite del expediente: ");
        scanf("%s", exp.tramite);

        printf("Ingrese dia del expediente ");
        scanf("%d", &exp.fecha.dia);

        printf("Ingrese mes del expediente: ");
        scanf("%d", &exp.fecha.mes);

        printf("Ingrese año del expediente: ");
        scanf("%d", &exp.fecha.año);
return exp;
}

void agregarExped(PILA P){
	Expediente exp;
	int n;
	while(1){
		printf("Desea agregar un expediente a la pila? (1=Si 0=No)\n");
		scanf("%d",&n);
		if(n==0)
			break;
		exp = leerExped();
		apilar(P, exp);
	}
}



void imprimirExped(Expediente exp){
	printf("\nNumero: %d\n",exp.numero);
	printf("Titular: %s\n",exp.titular);
	printf("Tramite: %s\n",exp.tramite);
	printf("Dia: %d\n",exp.fecha.dia);
	printf("Mes: %d\n",exp.fecha.mes);
	printf("Año: %d\n",exp.fecha.año);
}

void manejaMsg(int msg) {
    char *mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .", "Pila vacia . . .", "Pila llena . . ."};
    printf("%s\n", mensajes[msg]);
}