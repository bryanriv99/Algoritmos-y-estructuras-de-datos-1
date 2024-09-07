/*El programa debe solicitar la dimension de la matriz(leerDim), llenar con los datos proporcionados por el usuario llenarMatriz, obtener la transpuesta de A * la transpuesta de B  mediante la funcion calculaProdTans dejando el resultado en una matriz C resultante y la funcion mostrar resultado en una matriz C resultante  y la funcion mostrarResultado que desplegara el contenido de las matrices A,B y C. Las funciones que interactuan con el usuario pertenencientes al mainMatriz  se implementaran utilizando las operaciones definidas en el TAD. En caso de que no se pueda efectuar la multiplicacion debe enviar un mensaje al usuario
*/
#include<stdio.h>
#include<stdlib.h>
#include"matriz.h"

void manejaMsg(int);
void llenarMatriz(MATRIZ );
void mostrarResultado(MATRIZ);
MATRIZ calculaProdTrans(MATRIZ , MATRIZ);
int leerDimfila(int);
int leerDimcol(int);

void main(){
int filas, columnas;
    printf("Ingrese el número de filas de las matrices: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas de las matrices: ");
    scanf("%d", &columnas);

    MATRIZ m1, m2;
    m1 = crearMatriz(filas, columnas);
    m2 = crearMatriz(filas, columnas);

    llenarMatriz(m1);
    llenarMatriz(m2);

    mostrarResultado(m1);
    asignaValor(m1,0,0,3);
    mostrarResultado(m1);


    printf("\nResultado de la multiplicacion entre m1 y m2");
    mostrarResultado(multiplicaMatriz(m1,m2));
    
    printf("\nResultado del producto de A^t * B^t");
    mostrarResultado(transpuesta(m1));

}

void mostrarResultado(MATRIZ m){
    printf("\n");
    for (int i = 0; i < m->filas; i++){
        printf("\n|");
        for (int j = 0; j < m->columas; j++){
            printf("  %d ",m->mtz[i][j]);
        }
        printf("|");

    }
}

void llenarMatriz(MATRIZ m){
    printf("\n--LLENAR MATRIZ--\nIngrese los elementos de la matriz. \n");
    for (int i = 0; i < m->filas; i++){
        for (int j = 0; j < m->columas; j++){
            printf("[%d][%d]: ",i+1,j+1);
            scanf("%d",&m->mtz[i][j]);
        }
    }
    
}

MATRIZ calculaProdTrans(MATRIZ m1, MATRIZ m2){
	MATRIZ mresultante;
	mresultante=multiplicaMatriz(transpuesta(m1),transpuesta(m2));
	
	return mresultante;
}

int leeDimfila(int n){

    printf("Ingrese el número de filas de las matrices: ");
    scanf("%d", &n);
    return n;
}
int leerDimcol(int n){
    printf("Ingrese el número de columnas de las matrices: ");
    scanf("%d", &n);
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  "};
     printf("%s", mensajes[msg] );
}
