/**
*
* @author FernandaDesktop
* Busca Binária
*
*/

#include <stdio.h>
#include <stdlib.h>

void ordenaArrayInsertionSort(int array[], int N);
void imprimeArray(int N, int array[]);
int buscaBinaria(int array[], int inicio, int fim, int x);

int main(){

    int N;
    int x;

    printf("Entre com o numero inteiro do Array: ");
    scanf("%d", &N);
    int *array = (int*)malloc(N * sizeof(int));

    for(int i = 0; i < N; i++){
        printf("Digite o valor para a posicao %d do array: ", i+1);
        scanf("%d", &array[i]);
    }

    ordenaArrayInsertionSort(array, N);
    imprimeArray(N, array);

    printf("\nEntre com o valor inteiro a ser procurado: ");
    scanf("%d", &x);

    int resultado = buscaBinaria(array, 0, N - 1, x);

    if(resultado != -1){
        printf("O valor %d foi encontrado na posicao %d do Array!", x, resultado);
    }else{
        printf("O valor %d nao foi encontrado no Array!", x);
    }

    return 0;

}

void ordenaArrayInsertionSort(int array[], int N){

    int chave; 
    for(int j = 1; j < N; j++){
        chave = array[j];
        int i = j -1;

        while ((i >= 0) & (array[i]> chave)){
            array [i + 1] = array [i];
            i--;
        }
        array [ i + 1] = chave;
    }

}

void imprimeArray(int N, int array[]){

    printf("Array Gerado Ordenado = ");
    for(int i = 0; i < N; i++){ 
        printf("%d ", array[i]);
    }

}

int buscaBinaria(int array[], int inicio, int fim, int x){

    if(inicio > fim){
        return -1; 
    }

    int meio = (inicio + fim) / 2;

    if(array[meio] == x){
        return meio; 
    }

    if(x <= array[meio]){
        return buscaBinaria(array, inicio, (meio-1), x);
    }

    return buscaBinaria(array, (meio+1), fim, x);

}