#include <stdio.h>
#include <stdlib.h>

int main(){
    int  num,prox,ant,med;

    printf("Forneca um numero inteiro: ");
    scanf("%d",&num);

    printf("\nSucessor de %d: %d",num,num+1);
    printf("\nAntecessor de %d: %d",num,num-1);
    return 0;
}
