#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float areaCirculo (float raio);
float circunferenciaCirculo (float raio);

int main(){

    float raio;

    printf("Raio: ");
    scanf("%f", &raio);

    printf("\nArea = %.2f", areaCirculo(raio));
    printf("\nCircunferencia = %.2f", circunferenciaCirculo(raio));
    return 0;
}

float areaCirculo (float raio){
    return acos(-1) * (raio * raio);
}
float circunferenciaCirculo (float raio){
    return 2 * acos(-1) * raio;
}