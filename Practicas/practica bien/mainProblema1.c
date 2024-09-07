#include "Pilas.h"

TRABAJO crearTrabajo();
void liberarTrabajo(TRABAJO);
void ingresarTrabajos(PILA);
TRABAJO registrarTrabajo();

PILA buscarAlumno(PILA);
void mostrarPila(PILA,char);
void liberarPilaMsg(PILA);

int main(int argc, char const *argv[])
{
    PILA A,B;
    A = crearPila();

    ingresarTrabajos(A);
    B = buscarAlumno(A);
    mostrarPila(A,'A');
    mostrarPila(B,'B');

    liberarPilaMsg(A);
    liberarPilaMsg(B);
    return 0;
}

TRABAJO crearTrabajo(){
    TRABAJO ap = (TRABAJO)malloc(sizeof(trabajo));
    if(ap == NULL){
        manejaError(5);
        exit(-1);
    }
    return ap;
}

void liberarTrabajo(TRABAJO ap){
    free(ap);
}

void ingresarTrabajos(PILA A){
    int opcion;
    do
    {
        printf("\n");
        apilar(A,registrarTrabajo());
        printf("Seguir ingresando trabajos? (SI = 1 | N0 = 0):");
        scanf("%d",&opcion);
        getc(stdin);
    } while (opcion != 0);
    
}

TRABAJO registrarTrabajo(){
    TRABAJO tr = crearTrabajo();
    char c; int aux = 0;

    printf("\tIngresa nombre alumno: ");         //NOMBRE
    scanf("%[^\n]",tr->nombre);
    getchar();

    printf("\tIngresa materia: ");             //MATERIA
    scanf("%[^\n]",tr->materia);
    getchar();

    printf("\tIngresa tema: ");               //TEMA
    scanf("%[^\n]",tr->tema);
    getchar();

    //reciclamos la variable
    aux = 0;

    printf("\tIngresa cantidad de hojas: "); //HOJAS
    scanf("%d",&aux);
    tr->hojas=aux;
    
    printf("\tIngresa el estado (0 = sin terminar | 1 = terminado): ");
    scanf("%d",&aux);
    tr->estado= (aux == 0)?0:1;  //limitamos a que sea boolean y no otro valor

    return tr;
}


PILA buscarAlumno(PILA A){
    PILA B = crearPila();
    PILA tmp = crearPila();
    TRABAJO aux;
    char name[30];
    printf("\nIngresa el nombre del alumno a buscar y copiar en la otra pila: ");
    scanf("%[^\n]",name);
    getchar();

    while( !(es_vaciaPila(A)) ){
        apilar(tmp,desapilar(A));
    }

    while(!(es_vaciaPila(tmp))){
        aux = desapilar(tmp);
        apilar(A,aux);

        if(strcmp( name, aux->nombre ) == 0){
            apilar(B,aux);
        }
    }
    liberarPila(tmp);
    return B;
}


void mostrarPila(PILA ap,char c){
    PILA tmp = crearPila();
    TRABAJO aux;

    printf("\n\n----------------------------------------------------------------");
    printf("\n\t Pila [%c]\n",c);

    while( !(es_vaciaPila(ap)) ){
        apilar(tmp,desapilar(ap));
    }

    while(!es_vaciaPila(tmp)){
        aux = desapilar(tmp);
        printf("\n");
        printf("\tNombre: %s.\n", aux->nombre);
        printf("\tMateria: %s.\n", aux->materia);
        printf("\tTema: %s.\n", aux->tema);
        printf("\tCantidad de hojas: %d.\n", aux->hojas);
        printf("\tEstado: [%s].\n", (aux->estado) ? "terminado" : "sin terminar");

    }
}

void liberarPilaMsg(PILA ap){
    free(ap);
    manejaError(3);
}