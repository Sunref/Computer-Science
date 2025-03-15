#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

    float b;
    float e;

    printf("Base: ");
    scanf("%f", &b);
    printf("Expoente: ");
    scanf("%f", &e);

    printf("%.2f ^ %.2f = %.2f\n", b, e, pow(b, e));
    return 0;
}