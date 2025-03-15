#include <stdio.h>
#include <stdlib.h>

int main(){
    float  tempfar,cel;

    printf("Temperatura em graus Fahrenheit: ");
    scanf("%f",&tempfar);

    cel = (tempfar-32)/1.8;

    printf("%.2f graus Fahrenheit correspondem a %.2f graus Celsius",tempfar,cel);
    return 0;
}