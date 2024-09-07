#include <stdio.h>
#include <stdlib.h>

void darDim(int *, int *);
float **crearMatriz(int , int);
void darDatosMtz(int **, int, int);
void mostrarMtz(int **, int, int);
void liberarMtz(int **,int);
void Mensajes(int);
void volumen(int **, int, int);

int main() {
    return 0;
}

void volumen(int ** mtz, int fil, int col){

}

void darDim(int *fil, int *col) {
    printf("Indique el numero de filas\n");
    scanf("%f", fil);
    printf("Indique el numero de columnas\n");
    scanf("%f", col);
}

float **crearMatriz(int fil, int col) {
    float **mtz;
    int i;
    mtz=(float **)malloc(fil* sizeof(float *));

    if (mtz==NULL) {
        Mensajes(0);
        exit(0);
    }
    for (i=0; i<fil; i++)
        mtz[i]=(float *)malloc(sizeof(float)*col);

    return mtz;
}

void darDatosMtz(int **mtz, int fil, int col) {
    int i, j;

    printf("Ingrese los datos de la Matriz\n");
    for (i=0; i<fil; i++) {
        for (j=0; j<col; j++) {
            printf("Dato[%d][%d]=", i + 1, j + 1);
            scanf("%f", &mtz[i][j]);
        }
    }
}



void mostrarMtz(int **mtz, int fil, int col) {
    int i, j;
    printf("Los datos de la Matriz son: \n");
    for (i=0; i<fil; i++) {
        for (j=0; j<col; j++) {
            printf("\t%f", mtz[i][j]);
        }
        printf("\n");
    }
}

void liberarMtz(int **mtz, int fil) {
    int i;
    for (i=0; i<fil; i++)
        free(mtz[i]);
    free(mtz);
    Mensajes(1);
}

void Mensajes(int msg) {
    char *mensaje[]={"No hay memoria disponible... \n",
                       "Memoria liberada...\n"};
    printf("%s", mensaje[msg]);
}