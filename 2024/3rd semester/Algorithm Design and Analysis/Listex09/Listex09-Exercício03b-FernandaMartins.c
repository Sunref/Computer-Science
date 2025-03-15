/**
*
* @author Fernanda Martins
* Ordenação Binária - passo a passo
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void geraArray(int A[], int n);
void imprimeArray(int A[], int n, bool ordenou);
void ordenacaoBinaria(int A[], int n);

int main(){

    int n;

    printf("Entre com o tamanho do Array de Inteiros: "); 
    scanf("%d", &n);
    int *A = (int*) malloc(n *sizeof(int));
    geraArray(A, n);

    printf("\n ---------- Métodos de Ordenação por Inserção ---------- \n");
    printf("\n3) b- Ordenação Binária");
    ordenacaoBinaria(A, n);
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

void ordenacaoBinaria(int A[], int n){

    int i;
    int j;
    int m;
    int x;
    int L;
    int R;

    for(i = 1; i < n; i++){
        x = A[i];
        L = 0;
        R = i;

        while (L < R){
            m = (L + R)/2;
            if(x >= A[m]){
                L = m+1;
            }else{
                R = m;
            }
            imprimeArray(A, n, false);
            printf("- %d", x);
        }

        for(j = i; j > L; j = j-1){
            A[j] = A[j-1];
        }

        A[R] = x;

    }

    imprimeArray(A, n, true);

}

// void ordenaShellSort(int A[], int Inc, int SegCorrente, int n){

//     int i;
//     int j;
//     int x;
//     int k;

//     for(i = (SegCorrente + Inc); i < n; i += Inc){ 
//         k = SegCorrente;
//         j = i - Inc;
//         x = A[i];
//         while((j >= SegCorrente) && (k == SegCorrente)){
//             if(x < A[j]){
//                 A[j + Inc] = A[j];
//                 j = j - Inc;
//             }else{
//                 k = j + Inc;
//             }
//         }
//         A[k] = x;
//     }

// }

// void shellSort(int A[], int n){

//     int Np = 2;
//     int Inc;
//     for(int i = Np; i >= 0; i--){
//         Inc = Np *= 2;
//         for(int SegCorrente = 0; SegCorrente < Inc; SegCorrente++){
//             ordenaShellSort(A, Inc, SegCorrente, n);
//         }
//     }

//     imprimeArray(A, n);

// }