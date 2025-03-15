#include <stdio.h>
#include <stdlib.h>

int main(){

    float nota;
    float media;
    float soma;

    printf("Forneca a nota de 10 alunos: ");

    for(int i = 0; i < 10; i++){
        printf("Nota %d: ", i + 1);
        scanf("%f", &nota);
        printf("\n");

        soma += nota; /*Poderia ser também soma = soma + nota*/
    }

    media = soma/10;

    printf("A media aritmetica das dez notas e: %.2f", media);
    return 0;
}