#ifndef _listaSimple_
#define _listaSimple_

#define TRUE 1
#define FALSE 0

typedef struct {
    char NumHistoria[10];
    char nombre[50];
    char diagnostico[100];
} TPaciente;

typedef struct nodoPaciente {
    TPaciente infoPaci;
    struct nodoPaciente *sigPaciente;
} TNodoPaciente;

typedef struct {
    char codColegiado[10];
    char nombre[50];
} TMedico;

typedef struct nodoMedico {
    TMedico infoMedico;
    TNodoPaciente *listaPaci;
    struct nodoMedico *sigMedico;
} TNodoMedico;

typedef struct Nodo_Lista {
    TNodoMedico dato;
    struct Nodo_Lista *siguiente;
} Nodo_Lista;

typedef Nodo_Lista *LISTA;

LISTA crearLista();
int es_vaciaLista(LISTA L);
Nodo_Lista *crearNodoLista();
LISTA insertar(LISTA L, TNodoMedico e);
void visualizaLista(LISTA L);
void buscarElem(LISTA L, TNodoMedico elem);
LISTA borrar(LISTA L, TNodoMedico elem);
void mostrar(TNodoMedico e, int msg, int p);


#endif
