#include <stdio.h>
#include <stdlib.h>

int main(){
    int  nasc,atual,idade;

    printf("Ano de nascimento: ");
    scanf("%d",&nasc);
    printf("\nAno atual: ");
    scanf("%d",&atual);

    idade = atual - nasc;
    
    printf("\nIdade aproximada: %d anos",idade);

    return 0;
}