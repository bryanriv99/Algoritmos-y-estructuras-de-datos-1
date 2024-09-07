#include <stdio.h>
#include <stdlib.h>

void darDim(int *, int *);
int **crearMatriz(int, int);
void darDatosMtz(int **, int, int);
void mostrarMtz(int **, int, int);
void liberarMtz(int **, int);
void Mensajes(int);
void vectorFilas(int **,int, int);
void determinante(int **);

void main() {
    int **mtz;
    mtz = crearMatriz(2, 2);
    printf("\n");
    darDatosMtz(mtz, 2, 2);
    printf("\n");
    determinante(mtz);
    liberarMtz(mtz, 2);
}

void determinante(int **mtz){
    int a,b,c,d,z;
    a = mtz[0][0];
    b = mtz[0][1];
    c = mtz[1][0];
    d = mtz[1][1];
    z = (a*d)-(b*c);
    printf("\nEl determinante de la matriz es: %d\n", z);

}

void vectorFilas(int ** mtz,int fil, int col){
    int i, j;
    printf("\nMatriz original:\n");
    mostrarMtz(mtz,fil,col);
    printf("\n");
    for(i=0; i<fil; i++){
        int sumfil = 0;
        for(j=0; j<col; j++){
            sumfil += mtz[i][j];
        }
        printf("\nLa suma de la de la fila %d es: %d\n", i+1, sumfil);
    }

    for(j=0; j<col; j++){
        int sumcol=0;
        for(i=0; i<fil; i++){
            sumcol += mtz[i][j];
        }
        printf("\nLa suma de la columna %d es: %d\n",j+1,sumcol);
    }
}

void darDim(int *fil, int *col) {
    printf("Indique el numero de filas\n");
    scanf("%d", fil);
    printf("Indique el numero de columnas\n");
    scanf("%d", col);
}

int **crearMatriz(int fil, int col) {
    int **mtz;
    int i;
    mtz=(int **)malloc(fil* sizeof(int *));

    if (mtz==NULL) {
        Mensajes(0);
        exit(0);
    }
    for (i=0; i<fil; i++)
        mtz[i]=(int *)malloc(sizeof(int)*col);

    return mtz;
}

void darDatosMtz(int **mtz, int fil, int col) {
    int i, j;

    printf("Ingrese los datos de la Matriz\n");
    for (i=0; i<fil; i++) {
        for (j=0; j<col; j++) {
            printf("Dato[%d][%d]=", i + 1, j + 1);
            scanf("%d", &mtz[i][j]);
        }
    }
}

void mostrarMtz(int **mtz, int fil, int col) {
    int i, j;
    printf("Los datos de la Matriz son: \n");
    for (i=0; i<fil; i++) {
        for (j=0; j<col; j++) {
            printf("\t%d", mtz[i][j]);
        }
        printf("\n");
    }
}

void liberarMtz(int **mtz, int fil) {
    int i;
    for (i=0; i<fil; i++)
        free(mtz[i]);//libera columnas
    free(mtz);//libera columnas
    Mensajes(1);
}

void Mensajes(int msg) {
    char *mensaje[]={"No hay memoria disponible... \n",
                       "Memoria liberada...\n"};
    printf("%s", mensaje[msg]);
}
