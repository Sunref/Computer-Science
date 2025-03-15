/**
*
* @author FernandaDesktop
* Maximo Divisor Comum (MDC)
*
*/

#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b);

int main(){

    int N1;
    int N2;

    printf("Entre com o primeiro numero inteiro: ");
    scanf("%d", &N1);
    printf("Entre com o primeiro numero inteiro: ");
    scanf("%d", &N2);

    if(N1 < 0 || N2 < 0){
        printf("Favor entrar com dois numeros positivos");
        return 1;
    }

    printf("O maximo divisor comum (MDC) entre %d e %d = %d", N1, N2, mdc(N1, N2));

    return 0;

}

int mdc(int a, int b){

    if(b == 0){
        return a;
    }else{
        return mdc(b, a % b);
    }

}