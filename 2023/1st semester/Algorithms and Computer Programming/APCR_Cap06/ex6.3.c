#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float num;

    printf("Numero: ");
    scanf("%f", &num);

    printf("Maior inteiro mais proximo: %.2f", ceil(num));
    printf("\nMenor inteiro mais proximo: %.2f", floor(num));
    return 0;
}