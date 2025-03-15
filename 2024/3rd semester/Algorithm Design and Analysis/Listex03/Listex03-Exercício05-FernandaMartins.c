/**
*
* @author FernandaDesktop
* Busca Binária com o Paradigma de Divisão e Conquista
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraArray(int N, int array[]);
void mergeSort(int N, int array[], int inicio, int fim);
void intercalaSemSentinela(int N, int array[], int inicio, int meio, int fim);
void imprimeArray(int N, int array[]);
int buscaBinariaRecursiva(int array[], int inicio, int fim, int x);

int main(){

    int N;
    int x;

    printf("Entre com o tamanho do array de inteiros: ");
    scanf("%d", &N);
    int *array = (int*) malloc(N * sizeof(int));

    geraArray(N, array);
    mergeSort(N, array, 0, N-1);
    imprimeArray(N, array);

    printf("\nEntre com o valor inteiro a ser procurado: ");
    scanf("%d", &x);

    int resultado = buscaBinariaRecursiva(array, 0, N - 1, x);

    if(resultado != -1){
        printf("O valor %d foi encontrado na posicao %d do Array!", x, resultado);
    }else{
        printf("O valor %d nao foi encontrado no Array!", x);
    }

    return 0;

}

void geraArray(int N, int array[]){

    srand(time(NULL));
    for(int i = 0; i < N; i++){
        array[i] = rand() % 100;
    }

}

void mergeSort(int N, int array[], int inicio, int fim){

    int meio;
    if(inicio < fim){
        meio = (inicio + fim)/2;
        mergeSort(N, array, inicio, meio);
        mergeSort(N, array,  (meio+1), fim);

        intercalaSemSentinela(N, array, inicio, meio, fim);

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

    printf("Array Gerado Ordenado = ");
    for(int i = 0; i < N; i++){ 
        printf("%d ", array[i]);
    }

}

/*buscaBinariaRecursiva e uma funcao que busca por um numero previamente fornecido, 
    dividindo o array ate o encontra-lo*/
int buscaBinariaRecursiva(int array[], int inicio, int fim, int x){

    if(inicio > fim){
        return -1; //se o numero nao estiver no array
    }

    int meio = (inicio + fim) / 2;

    if(array[meio] == x){
        return meio; //se o numero for encontrado no meio do array
    }

    if(x <= array[meio]){
        return buscaBinariaRecursiva(array, inicio, (meio-1), x); //divisao do inicio ao meio até encontrar o numero do array
    }

    return buscaBinariaRecursiva(array, (meio+1), fim, x); //divisao do meio ao fim até encontrar o numero do array

}