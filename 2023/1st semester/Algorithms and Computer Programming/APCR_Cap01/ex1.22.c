#include <stdio.h>
#include <stdlib.h>

int main(){
    float  valor,desc;

    printf("Valor do produto: ");
    scanf("%f",&valor);

    desc = valor - valor*0.09;

    printf("\nPreco de venda com 9%% de desconto: %.2f",desc);
    return 0;
}