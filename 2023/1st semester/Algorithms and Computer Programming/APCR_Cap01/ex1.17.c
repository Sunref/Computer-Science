#include <stdio.h>
#include <stdlib.h>


int main(){
    float  basema,baseme,alt,area;

    printf("Valor do base: ");
    scanf("%f",&basema);
    printf("Valor do base: ");
    scanf("%f",&baseme);
    printf("Valor do altura: ");
    scanf("%f",&alt);

    area = (basema+baseme)*alt/2;

    printf("Area = %.2f",area);
    
    return 0;
}
