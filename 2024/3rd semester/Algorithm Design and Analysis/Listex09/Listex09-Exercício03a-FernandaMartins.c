/**
*
* @author Fernanda Martins
* Ordenação Insertion Sort - passo a passo
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void geraArray(int A[], int n);
void imprimeArray(int A[], int n, bool ordenou);
void insertionSort(int A[], int n);

int main(){

    int n;

    printf("Entre com o tamanho do Array de Inteiros: "); 
    scanf("%d", &n);
    int *A = (int*) malloc(n *sizeof(int));
    geraArray(A, n);

    printf("\n ---------- Métodos de Ordenação por Inserção ---------- \n");
    printf("\n3) a- Insertion Sort");
    insertionSort(A, n);
    printf("\n");

    free(A);
    return 0;

}

void geraArray(int A[], int n){

    for(int i = 0; i < n; i++){
        printf("Digite o valor para a posicao %d do Array: ", i+1);
        scanf("%d", &A[i]);
    }

}

void imprimeArray(int A[], int n, bool ordenou){


    if(ordenou){
        printf("\nArray Ord.    [] = ");
    }else{
        printf("\nArray Desord. [] = ");
    }

    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

}

void insertionSort(int A[], int n){

    for(int j = 1; j < n; j++){
        int chave = A[j];
        int i = j - 1;

        imprimeArray(A, n, 0);

        printf("- %d", chave);

        while (i >= 0 && A[i] > chave){
            A[i +1] = A[i];
            i -= 1;
        }

        A[i + 1] = chave;

    }

    imprimeArray(A, n, 1);

}

