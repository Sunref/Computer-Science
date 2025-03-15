/**
*
* @author Fernanda Martins
* Ordenação Shell Sort - passo a passo
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void geraArray(int A[], int n);
void imprimeArray(int A[], int n, bool ordenou);
void ordenaShellSort(int Vet[], int Inc, int SegCorrente, int n);
void shellSort(int A[], int n);

int main(){

    int n;

    printf("Entre com o tamanho do Array de Inteiros: "); 
    scanf("%d", &n);
    int *A = (int*) malloc(n *sizeof(int));
    geraArray(A, n);

    printf("\n ---------- Métodos de Ordenação por Inserção ---------- \n");
    printf("\n3) c- Shell Sort");
    shellSort(A, n);
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


void ordenaShellSort(int A[], int Inc, int SegCorrente, int n){

    int i;
    int j;
    int x;
    int k;

    for(i = (SegCorrente + Inc); i < n; i += Inc){ 
        k = SegCorrente;
        j = i - Inc;
        x = A[i];

        imprimeArray(A, n , false);
        printf("- %d\n", x);

        while((j >= SegCorrente) && (k == SegCorrente)){
            if(x < A[j]){
                A[j + Inc] = A[j];
                j = j - Inc;
            }else{
                k = j + Inc;
            }
        }
        A[k] = x;
    }

}

void shellSort(int A[], int n){

    int Inc = n / 2;

    while (Inc > 0){
        for(int SegCorrente = 0; SegCorrente < Inc; SegCorrente++){
            ordenaShellSort(A, Inc, SegCorrente, n);
        }
        Inc /= 2;
    }

    imprimeArray(A, n, false);
    imprimeArray(A, n, true);

}