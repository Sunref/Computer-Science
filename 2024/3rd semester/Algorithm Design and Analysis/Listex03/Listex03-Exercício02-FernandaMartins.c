/**
*
* @author FernandaDesktop
* MergeSort Recursivo com Sentinela
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraArray(int N, int array[]);
void imprimeDesord(int N, int array[]);
void mergeSort(int N, int array[], int inicio, int fim);
void intercalaComSentinela(int array[], int inicio, int meio, int fim);
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

        intercalaComSentinela(array, inicio, meio, fim);

        printf("Array Ord.    [] = ");
            for(int i = 0; i < N; i++){
                printf("%d ", array[i]);
            }
        printf("\n");
    }

}

void intercalaComSentinela(int array[], int inicio, int meio, int fim){

    int i;
    int j;
    int n1;
    int n2;

    n1 = meio - inicio + 1;
    n2 = fim - meio;

    int *L = (int*) malloc((n1+1) * sizeof(int));
    int *R = (int*) malloc((n2+1) * sizeof(int));

    for(i = 0; i < n1; i++){
        L[i] = array[inicio+i];
    }

    for(j = 0; j < n2; j++){
        R[j] = array[meio+j+1];
    }

    L[n1] = 300000;
    R[n2] = 300000;

    i = 0;
    j = 0;

    for(int k = inicio; k <= fim; k++){
        if(L[i] <= R[j]){
            array[k] = L[i];
            i++;
        }else{
            array[k] = R[j];
            j++;
        }
    }

    free(L);
    free(R);

}

void imprimeArray(int N, int array[]){

    printf("Array Ord.    [] = ");
    for(int i = 0; i < N; i++){ 
        printf("%d ", array[i]);
    }

}