/*
En estadistica, la moda de una serie de numerosd es aquel número que aparece con mas frecuencia. Por ejemplo, dada la lista
Entrada: A[1,12,12,3,6,44,7,5,44,6,9,44]
Salida: La moda es 44
La moda es 44, ya que aparece tres veces.Haz un programa que calcule la moda. Si todos los números sonn diferentes entonces no hay moda, con lo cual debe indicar que hubo un error. Haga un programa que debera tener una funcion que lea N serie de numeros, otra funcion que lea N serie de numeros, otra funcion que reciba como parametro la serie de numeros y arroje la moda, la funcion principal que mande a llamar a las funciones anteriiores( en caso de haber dos iguales o más mencione el primero.
*/
#include <stdio.h>
#include <stdlib.h>

void darDim(int *elem);
int *crearArregloUni(int);
void darDatos(int *, int);
void liberar(int *);
void Mensajes(int);
int Moda(int *, int);

int main() {
    int *A, elem;

    darDim(&elem);
    A=crearArregloUni(elem);
    darDatos(A, elem);

    int moda=Moda(A, elem);
    if (moda!=-1) {
        printf("La moda es: %d\n", moda);
    } else{
        printf("No hay moda, todos los numeros son diferentes.\n");
    }

    liberar(A);
    return 0;
}

void darDim(int *elem){
    printf("Dar la dimension del arreglo: ");
    scanf("%d", elem);
}

int *crearArregloUni(int elem){
    int *A;
    A=(int *)malloc(elem * sizeof(int));
    if (A==NULL) {
        Mensajes(0);
        exit(0);
    }
    return A;
}

void darDatos(int *A, int elem){
    int i;
    printf("Ingrese los datos del arreglo:\n");
    for (i=0; i<elem; i++) {
        printf("A[%d] = ", i+1);
        scanf("%d", &A[i]);
    }
}

void liberar(int *A){
    free(A);
    Mensajes(1);
}

void Mensajes(int msg){
    char *mensaje[]={"No hay memoria disponible...\n",
                      "Memoria liberada...\n"};
    printf("%s", mensaje[msg]);
}

int Moda(int *A, int elem){
    int moda=-1;
    int a=0;
    int i;

    for(i=0; i<elem; i++){
        int b=0;
        int j;

        for(j=0; j<elem; j++){
            if(A[i]==A[j]){
                b++;
            }
        }

        if(b>a){
            a=b;
            moda=A[i];
        }
    }

    if(a>1){
        return moda;
    } else{
        return -1;
    }
}
