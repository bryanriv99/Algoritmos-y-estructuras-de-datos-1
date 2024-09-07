#ifndef  _listaSimple_
#define  _listaSimple_

#define TRUE    1
#define FALSE  0

typedef  struct Alumno{
    char nombre[30];
    int calif;
}Alumno;

typedef struct Nodo_Lista{
    Alumno dato;
    struct Nodo_Lista * siguiente;
}Nodo_Lista;

typedef Nodo_Lista * LISTA;

// CREACION DE UNA LISTA VACÍA
LISTA crearLista();

// VERIFICA SI ESTA VACÍA LA LISTA
int es_vaciaLista(LISTA L);

// CREA UN ELEMENTO DE LA LISTA
Nodo_Lista * crearNodoLista();

LISTA insertar(LISTA L, Alumno e);
       
// MOSTRAR LOS ELEMENTOS DE LA LISTA
void visualizaLista(LISTA L);

// BUSCAR UN ELEMENTO DE LA LISTA
void  buscarElem(LISTA L, Alumno elem);

// BORRAR UN ELEMENTO DE LA LISTA
LISTA borrar(LISTA L, Alumno elem);

void mostrar(Alumno e, int msg, int p);

#endif