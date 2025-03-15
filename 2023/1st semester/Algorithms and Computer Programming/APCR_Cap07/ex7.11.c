#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

bool numeroCorreto(int n);
int obtemDigito(int n);
int obtemNumero(int n);
int calculaDigito(int n);

int main(){

    int n;
    int ncoret;
    int num;
    int digt;
    int digc;

    printf("\nNumero: ");
    scanf("%d", &n);
    if (n < 10 || n > 99999){
        do{
            printf("\nNumero: ");
            scanf("%d", &n);
        }while (n <= 0 || n > 9999);
    }

    digc = calculaDigito(n);
    digt = obtemDigito(n);
    num = obtemNumero(n);
    ncoret = numeroCorreto(n);

    printf("\nNumero completo: %d", n);
    printf("\nNumero: %d", num);
    printf("\nDigito: %d", digt);
    printf("\nDigito calculado: %d", digc);

    if(numeroCorreto(n) == true){
        printf("\nO numero fornecido esta correto!");
    }else{
        printf("\nO numero fornecido esta incorreto!");
    }
    return 0;
}

bool numeroCorreto(int n){

    int digito;
    int digitocalc;

    digito = obtemDigito(n);
    digitocalc = calculaDigito(n);

    if(digitocalc == digito){
        return true;
    }else{
        return false;
    }
}

int obtemDigito(int n){

    int arrayt[5] = {0};
    int c = 10000;
    int num;

    for(int i = 0; i < 5; i++){
        if(i == 0){
            arrayt[i] = n/c;
        }else{
            arrayt[i] = (n/c)%10;
        }
        c /= 10;
    }

    num = arrayt[4];

    return num;
}

int obtemNumero(int n){

    int arrayt[5] = {0};
    int c = 10000;
    int num;

    for(int i = 0; i < 5; i++){
        if(i == 0){
            arrayt[i] = n/c;
        }else{
            arrayt[i] = (n/c)%10;
        }
        c /= 10;
    }

    c = 10000;

    for(int i = 0; i < 4; i++){
        num += arrayt[i]*c;
        c /= 10;
    }

    num /= 10;

    return num;
}

int calculaDigito(int n){

    int arrayt[5] = {0};
    int c = 10000;
    int c2 = 2;
    int soma = 0;
    int digito;

    for(int i = 0; i < 5; i++){
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
