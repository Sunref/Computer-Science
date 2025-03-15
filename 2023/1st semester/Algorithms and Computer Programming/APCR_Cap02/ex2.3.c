#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    int num1;
    int num2;

    printf("Entre com um numero: ");
    scanf("%d", &num1);
    printf("Entre com outro numero: ");
    scanf("%d", &num2);

    if(num1 >= num2){
        printf("Ordem decrescente: %d >= %d", num1, num2);
    }
    else{
        printf("Ordem decrescente: %d >= %d", num2, num1);
    }
    return 0;
}