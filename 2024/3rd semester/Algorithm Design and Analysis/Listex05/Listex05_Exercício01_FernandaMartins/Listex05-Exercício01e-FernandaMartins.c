/**
*
* @author FernandaDesktop
* Fibonacci
*
*/

#include <stdio.h>
#include <stdlib.h>

int fib(int N);

int main(){

    int N;

    printf("Entre com um numero inteiro: ");
    scanf("%d", &N);

    printf("O fibonacci de %d e %d", N, fib(N));

    return 0;

}

int fib(int N){

    if(N < 2){
        return 1;
    }else{
        return fib(N - 1)+fib(N - 2);
    }

}