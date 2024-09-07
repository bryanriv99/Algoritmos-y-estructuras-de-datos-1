#include<stdio.h>
#include<stdlib.h>

void darDim(int *,int *);
int **crearMatriz(int,int);
void darDatosMtz(int **,int,int);
void liberarMtz(int **,int);

void main(){
    int fil,col,**mtz;

    darDimMtz(&fil,&col);
    mtz=crearMatriz(fil,&col);
    darDatosMtz(mtz,fil,col);
    mostrlarMtz(mtz,fil,col);
    liberarMtz(mtz);
}
void darDim(int *fil,int *col){
    printf("Indique el numero de filas\n");
    scanf("%d",fil);
    printf("Indique el numero de columnas\n");
    scanf("%d",col);
}
int **crearMatriz(int fil,int col){
    int **mtz, i;
    mtz=(int**)malloc(fil*sizeof(int*));

    if(mtz==NULL){
        Mensajes(0);
        exit(0);
    }
    for(i=0;i<fil;i++)
        mtz[i]=(int*)malloc(sizeof(int)*col);

    return mtz;
}
void darDatosMtz(int **mtz,int fil,int col){
    int i,j;

    printf("Los datos de la matriz son:\n");
    for(i=0;i<fil;i++){
        for(j=0;j<col;j++)
            printf("\t%d",mtz[i][j]);
        printf("\n");
    }
}
void liberarMtz(int **mtz,int fil){
    int i;

    for(i=0;i<fil;i++)
        free(mtz[i]);// libera columnas
    free(mtz); // Libera filas

    Mensajes(1);
}
