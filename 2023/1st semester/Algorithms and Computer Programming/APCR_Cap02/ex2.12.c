#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    int idadeH1;
    int idadeH2;
    int idadeM1;
    int idadeM2;
    int maiorH;
    int menorH;
    int maiorM;
    int menorM;
    int somaHVmn;
    int somaHNmv;

    printf("Idade Homem 1: ");
    scanf("%d", &idadeH1);
    printf("Idade Homem 2: ");
    scanf("%d", &idadeH2);
    printf("Idade Mulher 1: ");
    scanf("%d", &idadeM1);
    printf("Idade Mulher 2: ");
    scanf("%d", &idadeM2);

    if(idadeH1 > idadeH2){
        maiorH = idadeH1;
        menorH = idadeH2;
    }else{
        maiorH = idadeH2;
        menorH = idadeH1;
    }

    if(idadeM1 > idadeM2){
        maiorM = idadeM1;
        menorM = idadeM2;
    }else{
        maiorM = idadeM2;
        menorM = idadeM1;
    }

    somaHVmn = maiorH + menorM; 
    somaHNmv = menorH * maiorM;

    printf("\nIdade homem mais velho + idade mulher mais nova: %d",somaHVmn);
    printf("\nIdade homem mais novo * idade mulher mais velha: %d",somaHNmv);
    return 0;
}