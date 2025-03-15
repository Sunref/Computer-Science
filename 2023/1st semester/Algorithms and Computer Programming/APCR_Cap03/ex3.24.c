#include <stdio.h>
#include <stdlib.h>

int main(){

    int idade;
    int c = 0;
    int ime = 0;
    int ima = 0;

    while(idade > 0){
        c++;
        printf("Idade da pessoa %d: ", c);
        scanf("%d", &idade);
        printf("\n");

        if(idade > 0){
            if(idade < 21){
                ima++;
            }else if(idade > 50){
                ime++;
            }
        }
    }
    printf("Total de pessoas menores de 21 anos: %d", ima);
    printf("\nTotal de pessoas com mais de 50 anos: %d", ime);
    return 0;
}