#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    int num1;
    int num2;
    int num3;

    printf("N1: ");
    scanf("%d", &num1);
    printf("N2: ");
    scanf("%d", &num2);
    printf("N3: ");
    scanf("%d", &num3);

    if(num1 <= num2 && num2 <= num3){
        printf("Ordem crescente: %d <= %d <= %d", num1, num2, num3);
    }else if(num2 <= num1 && num1 <= num3){
        printf("Ordem crescente: %d <= %d <= %d", num2, num1, num3);
    }else if(num3 <= num2 && num2 <= num1){
        printf("Ordem crescente: %d <= %d <= %d", num3, num2, num1);
    }else if(num1 <= num3 && num3 <= num2){
        printf("Ordem crescente: %d <= %d <= %d", num1, num3, num2);
    }else if(num2 <= num3 && num3 <= num1){
        printf("Ordem crescente: %d <= %d <= %d", num2, num3, num1);
    }else if(num3 <= num1 && num1 <= num2){
        printf("Ordem crescente: %d <= %d <= %d", num2, num3, num1);
    }
    return 0;
}