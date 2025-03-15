#include <stdio.h>
#include <stdlib.h>
#include "../Headers/threesum.h"

int qtdOperacoes3SumFB = 0;
int qtdOperacoes3SumMelhorado = 0;

void treeSumForcaBruta(int A[], int n){

    printf("\n ---3SUM - Forca bruta:--- \n");

    int cont = 0;

    for(int i = 0; i < (n-2); i++){
        for(int j = (i+1); j < (n-1); j++){
            for(int k = (j+1); k < n; k++){
                qtdOperacoes3SumFB++;
                if( A[i] + A[j] + A[k] == 0){
                    cont++;
                    printf("\n %d Tripla Encontrada: [%d, %d, %d]", cont, A[i], A[j], A[k]);
                }
            }
        }
    }

    printf("\n Total Triplas Encontradas pela Forca Bruta: %d\n", cont);

}

void treeSumMelhorado(int A[], int n){

    printf("\n ---3SUM - Melhorado:--- \n");

    int cont = 0;

    MergeSortRecursivo(A, 0, (n-1), n);
    ImprimeArray(A, "\n Array Ord.   []", n);

    for(int i = 0; i < (n-2); i++){
        for(int j = (i+1); j < (n-1); j++){

            qtdOperacoes3SumMelhorado++;

            int indice = BuscaBinaria((A[i] + A[j]) * -1, A, (j+1), (n-1));

            if(indice != -1){
                cont++;
                printf("\n %d Tripla Encontrada: [%d, %d, %d]", cont, A[i], A[j], A[indice]);
            }
        }
    }

}

int BuscaBinaria (int x, int A[], int inicio, int fim){

    if(inicio > fim){
        return -1;
    }

    int meio = (inicio + fim)/2;

    if(A[meio] == x){
        return meio;
    }

    if(x <= A[meio]){
        return BuscaBinaria(x, A, inicio, (meio-1));
    }

    return BuscaBinaria(x, A, (meio+1), fim);

}

void MergeSortRecursivo(int A[], int inicio, int fim, int n){

    int meio;
    if(inicio < fim){
        meio = (inicio + fim)/2;
        MergeSortRecursivo(A, inicio, meio, n);
        MergeSortRecursivo(A,  (meio+1), fim, n);
        IntercalaSemSentinela(A, inicio, meio, fim, n);
    }

}

void IntercalaSemSentinela(int A[], int inicio, int meio, int fim, int n){

    int i;
    int j;
    int *arrayB = (int*) malloc((fim+1) * sizeof(int));

    for(i = inicio; i <= meio; i++){
        arrayB[i] = A[i];
    }

    for(j = (meio+1); j <= fim; j++){
        arrayB[fim + meio + 1 - j] = A[j];
    }

    i = inicio;
    j = fim;

    for(int k = inicio; k <= fim; k++){
        qtdOperacoes3SumMelhorado++;
        if(arrayB[i] <= arrayB[j]){
            A[k] = arrayB[i];
            i++;
        }else{
            A[k] = arrayB[j];
            j--;
        }
    }

    free(arrayB);

}

void ImprimeArray(int A[], char Msg[], int n){

    printf("%s = ", Msg);
    for(int i = 0; i < n; i++){
        printf(" %d ", A[i]);
    }

}

void ImprimeQtdOperacoes(){

    printf("\n Quantidade de Operacoes - 3SUM - Forca bruta: %d", qtdOperacoes3SumFB);
    printf("\n Quantidade de Operacoes - 3SUM - Melhorado: %d", qtdOperacoes3SumMelhorado);
    printf("\n");

}