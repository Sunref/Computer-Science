/**
*
* @author FernandaDesktop
* Primalidade
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // biblioteca para manipulacao do tempo

int numOp = 0;

int ehPrimo(int num); //funcao que verifica se o valor gerado eh ou nao primo

int main (){

    int num;

    srand(time(NULL)); //gerando um numero aleatorio a partir do tempo atual (hora, minuto, segundo...)
    num = rand() % 100; // fazendo com que o numero gerado seja de 1-100

    printf("Numero inteiro gerado aleatoriamente (1-100): %d\n", num);

    if(ehPrimo(num) == 1){ //chamando funcao ehPrimo e comparando valores: 1 para num. primo; 0 para num. nao primo
        printf("O numero %d eh Primo (Num. Operacoes %d)", num, numOp);
    }else{
        printf("O numero %d NAO eh Primo (Num. Operacoes %d)", num, numOp);
    }

    return 0;

}

int ehPrimo(int num){ //funcao que verifica se o valor gerado eh ou nao primo

    int primo = 1;

    for(int i = 2; i < num/2; i++){
        numOp++; //contador de operacoes
        if((num % i) == 0){
            primo = 0;
            break; // para o for assim que a variavel primo troca de valor
        }
    }

    return primo;

}