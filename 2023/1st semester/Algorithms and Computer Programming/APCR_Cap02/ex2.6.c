#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    float num;
    float metade;
    float triplo;

    printf("Ente com um valor: ");
    scanf("%f", &num);

    metade = num/2;
    triplo = num*3;

    if(num > 20){
        printf("A metade de %.2f e %.2f", num, metade);
    }
    else{
        printf("O triplo de %.2f e %.2f", num, triplo);
    }
    return 0;
}