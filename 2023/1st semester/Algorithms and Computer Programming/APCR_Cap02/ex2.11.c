#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    float a;
    float b;
    float y;

    printf("alfa: ");
    scanf("%f", &a);
    printf("beta: ");
    scanf("%f", &b);
    printf("gama: ");
    scanf("%f", &y);

    if((a + b + y <= 180)){

        if(a == 90 || b == 90 || y == 90){
            printf("Triangulo RETANGULO");
        }else if(a > 90 || b > 90 || y > 90){
            printf("Triangulo OBTUSANGULO");
        }else{
            printf("Triangulo ACUTANGULO");
        }
    }else{
        printf("As medidas fornecidas dos angulos nao representam um triangulo valido!");
    }
    return 0;
}