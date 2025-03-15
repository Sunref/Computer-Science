#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int somaDivisores();
int lePositivo();

int main(){

    int somadiv;
    int array[5] = {0};

    for(int i = 0; i < 5; i++){
        printf("n[%d]: ",i);
        array[i] = lePositivo();
    }

    for(int i = 0; i < 5; i++){
        somadiv = somaDivisores(array[i]);
        printf("\nSoma dos divisores de %d: %d",array[i], somadiv);
    }
    return 0;
}

int lePositivo(){

    int num;
    do{
        scanf("%d", &num);
        if (num <= 0){
            printf("\nEntre com um valor positivo:");
        }
    }while (num <= 0);
    return num; 
}

int somaDivisores(int n){

    int somad = 0;

    for(int i = 1; i < n; i++){
        if(n % i == 0){
            somad += i;
        }
    }
    return somad;
}
