/**
*
* @author Fernanda Martins
* Ordenação Select Sort, Heap Sort, Merge Sort e Radix Sort.
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraArray(int A[], int n);
void imprimeArray(int A[], int n);
void selectSort(int A[], int n);
void heapSort(int A[], int n);
void ordenaHeap(int A[], int n, int L, int R);
void mergeSort(int A[], int n);
void radixSort(int A[], int n);

int main(){

    int n;

    printf("Entre com o tamanho do Array de Inteiros: "); 
    scanf("%d", &n);
    int *A = (int*) malloc(n *sizeof(int));
    printf("Array gerado: ");
    geraArray(A, n);

    printf("\n/ --- Ordenação por Select Sort --- /\n");
    printf("Array ordenado: ");
    selectSort(A, n);

    printf("\n/ --- Ordenação por Heap Sort --- /\n");
    printf("Array ordenado: ");
    heapSort(A, n);

    printf("\n/ --- Ordenação por Merge Sort --- /\n");
    printf("Array ordenado: ");
    mergeSort(A, n);

    printf("\n/ --- Ordenação por Radix Sort --- /\n");
    printf("Array ordenado: ");
    radixSort(A, n);

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

void selectSort(int A[], int n){

    int i;
    int j;
    int k;
    int x;
    int comp;

    for(i = 0; i < n; i++){

        comp = 0;
        k = i;
        x = A[i];

        for(j = i+1; j < n; j++){
            if(A[j] < x){
                k = j;
                x = A[k];
                comp = 1;
            }
        }

        if(comp == 1){
            A[k] = A[i];
            A[i] = x;
        }

    }

    imprimeArray(A, n);

}

void heapSort(int A[], int n){

    int L;
    int R;
    int x;

    L = n/2+1;
    R = n-1;

    while(L > 0){
        L--;
        ordenaHeap(A, n, L, R);
    }while(R > 0){
        x = A[0];
        A[0] = A[R];
        A[R] = x;
        R--;
        ordenaHeap(A, n, L, R);
    }

    imprimeArray(A, n);

}

void ordenaHeap(int A[], int n, int L, int R){

    int i;
    int j;
    int x;

    i = L;
    j = 2*L;
    x = A[L];

    if((j < R) && (A[j] < A[j+1])){
        j++;
    }while((j <= R) && (x < A[j])){
        A[i] = A[j];
        i = j;
        j = 2*j;
        if((j < R) && (A[j] < A[j+1])){
            j++;
        }
    }

    A[i] = x;

}

void mergeSort(int A[], int n){

    int tam = 1;
    int L1, R1;
    int L2, R2;
    int i, j, k;
    int AuxFun[n];

    while(tam < n){

        L1 = 0;
        k = 0;

        while(L1 + tam < n){

            L2 = L1 + tam;
            R1 = L2 - 1;

            if((L2 + tam - 1) < n){
                R2 = L2 + tam - 1;
            }else{
                R2 = n - 1;
            }

            for(i = L1, j = L2; (i <= R1) && (j <= R2); k++){
                if(A[i] <= A[j]){
                    AuxFun[k] = A[i];
                    i++;
                }else{
                    AuxFun[k] = A[j];
                    j++;
                }
            }

            while(i <= R1){
                AuxFun[k] = A[i];
                i++;
                k++;
            }

            while(j <= R2){
                AuxFun[k] = A[j];
                j++;
                k++;
            }

            L1 = R2 + 1;
        }

        for(i = L1; k < n; i++){
            AuxFun[k] = A[i];
            k++;
        }

        for(i = 0; i < n; i++){ 
            A[i] = AuxFun[i];
        }

        tam = tam * 2;

    }

    imprimeArray(A, n);

}

void radixSort(int A[], int n){

    int i;
    int b[n];
    int m = 0;
    int exp = 1;

    for(i = 0; i < n; i++){
        if(A[i]>m){
            m = A[i];
        }
    }

    while(m/exp > 0){
    
        int bucket[10] = {0};

        for(i = 0; i < n; i++){
            bucket[A[i]/exp%10]++;
        }
        for(i = 1; i < 10; i++){
            bucket[i] += bucket[i-1];
        }
        for(i = n-1; i >= 0; i--){
            b[--bucket[A[i]/exp%10]] = A[i];
        }
        for(i = 0 ; i < n; i++){
            A[i] = b[i];
        }

        exp *= 10;
    }

    imprimeArray(A, n);

}