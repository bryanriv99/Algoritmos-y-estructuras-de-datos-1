#include <stdio.h>
#include <stdlib.h>

void darDim(float *, float *);
float **crearMatriz(float , float);
void darDatosMtz(float **, float, float);
void mostrarMtz(float **, float, float);
void liberarMtz(float **, float);
void Mensajes(int);
void Promedios(float **, float, float, float *, float *);

int main() {
    float fil, col, **mtz;
    float *promfila, *promcolumna;

    darDim(&fil, &col);
    mtz = crearMatriz(fil, col);
    darDatosMtz(mtz, fil, col);
    mostrarMtz(mtz, fil, col);
    promfila = (float *)malloc(fil * sizeof(float));
    promcolumna = (float *)malloc(col * sizeof(float));
    Promedios(mtz, fil, col, promfila, promcolumna);

    printf("\nEl promedio de las filas son:\n");
    for (int i=0; i<fil; i++) {
        printf("%f ", promfila[i]);
    }
    printf("\nEl promedio de las columnas son:\n");
    for (int j=0; j<col; j++) {
        printf("%f ", promcolumna[j]);
    }

    liberarMtz(mtz, fil);

    return 0;
}

void darDim(float *fil, float *col) {
    printf("Indique el numero de filas\n");
    scanf("%f", fil);
    printf("Indique el numero de columnas\n");
    scanf("%f", col);
}

float **crearMatriz(float fil, float col) {
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

void darDatosMtz(float **mtz, float fil, float col) {
    int i, j;

    printf("Ingrese los datos de la Matriz\n");
    for (i=0; i<fil; i++) {
        for (j=0; j<col; j++) {
            printf("Dato[%d][%d]=", i + 1, j + 1);
            scanf("%f", &mtz[i][j]);
        }
    }
}

void Promedios(float **mtz, float fil, float col, float *promfilas, float *promcolumnas) {
    for (int i=0; i<fil; i++) {
        float fila=0;
        for (int j=0; j<col; j++) {
            fila+=mtz[i][j];
        }
        promfilas[i]=fila/col;
    }
    for (int j=0; j<col; j++) {
        float columna=0;
        for (int i=0; i<fil; i++) {
            columna+=mtz[i][j];
        }
        promcolumnas[j]=columna/fil;
    }
}

void mostrarMtz(float **mtz, float fil, float col) {
    int i, j;
    printf("Los datos de la Matriz son: \n");
    for (i=0; i<fil; i++) {
        for (j=0; j<col; j++) {
            printf("\t%f", mtz[i][j]);
        }
        printf("\n");
    }
}

void liberarMtz(float **mtz, float fil) {
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
