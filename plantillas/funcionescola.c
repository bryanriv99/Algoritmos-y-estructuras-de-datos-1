//da el tamaño de la cola
int tamCola(COLA);

int tamCola(COLA C){
    int n;
    while(!es_vaciaCola(C)){
        desencolar(C);
        n++;
    }
    return n;
}

// da el ultimo elemento de la cola
int ultimocola(COLA);

int ultimocola(COLA C){
    int n;
    COLA temp=crearCola();
    while(!es_vaciaCola(C)){
        n=desencolar(C);
        encolar(temp,n);
    }
    return n;
}

//encola una cola en otra cola
COLA ponalaCola(COLA,COLA);

COLA ponalaCola(COLA C1,COLA C2){
    int n;
    while(!es_vaciaCola(C2)){
        n=desencolar(C2);
        encolar(C1,n);
    }
    return C1;
}

//mezcla una cola con otra
COLA mezclaCola(COLA C1, COLA C2){
	COLA C3 = crearCola();
	Cola temp1 = *C1;
	Cola temp2 = *C2;
	int n;
	while(!es_vaciaCola(&temp1)&&!es_vaciaCola(&temp2)){
		encolar(C3, desencolar(&temp1));
		encolar(C3, desencolar(&temp2));
	}
	while(!es_vaciaCola(&temp1))
			encolar(C3, desencolar(&temp1));
	while(!es_vaciaCola(&temp2))
			encolar(C3, desencolar(&temp2));
	return C3;
}

//maneja mensaje
void manejaMsg(int);

void manejaMsg(int msg) {
    char *mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .", "Pila vacía . . .", "Pila llena . . .","Cola llena . . .","Cola vacia . . ."};
    printf("%s\n", mensajes[msg]);
}