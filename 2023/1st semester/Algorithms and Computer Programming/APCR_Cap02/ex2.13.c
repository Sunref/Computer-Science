#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    float nota1;
    float nota2;
    float notaOptat;
    float M;

    printf("Nota Av. 1: ");
    scanf("%f", &nota1);
    printf("Nota Av. 2: ");
    scanf("%f", &nota2);
    printf("Nota Optativa: ");
    scanf("%f", &notaOptat);

    if(notaOptat > nota1){
        M = (notaOptat + nota2)/2;
    }else if (notaOptat > nota2){
        M = (notaOptat + nota1)/2;
    }else{
        M = (nota1 + nota2)/2;
    }

    if(M >= 6){
        printf("Media: %.2f", M);
        printf("\nAprovado!");
    }else if(M >= 4 && M < 6){
        printf("Media: %.2f", M);
        printf("\nExame.");
    }else{
        printf("Media: %.2f", M);
        printf("\nReprovado...");
    }
    return 0;
}