#include<stdio.h>
#include "pila.h"
#include<stdlib.h>



void manejaMsg(int);
int numElem(PILA);
int numElemi(PIL);
Datos registrarAlumno();
PILA invertird(PILA);
PIL invertiri(PIL);
void ingresarDAtos(PILA);
void visualizaLotes(PILA, PIL);
void mostrarPila(PILA);
void liberarMem(PILA);
void LiberarMem(PIL);
void datosEntrada(PIL);

void main(){
	PILA A=crearPila();
	PIL P=CrearPila();
	datosEntrada(P);
	ingresarDAtos(A);
	visualizaLotes(A,P);
	liberarMem(A);
	LiberarMem(P);
}
void ingresarDAtos(PILA A){
    int opcion;
    do
    {
        printf("\n");
        apilar(A,registrarAlumno());
        printf("Seguir registrando alumnos? (SI = 1 | N0 = 0):");
        scanf("%d",&opcion);
        getc(stdin);
    } while (opcion != 0);
    
}
void datosEntrada(PIL S){
    int op, num;
    do
    {
        printf ("Ingresa un dato\n");
        scanf("%d",&num);
        Apilar
		(S,num);
        printf("--0) Dejar de insertar datos--\n--1) Insertar otro dato--\n");
        scanf("%d",&op);
    } while (op!=0);
    
}

Datos registrarAlumno(){
	Datos a;
	printf("Ingrese los datos del alumno\n");
	printf("Nombre: ");
	scanf(" %[^\n]",a.nombre);
	getchar();
	printf("Edad: ");
	scanf("%d",&a.edad);
	getchar();
	printf("Sexo: ");
	scanf(" %[^\n]",a.sexo);
	getchar();
	printf("Calificaciones: ");
	scanf("%lf",&a.calif);
	getchar();
	return a;
}

PILA invertird(PILA S){
    PILA P = crearPila();
	Datos a;
	while(!es_vaciaPila(S)){
		a=desapilar(S);
		apilar(P,a);
	}
    return P;
}
PIL invertiri(PIL S){
	PIL P = CrearPila();
	int a;
	while (!es_vaciaPil(S)){
		a=Desapilar(S);
		Apilar(P,a);
	}
	return P;
}

 int numElem(PILA S){
	int count=0;
	while(!es_vaciaPila(S)){
		desapilar(S);
		count++;
	}
	return count;
}
 int numElemi(PIL S){
	int count=0;
	while(!es_vaciaPil(S)){
		Desapilar(S);
		count++;
	}
	return count;
}

void visualizaLotes(PILA A,PIL P){
	PILA k;
	PIL j;

	PIL auxii=CrearPila();
	int count=0;
	Datos a;
	PILA aux=crearPila();
	PILA auxid=crearPila();
	k = invertird(A);
	j = invertiri(P);
	if(numElem(A)>=numElemi(P)){
	while(!es_vaciaPila(k)&&!es_vaciaPil(j)){
		int n=Desapilar(j);
		a=desapilar(k);
		count++;
		if(n == count){
			apilar(aux, a);
		}

	} 
	mostrarPila(aux);
}else{manejaMsg(4);}
}

void mostrarPila(PILA p){
    PILA tmp = crearPila();
    Datos aux;



    while( !(es_vaciaPila(p)) ){
        apilar(tmp,desapilar(p));
    }

    while(!es_vaciaPila(tmp)){
        aux = desapilar(tmp);
        printf("\n");
        printf("\tNombre: %s.\n", aux.nombre);
        printf("\tEdad: %d.\n", aux.edad);
        printf("\tSexo: %s.\n", aux.sexo);
        printf("\tCalificaciones: %.2f.\n", aux.calif);

    }
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ","La Pila esta llena . . .","La Pila esta vacia . . .","NO es posible visualizar el alumno . . ."};
	printf("%s", mensajes[msg] );
}

void liberarMem(PILA P){
	free(P);
	manejaMsg(1);
}

void LiberarMem(PIL P){
	free(P);
	manejaMsg(1);
}