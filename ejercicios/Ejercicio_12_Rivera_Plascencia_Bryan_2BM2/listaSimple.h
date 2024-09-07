#ifndef  _listaSimple_
#define  _listaSimple_

#define TRUE    1
#define FALSE  0

typedef struct Mascota{
    int id;
    char raza[25];
    float peso;
}Mascota;

typedef struct Nodo_Lista{
    Mascota dato;
    struct Nodo_Lista * siguiente;
}Nodo_Lista;

typedef Nodo_Lista * LISTA;

LISTA crearLista();
int es_vaciaLista(LISTA L);
Nodo_Lista * crearNodoLista();
LISTA insertar(LISTA L, Mascota e);
void visualizaLista(LISTA L);
void buscarElem(LISTA L, Mascota elem);
LISTA borrar(LISTA L, Mascota elem);
void mostrar(Mascota e, int msg, int p);
void manejaMsg(int n);

#endif
