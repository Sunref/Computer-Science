/**
*
* @author FernandaDesktop
* Busca Linear
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraArray(int N, int array[]);
void imprimeArray(int N, int array[]); //funcoes utilizadas
int *buscaArray(int N, int array[], int v);
void imprimeArrayBusca(int v, int *index, int array[]);

int main(){

    int N;
    int v; //variavel de valor de busca

    printf("Entre com o tamanho do Array de Inteiros: ");
    scanf("%d", &N);
    int *array = (int*) malloc(N * sizeof(int));

    geraArray(N, array);
    imprimeArray(N, array);

    printf("\nEntre com o valor inteiro a ser procurado: ");
    scanf("%d", &v);

    int *resultadoBusca = buscaArray(N, array, v); //variavel que chama a funcao buscaArray, aplicacao mais facil para a linha abaixo
    imprimeArrayBusca(v, resultadoBusca, array);

    return 0;

}

void geraArray(int N, int array[]){

    srand(time(NULL)); //preenchendo array com numeroas aleatorios de 1-100
    for(int i = 0; i < N; i++){
        array[i] = rand() % 100;
    }

}

void imprimeArray(int N, int array[]){ //imprimindo array gerado

    printf("Array Gerado: ");
    for(int i = 0; i < N; i++){ 
        printf(" %d ", array[i]);
    }

}

int *buscaArray(int N, int array[], int v){ //buscando valor v fornecido pelo usuario no array gerado anteriormente

    for(int i = 0; i < N; i++){
        if(array[i] == v){
            return &array[i]; //salva onde o array foi encontrado
        }
    }

    return (int*)NULL;

}

void imprimeArrayBusca(int v, int *index, int array[]){ //imprime os resultados da busca, index se refere ao resultadoBusca, criado anteriormente

    if(index == NULL){
        printf("Valor nao encontrado no Array!");
    }else{
        printf("O valor %d foi encontrado na posicao %d", v, (long)(index - array)); //(long)(index - array) retorna a posicao em que o valor foi encontrado, nao o valor guardado
    }

}