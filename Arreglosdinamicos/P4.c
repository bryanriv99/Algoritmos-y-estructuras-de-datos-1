#include <stdio.h>
#include <stdlib.h>

void darDim(int *, int *);
int **crearMatriz(int, int);
void darDatosMtz(int **, int, int);
void mostrarMtz(int **, int, int);
void liberarMtz(int **, int);
void Mensajes(int);
void vectorFilas(int **,int, int);
void menu(int **mtz1, int **mtz2, int fil1, int col1, int fil2, int col2, int mult1, int mult2);
void suma(int **,int **, int, int, int, int, int, int);
void resta(int **,int **, int, int, int, int, int, int);
void multi(int **,int **, int, int, int, int, int, int);

void main() {
    int fil, col, **mtz, **mtz1, fil2, col2,n,m;
    printf("matriz 1:\n");
    darDim(&fil, &col);
    printf("matriz 2:\n");
    darDim(&fil2, &col2);
    mtz = crearMatriz(fil, col);
    mtz1 = crearMatriz(fil2, col2);
    printf("matriz 1:\n");
    darDatosMtz(mtz, fil, col);
    printf("matriz 2:\n");
    darDatosMtz(mtz1, fil2, col2);
    printf("ingresa el numero por el cual quieres multiplicar la matriz 1: ");
    scanf("%d",&n);
    printf("\n");
    printf("ingresa el numero por el cual quieres multiplicar la matriz 2: ");
    scanf("%d",&m);
    printf("\n");
    menu(mtz,mtz1,fil,col,fil2,col2,n,m);
    liberarMtz(mtz, fil);
}

void multi(int **mtz1, int **mtz2, int fil1, int col1, int fil2, int col2, int mult1, int mult2){
    if(fil1 != fil2 || col1 != col2){
        printf("\nNo se puede hacer la suma porquue las dimensiones de las matrices son diferentes\n");
    }else{
        int **aux;
        aux = crearMatriz(fil1,col1);
        int i,j,k,l,a,b,c,x,y,o,u,m1,m2,m,n;

        for(o=0; o<fil1; o++){
            for(u=0; u<col1; u++){
                m1 = mtz1[o][u] * mult1;
            }
        }

        for(m=0; m<fil1; m++){
            for(n=0; n<col1; n++){
                m2 = mtz2[m][n] * mult2;
            }
        }

        for(i=0; i<fil1; i++){
            for(j=0; j<col1; j++){
                a = mtz1[i][j];
                for(k=0; k<fil2; k++){
                    for(l=0; l<col2; l++){
                        b = mtz2[k][l];
                        c = a * b;
                        for (x=0; x<fil1; x++) {
                            for (y=0; y<col1; y++) {
                                 aux[x][y] = c;
                            }
                        }
                    }
                }

            }
        }
        printf("\nEl resultado de la suma es:\n");
        mostrarMtz(aux,fil1,col1);
    }
}

void resta(int **mtz1, int **mtz2, int fil1, int col1, int fil2, int col2, int mult1, int mult2){
    if(fil1 != fil2 || col1 != col2){
        printf("\nNo se puede hacer la suma porquue las dimensiones de las matrices son diferentes\n");
    }else{
        int **aux;
        aux = crearMatriz(fil1,col1);
        int i,j,k,l,a,b,c,x,y,o,u,m1,m2,m,n;

        for(o=0; o<fil1; o++){
            for(u=0; u<col1; u++){
                m1 = mtz1[o][u] * mult1;
            }
        }

        for(m=0; m<fil1; m++){
            for(n=0; n<col1; n++){
                m2 = mtz2[m][n] * mult2;
            }
        }

        for(i=0; i<fil1; i++){
            for(j=0; j<col1; j++){
                a = mtz1[i][j];
                for(k=0; k<fil2; k++){
                    for(l=0; l<col2; l++){
                        b = mtz2[k][l];
                        c = a - b;
                        for (x=0; x<fil1; x++) {
                            for (y=0; y<col1; y++) {
                                 aux[x][y] = c;
                            }
                        }
                    }
                }

            }
        }
        printf("\nEl resultado de la suma es:\n");
        mostrarMtz(aux,fil1,col1);
    }
}

void suma(int **mtz1, int **mtz2, int fil1, int col1, int fil2, int col2, int mult1, int mult2){
    if(fil1 != fil2 || col1 != col2){
        printf("\nNo se puede hacer la suma porquue las dimensiones de las matrices son diferentes\n");
    }else{
        int **aux;
        aux = crearMatriz(fil1,col1);
        int i,j,k,l,a,b,c,x,y,o,u,m1,m2,m,n;

        for(o=0; o<fil1; o++){
            for(u=0; u<col1; u++){
                m1 = mtz1[o][u] * mult1;
            }
        }

        for(m=0; m<fil1; m++){
            for(n=0; n<col1; n++){
                m2 = mtz2[m][n] * mult2;
            }
        }

        for(i=0; i<fil1; i++){
            for(j=0; j<col1; j++){
                a = mtz1[i][j];
                for(k=0; k<fil2; k++){
                    for(l=0; l<col2; l++){
                        b = mtz2[k][l];
                        c = a + b;
                        for (x=0; x<fil1; x++) {
                            for (y=0; y<col1; y++) {
                                 aux[x][y] = c;
                            }
                        }
                    }
                }

            }
        }
        printf("\nEl resultado de la suma es:\n");
        mostrarMtz(aux,fil1,col1);
    }
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

void menu(int **mtz1, int **mtz2, int fil1, int col1, int fil2, int col2, int mult1, int mult2) {
    int respuesta; 

    while (respuesta != -1) {
        printf("\n\nMenu: \n1) sumar matriz \n2) restar matriz \n3) multiplicar matriz \n0) Salir\nIntroduzca una opcion: ");
        scanf("%d", &respuesta);
        switch (respuesta) {
            case 1:
                suma(mtz1,mtz2,fil1,col1,fil2,col2,mult1,mult2);
                break;
            case 2:
                resta(mtz1,mtz2,fil1,col1,fil2,col2,mult1,mult2);
                break;
            case 3:
                multi(mtz1,mtz2,fil1,col1,fil2,col2,mult1,mult2);
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