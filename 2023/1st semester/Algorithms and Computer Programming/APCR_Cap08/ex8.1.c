#include <stdio.h>
#include <stdlib.h>

void somatorioMedia(float array[], int n, float *somatorio, float *media);

int main(){

    float array[10];
    int n = 10;
    float somatorio;
    float media;

    for(int i = 0; i < 10; i++){
        printf("[%d]: ", i);
        scanf("%f", &array[i]);
    }

    somatorioMedia(array, n, &somatorio, &media);
    return 0;
}

void somatorioMedia(float array[], int n, float *somatorio, float *media){

    for(int i = 0; i < 10; i++){
        *somatorio += array[i];
    }

    *media = *somatorio / 10;

    printf("\nSomatorio: %.2f", *somatorio);
    printf("\nMedia: %.2f", *media);
}