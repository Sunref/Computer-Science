/**
*
* @author FernandaDesktop
* Fibonacci iterativo (rever depois, nao tava dando bom)
*
*/

#include <stdio.h>
#include <stdlib.h>

int fibIterativo(int N);

int main(){

    int N;

    printf("Entre com um numero inteiro: ");
    scanf("%d", &N);

    printf("O fibonacci de %d e %d", N, fibIterativo(N));

    return 0;

}

int fibIterativo(int N){

    int i = 1;
    int fib = 1;
    int anterior = 0;
    int temp = 0;

    while (i < N){
        temp = fib;
        fib = fib + anterior;
        anterior = temp;
        i++;
    }

    return fib;

}