#include <stdio.h>
#include <stdlib.h>

int main(){
    int  num1, num2,med;

    printf("Primeiro número: ");
    scanf("%d",&num1);
    printf("\nSegundo número: ");
    scanf("%d",&num2);

    med = (num1 + num2)/2;

    printf("\nMedia aritmetica: %d",med);
    return 0;
}
