#include <stdio.h>
#include <stdlib.h>

int main(){

    int valor;
    int c = 0;
    int maiorNumero = 0;
    int menorNumero = 0;

    do{
        c++;
        printf("Entre com um valor: ");
        scanf("%d", &valor);
        printf("\n");

        if(valor >= 0){
            if(valor > maiorNumero){
                maiorNumero = valor;
            }
            if(valor < menorNumero){
                menorNumero = valor;
            }
        }else if(valor < 0 && c == 1 || c == 2){
            menorNumero = maiorNumero;
        }
    }while (valor >= 0);
        printf("\nMenor numero: %d", menorNumero);
        printf("\nMaior numero: %d", maiorNumero);
    return 0;
}