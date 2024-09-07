#include <stdio.h>
#include <stdlib.h>

void darDim(int *);
int *crearArregloUni(int);
void darDatos(int *, int);
void mostrar(int *, int);
void liberar(int *);
void Mensajes(int);
void producto(int *, int *, int *);

void main(){
    int *A, *B, *C;
    
    A = crearArregloUni(3);
    B = crearArregloUni(3);
    C = crearArregloUni(3);
    printf("Arreglo 1:\n");
    darDatos(A,3);
    printf("\n");
    printf("Arreglo 2:\n");
    darDatos(B,3);
    printf("\n");
    printf("Arreglo 3:\n");
    darDatos(C,3);
    printf("\n");
    producto(A,B,C);
    liberar(A);
    liberar(B);
    liberar(C);
}

void producto(int *A, int *B, int *C){
    int *n, *m;
    n = crearArregloUni(3);
    n[0] = A[0] * B[0];
    n[1] = A[1] * B[1];
    n[2] = A[2] * B[2];

    m = crearArregloUni(3);
    m[0] = n[0] * C[0];
    m[1] = n[1] * C[1];
    m[2] = n[2] * C[2];

    printf("\nLos vectores originales son: A=<%d,%d,%d>  B=<%d,%d,%d>  C=<%d,%d,%d>\n\n", A[0],A[1],A[2],B[0],B[1],B[2],C[0],C[1],C[2]);
    printf("El producto mixto de A, B y C es: <%d,%d,%d>\n",m[0], m[1], m[2]);
}

void darDim(int *elem){
    printf("Dar la dimension del arreglo\n");
    scanf("%d",elem);
}

int *crearArregloUni(int elem){
    int * A;
    A = (int*) malloc (elem*sizeof(int));
    if(A == NULL){
        Mensajes(0);
        exit(0); 
    }
    return A;
}

void darDatos(int *A, int elem){
    int i;
    printf("ingrese los datos del arreglo\n");
    for(i=0 ; i<elem; i++){
        printf("\nA[%d]=",i+1);
        scanf("%d",&A[i]);
    }
}

void mostrar(int *A, int elem){
    int i;

    printf("Los datos del arreglo son:\n");
    for(i=0; i<elem; i++){
        printf("A[%d]=%d\n", i+1,A[i]);
    }
}

void liberar(int *A){
    free(A);
    Mensajes(1);
}

void Mensajes(int msg){
    char * mensaje[]={"No hay memoria disponnible ...\n","Memoria liberada ...\n"};
    printf("%s",mensaje[msg]);
}