#include<stdio.h>

void area(int,int);


int main(){
    int a,b,c;

    printf("Dame los datos de la base\n");
    scanf("%d",&b);
    printf("%Dame los datos de la altura\n");
    scanf("%d",&a);

    area(a,b);


    return 0;

}
void area(int a, int b){
    int c;
    c=(a*b)/2;
    printf("El area del triangulo es %d",c);
}
