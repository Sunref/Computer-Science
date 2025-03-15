/**
*
* @author FernandaDesktop
* Fatorial de um número n
*
*/

#include <stdio.h>
#include <stdlib.h>

long fatorial(int N);

int main(){

    int N;

    printf("Forneca um numero inteiro: ");
    scanf("%d", &N);

    printf("O fatorial de %d e %d.", N, fatorial(N));

    return 0;

}

long fatorial(int N){

    if(N <= 1){
        return 1;
    }else{
        return N * fatorial(N-1);
    }

}