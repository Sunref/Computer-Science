#include <stdio.h>
#include <stdlib.h>

int lePositivo();
int somatorio();

int main(){

    int n1;
    int somat;
    int array[5];

    for(int i = 0; i < 5; i++){
        printf("n[%d]: ", i);
        array[i] = lePositivo();
    }

    for(int i = 0; i < 5; i++){
        somat = somatorio(array[i]);
        printf("\nSomatorio de 1 a %d: %d",array[i], somat);

    }
    return 0;
}

int lePositivo(){

    int num;
    do{
        scanf("%d", &num);
        if(num <= 0){
            printf("\nEntre com um valor positivo:");
        }
    }while(num <= 0);
    return num;
}

int somatorio(int n){

    int soma = 0;

    for(int i = 1; i <= n; i++){
        soma += i;
    }
    return soma;
}