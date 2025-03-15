/**
*
* @author FernandaDesktop
* MergeSort Iterativo sem Sentinela
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraArray(int N, int array[]);
void imprimeDesord(int N, int array[]);
void mergeSortIterativo(int N, int array[]);
void intercalaSemSentinela(int N, int array[], int inicio, int meio, int fim);
void imprimeArray(int N, int array[]);


int main(){

    int N;

    printf("Entre com o pos do array de inteiros: ");
    scanf("%d", &N);
    int *array = (int*) malloc(N * sizeof(int));

    geraArray(N, array);

    printf("Ordenacao\n");

    imprimeDesord(N, array);
    mergeSortIterativo(N, array);
    imprimeArray(N, array);

    return 0;

}

void geraArray(int N, int array[]){

    srand(time(NULL));
    for(int i = 0; i < N; i++){
        array[i] = rand() % 100;
    }

}

void imprimeDesord(int N, int array[]){

    printf("Array Desord. [] = ");

    for(int i = 0; i < N; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

}

void mergeSortIterativo(int N, int array[]){

    for (int pos = 1; pos <= N - 1; pos = 2 * pos){
        for (int inicio = 0; inicio < N - 1; inicio += 2 * pos){
            int meio = inicio + pos - 1;
            int fim = (inicio + 2 * pos - 1 < N - 1) ? inicio + 2 * pos - 1 : N - 1;
            // condicao ? verdade : falso
            /* se a condicao (inicio+2*pos-1) for verdadeira (menor que N - 1), inicio+2*pos-1
            senao (falso, maior que N-1), N-1*/

            intercalaSemSentinela(N, array, inicio, meio, fim);

            printf("Array Ord.    [] = ");
            for(int i = 0; i < N; i++){
                printf("%d ", array[i]);
            }
            printf("\n");
        }
    }

}

void intercalaSemSentinela(int N, int array[], int inicio, int meio, int fim){

    int i;
    int j;
    int *arrayB = (int*) malloc((fim+1) * sizeof(int));

    for(i = inicio; i <= meio; i++){
        arrayB[i] = array[i];
    }

    for(j = (meio+1); j <= fim; j++){
        arrayB[fim + meio + 1 - j] = array[j];
    }

    i = inicio;
    j = fim;

    for(int k = inicio; k <= fim; k++){
        if(arrayB[i] <= arrayB[j]){
            array[k] = arrayB[i];
            i++;
        }else{
            array[k] = arrayB[j];
            j--;
        }
    }

    free(arrayB);

}

void imprimeArray(int N, int array[]){

    printf("Array Ord.    [] = ");
    for(int i = 0; i < N; i++){ 
        printf("%d ", array[i]);
    }

}