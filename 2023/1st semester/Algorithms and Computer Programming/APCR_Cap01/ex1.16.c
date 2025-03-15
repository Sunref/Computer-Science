#include <stdio.h>
#include <stdlib.h>


int main(){
    float  base,alt,area;

    printf("Valor do base: ");
    scanf("%f",&base);
    printf("Valor do altura: ");
    scanf("%f",&alt);

    area = (base*alt)/2;

    printf("Area = %.2f",area);

    return 0;
}
