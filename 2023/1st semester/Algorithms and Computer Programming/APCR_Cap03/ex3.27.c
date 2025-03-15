#include <stdio.h>
#include <stdlib.h>

int main(){

    int c = 0;
    int i = 0;
    float peso;
    float maiorPeso = 0;
    float media = 0;
    float soma = 0;

    do{
        c++;
        printf("Entre com o peso da pessoa %d: ", c);
        scanf("%f", &peso);
        printf("\n");

        if(peso > 0){
            if(peso > maiorPeso){
                maiorPeso = peso;
            }
            if(peso > 60){
                i++;
                soma += peso; /*Poderia ser também soma = soma + peso*/
                media = soma/i;
            }
        }
    }while(peso >= 0);
        printf("\nMedia dos pesos acima de 60kg: %.2f", media);
        printf("\nA pessoa mais pesada possui %.2fkg", maiorPeso);
    return 0;
}