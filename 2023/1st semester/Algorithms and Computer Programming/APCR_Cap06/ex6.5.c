#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float num;

    printf("Numero: ");
    scanf("%f", &num);

    if(num > 0){
        printf("Raiz quadrada de %.2f: %.2f", num, sqrt(num));
    }else{
        printf("Quadrado de %.2f: %.2f", num, pow(num, 2));
    }
    return 0;
}