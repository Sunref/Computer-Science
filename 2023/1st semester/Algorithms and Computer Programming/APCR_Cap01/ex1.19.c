#include <stdio.h>
#include <stdlib.h>


int main(){
    float  ralho,diametro,circun,area,pi = 3.141592;

    printf("Valor do raio do circulo: ");
    scanf("%f",&ralho);
    diametro = 2*ralho;
    circun = 2*pi*ralho;
    area = pi*(ralho*ralho);

    printf("\nDiametro = %.2f\n",diametro);
    printf("Circunferencia = %.2f\n",circun);
    printf("Area = %.2f",area);

    return 0;
}