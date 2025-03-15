/**
*
* @author FernandaDesktop
* Máximo Elemento de um Array
*
*/

#include <stdio.h>
#include <stdlib.h>

int encontrarMaior(int array[], int N, int *op); // Funcao para encontrar o maior número

int main() {

    int N; // tamanho do array fornecido pelo usuario
    int op = 0; // contador de instucoes

    printf("Entre com o tamanho do array de inteiros: "); //tamanho do array sendo solicitado
    scanf("%d", &N);
    printf("\n");

    int *array = (int*)malloc(N * sizeof(int)); // Alocacao dinâmica para o array
    // int *array declara um ponteiro chamado array;
    // maloc e uma funcao que aloca uma quantia especifica na mamoria;
    // sizeof retorna o tamanho em bytes, que e multiplicado por N, valor fornecido pelo usuario, aloca este valor ao array;
    // int* converte o malloc (que retorna void*) a retornar int;

    for(int i = 0; i < N; i++){
        printf("Digite o valor para a posicao %d do array: ", i+1); // i+1 para dar posicao de 1-10 (ja que array comeca sempre em 0);
        scanf("%d", &array[i]);
        printf("\n");
    }

    int maior = encontrarMaior(array, N, &op); // chama a funcao

    printf("O maior elemento do Array eh: %d (Num. Operacoes = %d)", maior, op);

    return 0;

}

int encontrarMaior(int array[], int N, int *op){ // Funcao para encontrar o maior número e o contador de instrucoes

    int maior = 0; //variavel para salvar o maior valor, iniciada em 0
    int temp; //variavel temporaria para troca de valores
    int c = 0; //contador

    for (int i = 0; i < N; i++){ //ordenacao do array
        for (int j = 0; j < N; j++){
            if (array[j] > array[j + 1] && array[j + 1] < N){
            temp = array[j + 1];
            array[j + 1] = array[j];
            array[j] = temp;
            c++;
            }
        }

        if(c > 0){ //calcula num. operacoes
            *op += 1;
            c = 0;
        }
    }

    for (int i = 0; i < N; i++){ //acha maior valor
        if (array[i] > maior) {
            maior = array[i];
        }
    }

    return maior;

}