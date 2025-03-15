#include <stdio.h>
#include <stdlib.h>

int main(){
    float  valorh,qtdh,descinss,saliq,salbrut;

    printf("Valor da hora/aula: ");
    scanf("%f",&valorh);
    printf("Quantidade de aulas: ");
    scanf("%f",&qtdh);
    printf("Porcentagem de desconto do INSS: ");
    scanf("%f",&descinss);


    salbrut = valorh*qtdh;
    saliq = salbrut - salbrut * (descinss / 100);

    printf("\nSalario Liquido: %.2f",saliq);
    return 0;
}