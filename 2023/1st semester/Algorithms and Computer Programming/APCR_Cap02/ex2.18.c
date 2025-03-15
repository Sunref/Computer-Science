#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    float num1;
    float num2;
    float soma;
    float sub;
    float mult;
    float div;
    char op;
    
    printf("N1: ");
    scanf("%f", &num1);
    printf("\nN2: ");
    scanf("%f", &num2);
    printf("\nEscolha uma operacao de acordo com o menu: \n        +) Adicao;\n        -) Subtracao;\n        *) Multiplicacao;\n        /) Divisao.\nOperacao: ");
    scanf(" %c", &op);


    switch (op){
        case '+':
            soma = num1 + num2;
            printf("\n%.2f + %.2f = %.2f", num1, num2, soma);
            break;

        case '-':
            sub = num1 - num2;
            printf("\n%.2f - %.2f = %.2f", num1, num2, sub);
            break;

        case '*':
            mult = num1 * num2;
            printf("\n%.2f * %.2f = %.2f", num1, num2, mult);
            break;

        case '/':
            div = num1 / num2;
            printf("\n%.2f / %.2f = %.2f", num1, num2, div);
            break;

        default:
            printf("\nOpcao invalida!");
    }      
    return 0;
}