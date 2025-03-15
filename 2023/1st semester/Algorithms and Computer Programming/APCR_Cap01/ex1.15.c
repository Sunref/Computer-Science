#include <stdio.h>
#include <stdlib.h>


int main(){
    float  valorlarg,alt,area,perimetro;


    printf("Valor do largura: ");
    scanf("%f",&valorlarg);
    printf("Valor do altura: ");
    scanf("%f",&alt);


    perimetro = valorlarg*2 + alt*2;
    area = valorlarg*alt;

    printf("Perimetro = %.2f\n",perimetro);
    printf("Area = %.2f",area);
    
    return 0;
}