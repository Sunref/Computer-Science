#include <stdio.h>
#include <stdlib.h>

int main(){

    int op;
    float saldo;
    float valorDeposito;
    float valorRetirado;

    printf("Saldo inicial: ");
    scanf("%f", &saldo);
    printf("\nperacoes:");
    printf("\n    1) Deposito;");
    printf("\n    2) Saque;");
    printf("\n    3) Fim.");

    do{
        printf("\nOperacao desejada: ");
        scanf("%d", &op);

        switch(op){
            case 1:
            printf("\nValor a depositar: ");
            scanf("%f", &valorDeposito);

            saldo += valorDeposito; /*poderia ser também saldo = saldo + valorDeposito*/
            break;

            case 2: 
            printf("\nValor a sacar: ");
            scanf("%f", &valorRetirado);

            saldo -= valorRetirado; /*poderia ser também saldo = saldo - valorDeposito*/
            break;

            case 3:
            if(saldo > 0){
                printf("\nSaldo final: R$%.2f", saldo);
                printf("\nConta preferencial.");
            }else if(saldo == 0){
                printf("\nSaldo final: R$%.2f", saldo);
                printf("\nSem saldo.");
            }
            else{
                printf("\nSaldo final: -R$%.2f", saldo*-1);
                printf("\nConta devedora.");
            }
            break;

            default:
            break;
        }
    }while (op != 3);
    return 0;
}