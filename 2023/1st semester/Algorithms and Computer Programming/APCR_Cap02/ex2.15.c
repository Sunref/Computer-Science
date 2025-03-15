#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    int idade;

    printf("Entre com sua idade: ");
    scanf("%d", &idade);

    if(idade < 16){
        printf("Nao eleitor.");
    }else if(idade >= 18 && idade <= 65){
        printf("Eleitor obrigatorio.");
    }else{
        printf("Eleitor facultativo.");
    }
    return 0;
}