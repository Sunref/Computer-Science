#include <stdio.h>
#include <stdlib.h>

int main(){

    int c = 0;
    float num;
    float soma = 0;
    float media = 0;

    do{
        printf("Entre com um valor: ");
        scanf("%f", &num);
        printf("\n");

        if(num > 0){
            soma += num; /*Poderia ser também soma = soma + num*/
            c++;
            media = soma/c;
        }
    }while(num > 0);
        printf("\nSomatorio: %.2f", soma);
        printf("\nMedia: %.2f", media);
        printf("\nQuantidade: %d", c);
    return 0;
}