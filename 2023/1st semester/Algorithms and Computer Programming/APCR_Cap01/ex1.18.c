#include <stdio.h>
#include <stdlib.h>

int main(){
    float  diagma,diagme,area;

    printf("Valor da diagonal maior: ");
    scanf("%f", &diagma);
    printf("Valor da diagonal menor: ");
    scanf("%f", &diagme);

    area = (diagma*diagme)/2;

    printf("Area = %.2f",area);

    return 0;
}
