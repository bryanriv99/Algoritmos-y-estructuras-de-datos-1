//funciones de pila
//identifica so los parentesis corchetes o llaves estan equilibrados 
void identificar(PILA);

//Leer cadena
void leer(char *);

//invertir cadena pasandola a una pila y devolviendo la invertida en una cadena
void invertircad(char *, char *);

//mostrar cadena
void mostrarInvertida(char *);

//da la cantidad de elementos de la pila
int numelem(PILA);

//da el elemento del fondo de la pila
void elemfondo(PILA);

//copia de una pila a otra
void copiapila(PILA);

//agregar elemento
void agregarElem(PILA);

//mostrar una pila de caracteres
void mostrarPila(PILA);

//menu
void menu(PILA);

//invertir pila
PILA invertir(PILA);

//maneja mensaje
void manejaMsg(int);

//copia la pila 
PILA copiarPila(PILA);

PILA copiarPila(PILA P){
    PILA aux1 = crearPila();
    PILA aux2 = crearPila();
    int n,m;
    while(!es_vaciaPila(P)){
        n=desapilar(P);
        apilar(aux1,n);
    }
    while(!es_vaciaPila(aux1)){
        m=desapilar(aux1);
        apilar(aux2,m);
    }
    return aux2;
}

void manejaMsg(int msg) {
    char *mensajes[] = {"No hay memoria disponible . . .", "Se ha liberado la memoria . . .", "Pila vacía . . .", "Pila llena . . ."};
    printf("%s\n", mensajes[msg]);
}

PILA invertir(PILA P){
    PILA aux = crearPila();
    int a;
    while(!es_vaciaPila(P)){
        a=desapilar(P);
        apilar(aux,a);
    }
    return aux;
}

void menu(PILA S) {
    int respuesta; 
    PILA a,b,c,d;
    a=crearPila();
    b=crearPila();
    c=crearPila();
    d=crearPila();

    while (respuesta != -1) {
        printf("\n\nMenu: \n1) Insertar Pila \n2) Calcular numero de elementos \n3) Elemento del fondo de la pila \n4) Copiar una pila a otra \n0) Salir\nIntroduzca una opcion: ");
        scanf("%d", &respuesta);
        switch (respuesta) {
            case 1:
                datosEntrada(S);
                break;
            case 2:
                elempila(S);
                break;
            case 3:
                elemfondo(S);
                break;
            case 4: copiapila(S);
                break;
            case 0:
                respuesta = -1;
                break;
            default:
                printf("\nIntroduzca una opcion valida!: ");
                break;
        }
    }
}

void mostrarPila(PILA P){
	PILA temp = crearPila();
	char n[25];
	printf("Cesto de Compras: \n");
	while(!es_vaciaPila(P)){
		strcpy(n, desapilar(P));
		printf("%s\n",n);
		apilar(temp, n);
	}
	while(!es_vaciaPila(temp))
		apilar(P, desapilar(temp));
}

void agregarElem(PILA P){
	char n[25];
	getchar();
	printf("Ingrese el producto a agregar a la cesta:\n");
	scanf("%[^\n]",&n);
	printf("Se agrego %s al cesto\n",n);
	apilar(P, n);
}

void elemfondo(PILA S){
    PILA a,b;
    a = crearPila();
    b = crearPila();
    while(!es_vaciaPila(S)){
        char x = desapilar(S);
        apilar(a,x);
    }
    
        char z = desapilar(a);

    printf("El elemento del fondo es: %c",z);
}

int numelem(PILA P){
    int cont=0;

    while(!es_vaciaPila(P)){
        desapilar(P);
        cont++;
    }
    return cont;
}

void mostrarInvertida(char *cadena){
    printf("\n----------------------------------------------\n\tCadena Invertida: %s\n\n",cadena);
}

void invertircad(char *vieja, char *nueva){
    PILA p = crearPila();
    int aux = 0;
    while(vieja[aux] != '\0'){
        apilar(p,vieja[aux]);
        aux++;
    }
    aux = 0;
    while(!(es_vaciaPila(p))){
        nueva[aux] = desapilar(p);
        aux++;
    }
    nueva[aux] = '\0';

}

void leer(char *cadena) {
  int cont = 0;

  printf("\n Introduzca la cadena a invertir: ");
  while ((cadena[cont++] = getchar()) != '\n');
  cadena[--cont] = '\0';
}

void identificar(PILA S){
    int contPA=0;
    int contPC=0;
    int contCA=0;
    int contCC=0;
    int contLA=0;
    int contLC=0;

    PILA a,b,c,d,e,f,g,h;
    a=crearPila();
    b=crearPila();
    c=crearPila();
    d=crearPila();
    e=crearPila();
    f=crearPila();
    g=crearPila();
    h=crearPila();

    while(!es_vaciaPila(S)){
        int elemento = desapilar(S);
        if(elemento != '(' && elemento != ')' && elemento != '{' && elemento != '}' && elemento != '[' && elemento != ']'){
            apilar(a, elemento);
        } else if (elemento == '(') {
            apilar(b, elemento);
        } else if(elemento == ')') {
            apilar(c, elemento);
        } else if (elemento == '{') {
            apilar(d, elemento);
        } else if (elemento == '}') {
            apilar(e, elemento);
        } else if (elemento == '[') {
            apilar(f, elemento);
        } else if (elemento == ']') {
            apilar(g, elemento);
        }
    }
    
    while(!es_vaciaPila(b)){
        int x=desapilar(b);
        apilar(h,x);
        contPA++;
    }

    while(!es_vaciaPila(c)){
        int z=desapilar(c);
        apilar(h,z);
        contPC++;
    }
    
    while(!es_vaciaPila(d)){
        int y=desapilar(d);
        apilar(h,y);
        contLA++;
    }

    while(!es_vaciaPila(e)){
        int w=desapilar(e);
        apilar(h,w);
        contLC++;
    }

    while(!es_vaciaPila(f)){
        int q=desapilar(f);
        apilar(h,q);
        contCA++;
    }

    while(!es_vaciaPila(g)){
        int r=desapilar(g);
        apilar(h,r);
        contCC++;
    }

    if(contPA==contPC){
        printf("\nLos parentesis estan equilibrados\n");
    } else {
        printf("\nLos parentesis no estan equilibrados\n");
    }

    if(contLA==contLC){
        printf("\nLas llaves estan equilibradas\n");
    } else {
        printf("\nLas llaves no estan equilibradas\n");
    }

    if(contCA == contCC){ 
        printf("\nLos corchetes estan equilibrados\n");
    } else {
        printf("\nLos corchetes no estan equilibrados\n");
    }
}
