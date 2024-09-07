#include<stdiio.h>
#include "Pila.h"

void Datosentrada(PILA);
void mostrarPila(PILA);
 

void main(){
	PILA P1;
	P1 = crearPila();
	
}
void Datosentrada(PILA s){
	int op, num;
	do{
		printf("ingresa un dato\n")
		
