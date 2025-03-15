#include <stdio.h>
#include <stdlib.h>

int main(){
    float  cel,tempfar;

    printf("Temperatura em graus Celsius: ");
    scanf("%f",&cel);

    tempfar = 1.8*cel + 32;

    printf("%.2f graus Celsius correspondem a %.2f graus Fahrenheit ",cel,tempfar);
    return 0;
}