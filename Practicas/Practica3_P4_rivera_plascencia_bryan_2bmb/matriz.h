#ifndef _matriz_
#define  _matriz_

typedef  struct{
    int **mtz;
    int filas;
    int columas;
}Matriz;

typedef Matriz* MATRIZ;

//operaciones
MATRIZ crearMatriz(int fila, int columna);
int obtenValor(MATRIZ m,int fila, int columna);
MATRIZ asignaValor(MATRIZ m, int fila, int columna, int valor);
int tamFilas(MATRIZ m);
int tamColum(MATRIZ m);
MATRIZ transpuesta(MATRIZ m1);
MATRIZ multiplicaMatriz(MATRIZ m1, MATRIZ m2);
#endif
