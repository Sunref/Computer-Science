/**
*
* @author FernandaDesktop
* Maior e Menor Elemento de um Array
*
*/

#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

void maxmin1(int N, int array[], int max, int min);
void maxmin2(int N, int array[], int max, int min); //funcoes para achar maior e menor valores do array, 3 formas diferentes
void maxmin3(int N, int array[], int max, int min);

int main(){

    int N;
    int max;
    int min;

    printf("Entre com o tamanho do Array de Inteiros: "); 
    scanf("%d", &N);

    int *array = (int*)malloc(N * sizeof(int)); //definindo um array com o tamanho fornecido pelo usuario

    for(int i = 0; i < N; i++){
        printf("Digite o valor para a posicao %d do Array: ", i+1); //recebendo os valores do array[N]
        scanf("%d", &array[i]);
    }

    maxmin1(N, array, max, min);
    maxmin2(N, array, max, min); //chamando funcoes
    maxmin3(N, array, max, min);

    return 0;

}

void maxmin1(int N, int array[], int max, int min){ //achando maior e menor valor

    max = array[0];
    min = array[0];
    int numOP1 = 0;

    for(int i = 1; i < N; i++){
        numOP1+=2;
        if(array[i] > max){
            max = array[i];
        }if(array[i] < min){
            min = array[i];
        }
    }

    printf("maxMin1() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", max, min, numOP1);

}

void maxmin2(int N, int array[], int max, int min){ //achando maior e menor valor pela segunda vez, mas de maneira diferente

    max = array[0];
    min = array[0];
    int numOP2 = 0; 

    for(int i = 1; i < N; i++){
        numOP2++;
        if(array[i] > max){
            max = array[i];
        }else if(array[i] < min){
            min = array[i];
        }
    }

    printf("maxMin2() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", max, min, numOP2);

}

void maxmin3(int N, int array[], int max, int min){ //achando maior e menor valor pela terceira vez, novamente de maneira diferente (exemplo de aula)

    int numOP3 = 0;

    if(N%2 != 0){
        array[N+1] = array[N];
        N = N + 1;
    }

    max = array[0];
    min = array[1];

    if(array[0] < array[1]){
        max = array[1];
        min = array[0];
    }

    for(int i = 2; i < N; i += 2){
        numOP3+=3;
        if(array[i] > array[i+1]){
            if(array[i] > max){
                max = array[i];
            }
        }else{
            if(array[i] < min){
                min = array[i];
                numOP3++;
            }if(array[i+1] > max){
                max = array[i+1];
                numOP3++;
            }
        }
    }

    printf("maxMin3() - Maior Elemento: %d - Menor Elemento: %d (Num. de Operacoes: %d)\n", max, min, numOP3);

}