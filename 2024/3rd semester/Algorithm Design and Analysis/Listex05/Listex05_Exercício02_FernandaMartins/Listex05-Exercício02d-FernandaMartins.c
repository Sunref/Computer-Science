/**
*
* @author FernandaDesktop
* Serie Harmonica
*
*/

#include <stdio.h>
#include <stdlib.h>

double harmonica(int N);

int main(){

    int N;

    printf("Entre com um valor inteiro maior que 0: ");
    scanf("%d", &N);

    if(N < 1){
        printf("Favor entrar com um numero inteiro maior que 0");
        return 1;
    }

    printf("O %d-esimo numero harmonico e: %.6f\n", N, harmonica(N));

    return 0;

}

double harmonica(int N){

    if(N == 1){
        return 1.0;
    }else{
        return harmonica(N - 1) + (1.0/N);
    }

}
