#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int calculaDigito(int n);

int main(){

    int n;
    int dgi;

    printf("\nNumero: ");
    scanf("%d", &n);
    if (n <= 0 || n > 9999){
        do{
            printf("\nNumero: ");
            scanf("%d", &n);
        }while (n <= 0 || n > 9999);
    }

    dgi = calculaDigito(n);

    printf("Digito verificador de %d: %d",n,dgi);

    return 0;
}

int calculaDigito(int n){

    int arrayt[4] = {0};
    int c = 1000;
    int c2 = 2;
    int soma = 0;
    int digito;

    for(int i = 0; i < 4; i++){
        if(i == 0){
            arrayt[i] = n/c;
        }else{
            arrayt[i] = (n/c)%10;
        }
        c /= 10;
    }

    for (int i = 3; i >= 0; i--){
        soma += arrayt[i]*c2;
        c2++;
    }

    digito = 11 - (soma % 11);

    if(digito == 10 || digito == 11){
        return 0;
    }else{
        return digito;
    }
}
