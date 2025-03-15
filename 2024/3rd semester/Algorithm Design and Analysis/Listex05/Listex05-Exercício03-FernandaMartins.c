/**
*
* @author FernandaDesktop
* Comb(n, k)
*
*/

#include <stdio.h>
#include <stdlib.h>

long fatorial(int N);
int comb(int N, int K, long fatorialN);

int main(){

    int N;
    int K;

    printf("Entre com o valor de grupos distintos (k): ");
    scanf("%d", &K);
    printf("Entre com o valor de pessoas (n): ");
    scanf("%d", &N);

    if(K > N){
        printf("O numero de pessoas em cada grupo nao pode ser maior que o numero total de pessoas\n");
        return 1;
    }

    long fatorialN = fatorial(N);

    printf("A quantidade de combinacoes C(n, k) = C(%d, %d) = %d", N, K, comb(N, K, fatorialN));

    return 0;

}

long fatorial(int N){

    if(N <= 1){
        return 1;
    }else{
        return N * fatorial(N-1);
    }

}

int comb(int N, int K, long fatorialN){

    if(K == 0 || K == N){
        return 1;
    }else{
        return fatorialN / (fatorial(K) * fatorial(N - K));
    }

}