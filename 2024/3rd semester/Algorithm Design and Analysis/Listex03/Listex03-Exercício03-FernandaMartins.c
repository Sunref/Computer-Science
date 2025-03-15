/**
*
* @author FernandaDesktop
* MergeSort Recursivo sem Sentinela
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraArray(int N, int array[]);
void imprimeDesord(int N, int array[]);
void mergeSort(int N, int array[], int inicio, int fim);
void intercalaSemSentinela(int N, int array[], int inicio, int meio, int fim);
void imprimeArray(int N, int array[]);

int main(){

    int N;

    printf("Entre com o tamanho do array de inteiros: ");
    scanf("%d", &N);
    int *array = (int*) malloc(N * sizeof(int));

    geraArray(N, array);

    printf("Ordenacao\n");

    imprimeDesord(N, array);
    mergeSort(N, array, 0, N-1);
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

void mergeSort(int N, int array[], int inicio, int fim){

    int meio;
    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergeSort(N, array, inicio, meio);
        mergeSort(N, array,  (meio+1), fim);

        intercalaSemSentinela(N, array, inicio, meio, fim);

        printf("Array Ord.    [] = ");
            for(int i = 0; i < N; i++){
                printf("%d ", array[i]);
            }
        printf("\n");
    
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