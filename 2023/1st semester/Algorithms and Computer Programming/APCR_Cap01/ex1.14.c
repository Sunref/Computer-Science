#include <stdio.h>
#include <stdlib.h>


int main(){
    float  valorld,prmtro,area;

    printf("Valor do lado: ");
    scanf("%f",&valorld);

    prmtro = valorld*4;
    area = valorld*valorld;

    printf("Perimetro = %.2f\n",prmtro);
    printf("Area = %.2f",area);

    return 0;
}