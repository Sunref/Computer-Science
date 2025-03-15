/**
*
* @author FernandaDesktop
* Ordenação
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int numOp = 0; // variavel global para numero das operacoes

void ordenaArray(int array[], int N); // ordenacao do array
void imprimeArray(int array[], int N, bool ordenou); // impressao do array

int main() {

    int N; // variavel do tamanho do array

    printf("Entre com o tamanho do Array de Inteiros: ");
    scanf("%d", &N);

    int *array = (int*) malloc(N * sizeof(int)); // alocando o valor fornecido em um array

    srand (time(NULL));

    for(int i = 0; i < N; i++){
        array[i] = rand() % 100; // preenchendo array com valores aleatorios
    }

    ordenaArray(array, N); // chama funcao que ordena o array

    printf("\nNumero de Ordenacoes para a Operacao: %d", numOp);

    return 0;
}

void imprimeArray(int array[], int N, bool ordenou){ // funcao de impressao

    if(ordenou){
        printf("\nArray Ord.    [] =");
    }else{
        printf("\nArray Desord. [] =");
    }

    for(int i = 0; i < N; i++){
        printf(" %d ", array[i]);
    }

}

void ordenaArray(int array[], int N){ // funcao de ordenacao, nao entendi direito, rever com o professor.

    for(int j = 1; j < N; j++){
        numOp ++;
        int chave = array[j];
        int i = j - 1;

        imprimeArray(array, N, 0);

        printf("- %d", chave);

        while (i >= 0 && array[i] > chave){
            numOp++;
            array[i +1] = array[i];
            i -= 1;
        }

        array[i + 1] = chave;

    }

    imprimeArray(array, N, 1);

}