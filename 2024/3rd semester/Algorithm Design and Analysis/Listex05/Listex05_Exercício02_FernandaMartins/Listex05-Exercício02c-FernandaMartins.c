/**
*
* @author FernandaDesktop
* função Max
*
*/

#include <stdio.h>
#include <stdlib.h>

int max(int array[], int N);
void imprimeArray(int array[], int N);

int main(){

    int N;

    printf("Entre com o numero inteiro do Array: ");
    scanf("%d", &N);
    int *array = (int*)malloc(N * sizeof(int));

    for(int i = 0; i < N; i++){
        printf("Digite o valor para a posicao %d do array: ", i+1);
        scanf("%d", &array[i]);
    }

    imprimeArray(array, N);

    printf("\nO maior valor no array foi: %d", max(array, N));

    return 0;

}

void imprimeArray(int array[], int N){

    printf("Array gerado = ");
    for(int i = 0; i < N; i++){
        printf("%d ", array[i]);
    }

}

int max(int array[], int N){

    int resto;

    if(N == 1){
        return array[0];
    }else{
        resto = max(array + 1, N - 1);
        return (array[0] > resto) ? array[0] : resto;
    }

}