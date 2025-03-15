/**
*
* @author Fernanda Martins
* Ordenação Bubble Sort e Bubble Sort melhorado, Shake Sort, Comb Sort e Quick Sort.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraArray(int A[], int n);
void imprimeArray(int A[], int n);
void bubbleSort(int A[], int n);
void bubbleSortMelhorado(int A[], int n);
void shakeSort(int A[], int n);
void combSort(int A[], int n);
void quickSort(int A[], int n, int inicio, int fim);

int main(){

    int n;
    printf("Insira o número de elementos do array a ser gerado: ");
    scanf("%d", &n);
    int *A = (int*) malloc(n * sizeof(int));
    printf("Array gerado: ");
    geraArray(A, n);

    printf("\n/ --- Ordenação por Bubble Sort --- /\n");
    printf("Array ordenado: ");
    bubbleSort(A, n);

    printf("\n/ --- Ordenação por Bubble Sort --- /\n");
    printf("Array ordenado: ");
    bubbleSortMelhorado(A, n);

    printf("\n/ --- Ordenação por Shake Sort --- /\n");
    printf("Array ordenado: ");
    shakeSort(A, n);

    printf("\n/ --- Ordenação por Comb Sort --- /\n");
    printf("Array ordenado: ");
    combSort(A, n);

    printf("\n/ --- Ordenação por Quick Sort --- /\n");
    printf("Array ordenado: ");
    quickSort(A, n, 0, n-1);

    free(A);
    return 0;
}

void geraArray(int A[], int n){

    srand(time(NULL));
    for(int i = 0; i < n; i++){
        A[i] = rand() % 100;
    }

    imprimeArray(A, n);

}

void imprimeArray(int A[], int n){

    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }

    printf("\n");

}

void bubbleSort(int A[], int n){

    int aux;

    for(int j = n-1; j >= 1; j--){
        for(int i = 0; i < j; i++){
            if(A[i] > A[i+1]){
                aux = A[i];
                A[i] = A[i+1];
                A[i+1] = aux;
            }
        }
    }

    imprimeArray(A, n);

}

void bubbleSortMelhorado(int A[], int n){

    int memoria;
    int troca;

    troca = 1;

    for(int j = n-1; (j >= 1) && (troca == 1); j--){
        troca = 0;
        for(int i = 0; i < j; i++){
            if(A[i] > A[i+1]){
                memoria = A[i];
                A[i] = A[i+1];
                A[i+1] = memoria;
                troca = 1;
            }
        }
    }

    imprimeArray(A, n);

}

void shakeSort(int A[], int n){

    int L = 0;
    int R = n-1;
    int k = n-1;
    int j;
    int x;

    do{
        for(j = L; j < R; j++){
            if(A[j] > A[j+1]){
                x = A[j];
                A[j] = A[j+1];
                A[j+1] = x;
                k = j;
            }
        }

        R = k;

        for(j = R; j > L; j--){
            if(A[j-1] > A[j]){
                x = A[j-1];
                A[j-1] = A[j];
                A[j] = x;
                k = j;
            }
        }

        L = k;

    }
    while(L < R);

    imprimeArray(A, n);

}

void combSort(int A[], int n){

    double h = n;
    int x;
    int i;
    int troca;

    do{
        h = h/1.3;
        if((h == 9) || (h==10)){
            h = 11;
        }

        troca = 0;

        for(i = 0; i < (n-h); i++){
            if(A[(int)i] > A[(int)(i+h)]){
                x = A[i];
                A[(int)i] = A[(int)(i+h)];
                A[(int)(i+h)] = x;
                troca = 1;
            }
        }

    }while((troca == 1)||(h >= 1));

    imprimeArray(A, n);

}

void quickSort(int A[], int n, int inicio, int fim){

    int pivo;
    int aux;
    int i;
    int j;
    int meio;

    i = inicio;
    j = fim;
    meio = (int) ((i + j) / 2);
    pivo = A[meio];

    do{
        while(A[i] < pivo){
            i = i + 1;
        }
        while(A[j] > pivo){
            j = j - 1;
        }

        if(i <= j){
            aux = A[i];
            A[i] = A[j];
            A[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    }while(j > i);

    if(inicio < j){
        quickSort(A, n, inicio, j);
    }if(i < fim){
        quickSort(A, n, i, fim);
    }

    imprimeArray(A, n);

}