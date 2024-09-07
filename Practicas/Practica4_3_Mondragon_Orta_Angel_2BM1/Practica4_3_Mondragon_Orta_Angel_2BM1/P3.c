#include<stdio.h>
#include<stdlib.h>
#include "pila.h"

void llenarPila(PILA S){
    int n;
    printf("\nIngrese datos para la pila (Si ingresa -1 dejara de ingresar): ");
    while(n!=-1){
        printf("\nIngrese el dato: ");
        scanf("%d",&n);
        if(n!=-1)
            apilar(S,n);
    }
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ","PILA VACIA","PILA LLENA"};
     printf("%s", mensajes[msg] );
}
void mostrarPila(PILA S){
    Pila Copia = *S;
    int e;
    printf("\n[");
    while(!esVacia(&Copia)){
        printf("  %d ",desapilar(&Copia));
    }
    printf("]");
}

PILA llenarRegistro(PILA S,PILA operaciones){
    PILA registro = crearPila();
    Pila copiaS = *S;
    Pila copiaOperaciones = *operaciones;

    while(!esVacia(&copiaS)){
        char e = desapilar(&copiaOperaciones);
        if(esVacia(registro)){
            int s1 = desapilar(&copiaS);
            int s2 = desapilar(&copiaS);
            printf("\nLD %c",s2);
            apilar(registro,s2);
            if(e=='-'){
                printf("\nSB %c",s1);
                s2-=s1;
                desapilar(registro);
                apilar(registro,s2);
            }
            if(e=='+'){
                printf("\nAD %c",s1);
                s2+=s1;
                desapilar(registro);
                apilar(registro,s2);
            }
        }else if(!esVacia(&copiaOperaciones)){
            int s1 = desapilar(registro);
            int s2 = desapilar(&copiaS);
            if(e=='-'){
                printf("\nSB %c",s2);
                s1-=s2;
                apilar(registro,s2);
            }
            if(e=='+'){
                printf("\nAD %c",s2);
                s1+=s2;
                apilar(registro,s2);
            }

            
        }else {
            int s1 = desapilar(registro);
            int s2 = desapilar(&copiaS);
            if(e=='-'){
                printf("\nSB %c",s2);
                s1-=s2;
                apilar(registro,s2);
            }
            if(e=='+'){
                printf("\nAD %c",s2);
                s1+=s2;
                apilar(registro,s2);
            }
            printf("\nST %c\n",s2);
            break;
        }

        
    }

}

void leerCad(PILA S,PILA operaciones){
    char cad[100];
    PILA aux = crearPila();

    printf("\nIngrese la expresion: ");
    scanf("%[^\n]",cad);
    getchar();

    int i=0;
    char e;
    while(cad[i]!='\0'){
        e=cad[i];
        if(e=='-' || e=='+'){
            apilar(aux,e);
        }else apilar(S,e);
        i++;
    }

    while(!esVacia(aux))
        apilar(operaciones,desapilar(aux));

}

void liberarMemoria(PILA S){
    free(S);
    manejaMsg(1);
}
void main(){
    PILA S;
    PILA operaciones;
    S=crearPila();
    operaciones = crearPila();
    
    leerCad(S,operaciones);
    llenarRegistro(S,operaciones);

    liberarMemoria(S);
    liberarMemoria(operaciones);
    
}
