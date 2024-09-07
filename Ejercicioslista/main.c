#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void llenar(LISTA*);
void liberarLista(LISTA );
void manejaMsg(int n);
void igualmayor6(LISTA);
void examendic(LISTA);
void examenmarz(LISTA);

void main(){
    LISTA L = crearLista();
    llenar(&L);
    examendic(L);
    examenmarz(L);
    igualmayor6(L);
    liberarLista(L);
}

void examenmarz(LISTA L){
    Nodo_Lista *aux = L;
    LISTA temp = crearLista();
    while(aux != NULL){
        Nodo_Lista *nvo = crearNodoLista();
        if(aux->dato.calif < 4){
            nvo->dato = aux->dato;
            if (es_vaciaLista(temp)==TRUE){
                temp = nvo;
            }else{
                Nodo_Lista *aux2 = temp;
                while(aux2->siguiente != NULL){
                    aux2 = aux2->siguiente;
                }
                aux2->siguiente = nvo;
            }
        }
        aux = aux->siguiente;
    }
    printf("Los datos de los alumnos que presentan calificacin en marzo son:\n");
    visualizaLista(temp);
    liberarLista(temp);
}

void examendic(LISTA L){
    
    Nodo_Lista *aux = L;
    LISTA temp = crearLista();
    while(aux != NULL){
        Nodo_Lista *nvo = crearNodoLista();
        if(aux->dato.calif < 6 && aux->dato.calif >= 4 ){
            nvo->dato = aux->dato;
            if (es_vaciaLista(temp)==TRUE){
                temp = nvo;
            }else{
                Nodo_Lista *aux2 = temp;
                while(aux2->siguiente != NULL){
                    aux2 = aux2->siguiente;
                }
                aux2->siguiente = nvo;
            }
        }
        aux = aux->siguiente;
    }
    printf("Los datos de los alumnos que presentan calificacin en marzo son:\n");
    visualizaLista(temp);
    liberarLista(temp);
}

void igualmayor6(LISTA L){
    
    Nodo_Lista *aux = L;
    LISTA temp = crearLista();
    while(aux != NULL){
        Nodo_Lista *nvo = crearNodoLista();
        if(aux->dato.calif > 6){
            nvo->dato = aux->dato;
            if (es_vaciaLista(temp)==TRUE){
                temp = nvo;
            }else{
                Nodo_Lista *aux2 = temp;
                while(aux2->siguiente != NULL){
                    aux2 = aux2->siguiente;
                }
                aux2->siguiente = nvo;
            }
        }
        aux = aux->siguiente;
    }
    printf("Los datos de los alumnos que presentan calificacin en marzo son:\n");
    visualizaLista(temp);
    liberarLista(temp);
}

void llenar(LISTA *AP){
    int op = 1;
    Alumno m;
    while(op==1){
        printf("Digite el nombre del alumno: ");
        scanf("%s",m.nombre);
        printf("Digite la calificacion del alumno: ");
        scanf("%d",&m.calif);
        printf("Desea agregar otro animal: (1.-SI 0.-NO): ");
        scanf("%d",&op);
    }
    printf("\n");
}

void liberarLista(LISTA L){
    free(L);
    manejaMsg(2);
}

void manejaMsg(int n){
    char * errores[]={"No hay memoria disponible\n","La lista esta vacia\n","Memoria liberada\n"};
    printf("%s", errores[n]);
}
