#include <stdio.h>
#include <stdlib.h>

int main(){

    int num;
    int f= 1;

    printf("Numero 5: ");
    scanf("%d", &num);

    if(num > 0){
        for(int i = num; i > 0; i--){
            f *= i;
        }
        printf("\n%d! = %d", num, f);
    }else{
        printf("Nao ha fatorial de numero negativo.");
    }
    return 0;
}