/**
*
* @author FernandaDesktop
* calcular 2^n
*
*/

#include <stdio.h>
#include <stdlib.h>

int potenciaDe2(int N);

int main(){

    int N;

    printf("Entre com um numero inteiro: ");
    scanf("%d", &N);

    printf("2 elevado a %d e: %d\n", N, potenciaDe2(N));

    return 0;

}

int potenciaDe2(int N){

    if(N == 0){
        return 1;
    }else{
        return 2 * potenciaDe2(N - 1);
    }

}