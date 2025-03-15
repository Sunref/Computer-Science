#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    float num1;
    float num2;
    float num3;

    printf("N1: ");
    scanf("%f", &num1);
    printf("N2: ");
    scanf("%f", &num2);
    printf("N3: ");
    scanf("%f", &num3);

    if(num1 >= num2 && num2 >= num3){
        printf("A soma dos dois numeros maiores fornecidos e %.2f", num1 + num2);
    }else if(num2 >= num1 && num1 >= num3){
        printf("A soma dos dois numeros maiores fornecidos e %.2f", num2 + num1);
    }else if(num1 >= num3 && num3 >= num2){
        printf("A soma dos dois numeros maiores fornecidos e %.2f", num1 + num3);
    }else if(num3 >= num1 && num1 >= num2){
        printf("A soma dos dois numeros maiores fornecidos e %.2f", num3 + num1);
    }else if(num2 >= num3 && num3 >= num1){
        printf("A soma dos dois numeros maiores fornecidos e %.2f", num2 + num3);
    }else{
        printf("A soma dos dois numeros maiores fornecidos e %.2f", num3 + num2);
    }
    return 0;
}