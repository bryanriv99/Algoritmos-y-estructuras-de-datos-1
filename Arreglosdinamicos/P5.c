#include <stdio.h>
#include <stdlib.h>

void darDim(int *, int *);
int **crearMatriz(int, int);
void darDatosMtz(int **, int, int);
void mostrarMtz(int **, int, int);
void liberarMtz(int **, int);
void Mensajes(int);
void vectorFilas(int **,int, int);
void traspuesta(int **, int, int);

void main() {
    int fil, col, **mtz;
    darDim(&fil, &col);
    mtz = crearMatriz(fil, col);
    printf("\n");
    darDatosMtz(mtz, fil, col);
    printf("\n");
    traspuesta(mtz,fil,col);
    liberarMtz(mtz, fil);
}

void traspuesta(int** mtz, int fil, int col){
    int **maux, i,j,k,l,a;
    maux = crearMatriz(col,fil);
    for(i=0; i<fil; i++){
        for(j=0; j<col; j++){
            a = mtz[i][j];
            for(l=0; l<fil; l++){
                for(k=0; k<col; k++){
                    maux[k][l] = a;
                }
            }
        }
    }
    printf("\n\nMatriz original:\n\n");
    mostrarMtz(mtz,fil,col);
    printf("\n\nLa matriz traspuesta de la original es:\n\n");
    mostrarMtz(maux,col,fil);
    liberarMtz(maux,col);
}

void vectorFilas(int ** mtz,int fil, int col){
    int *vecfil, *veccol;
    vecfil = (int *)malloc(fil * sizeof(int));
    veccol = (int *)malloc(col * sizeof(int));
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
