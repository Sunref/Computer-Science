#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    float num1;
    float num2;
    float soma;
    float sub;

    printf("Entre com um numero: ");
    scanf("%f", &num1);
    printf("Entre com outro numero: ");
    scanf("%f", &num2);

    soma = num1 + num2;
    sub = num1 - num2;

    if(soma >10){
        printf("Os numeros fornecidos foram %.2f e %.2f", num1, num2);
    }
    else{
        printf("A subtracao entre %.2f e %.2f e igual a %.2f", num1, num2, sub);
    }
    return 0;
}