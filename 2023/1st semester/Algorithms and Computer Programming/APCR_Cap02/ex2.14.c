#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){

    float imc;
    float altura;
    float peso;

    printf("Entre com seu peso em quilogramas: ");
    scanf("%f", &peso);
    printf("Entre com sua altura em metros: ");
    scanf("%f", &altura);   

    imc = peso/(altura*altura);

    if(imc < 17){
        printf("IMC: %.2f", imc);
        printf("\nVoce esta muito abaixo do peso ideal!");
    }else if(imc >= 17 && imc < 18.5){
        printf("IMC: %.2f", imc);
        printf("\nVoce esta abaixo do peso ideal!");
    }else if(imc >= 18.5 && imc < 25){
        printf("IMC: %.2f", imc);
        printf("\nParabens! Voce esta em seu peso normal!");
    }else if(imc >= 25 && imc < 30){
        printf("IMC: %.2f", imc);
        printf("\nAtencao, voce esta acima de seu peso (sobrepeso)!");
    }else if(imc >= 30 && imc < 35){
        printf("IMC: %.2f", imc);
        printf("\nCuidado! Obesidade grau I!");
    }else if(imc >= 35 && imc < 40){
        printf("IMC: %.2f", imc);
        printf("\nCuidado! Obesidade grau II!");
    }else{
        printf("IMC: %.2f", imc);
        printf("\nMuito cuidado!!! Obesidade grau III!");
    }
    return 0;
}