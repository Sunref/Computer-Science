/**
*
* @author FernandaDesktop
* Fatorial de um número n iterativo
*
*/

#include <stdio.h>
#include <stdlib.h>

long fatorial(int N);

int main(){

    int N;

    printf("Forneca um numero interio: ");
    scanf("%d", &N);

    printf("O fatorial de %d e %d.", N, fatorial(N));

    return 0;

}

long fatorial(int N){

    int temp = 1;

    if(N <= 1){
        return 1;
    }

    for(int i = 2; i <= N; i++){
        temp *= i;
    }

    return temp;

}