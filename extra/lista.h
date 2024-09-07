#ifndef  _listaSimple_
#define  _listaSimple_

#define TRUE    1
#define FALSE  0


//datos paciente
typedef struct{
    char NumHistoria[10];
    char nombre[50];
    char diagnostico[200];
}TPaciente;

typedef struct nodoPaciente{
    TPaciente infoPaci;
    struct nodoPaciente * sigPaciente;
}TNodoPaciente;

//datos medico
typedef struct{
    char codColegiado[10];
    char nombre[50];
}TMedico;

typedef struct nodoMedico{
    TMedico infoMedico;
    TNodoPaciente *listaPaci;
    struct nodoMedico *sigMedico;
}TNodoMedico;

typedef struct Nodo_Lista{
    TNodoMedico dato;
    struct Nodo_Lista * siguiente;
}Nodo_Lista;

typedef Nodo_Lista * LISTA;

// CREACION DE UNA LISTA VACÍA
LISTA crearLista();

// VERIFICA SI ESTA VACÍA LA LISTA
int es_vaciaLista(LISTA L);

// CREA UN ELEMENTO DE LA LISTA
Nodo_Lista * crearNodoLista();

LISTA insertar(LISTA L, TNodoMedico e);
       
// MOSTRAR LOS ELEMENTOS DE LA LISTA
void visualizaLista(LISTA L);

// BUSCAR UN ELEMENTO DE LA LISTA
void  buscarElem(LISTA L, TNodoMedico elem);




void mostrar(TNodoMedico e, int msg, int p);

#endif